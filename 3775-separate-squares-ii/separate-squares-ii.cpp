class Solution {
public:
    struct Event {
        int y;
        int type;   // +1 = add, -1 = remove
        int x1, x2;

        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    // Compute union length of intervals on x-axis
    double getUnionWidth(vector<pair<int,int>>& intervals) {
        if (intervals.empty()) return 0.0;

        sort(intervals.begin(), intervals.end());
        long long width = 0;

        int currL = intervals[0].first;
        int currR = intervals[0].second;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first > currR) {
                width += currR - currL;
                currL = intervals[i].first;
                currR = intervals[i].second;
            } else {
                currR = max(currR, intervals[i].second);
            }
        }
        width += currR - currL;
        return (double)width;
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;

        // Build sweep events
        for (auto& s : squares) {
            int x = s[0];
            int y = s[1];
            int l = s[2];

            events.push_back({y, +1, x, x + l});
            events.push_back({y + l, -1, x, x + l});
        }

        sort(events.begin(), events.end());

        vector<pair<int,int>> activeX;
        vector<tuple<int,int,double>> strips;

        long long totalArea = 0;
        int prevY = events[0].y;

        for (auto& e : events) {
            if (e.y > prevY) {
                double width = getUnionWidth(activeX);
                int height = e.y - prevY;

                if (width > 0) {
                    strips.emplace_back(prevY, height, width);
                    totalArea += (long long)(width * height);
                }
            }

            if (e.type == +1) {
                activeX.emplace_back(e.x1, e.x2);
            } else {
                for (auto it = activeX.begin(); it != activeX.end(); it++) {
                    if (it->first == e.x1 && it->second == e.x2) {
                        activeX.erase(it);
                        break;
                    }
                }
            }

            prevY = e.y;
        }

        double target = totalArea / 2.0;
        double currArea = 0;

        // Find split y
        for (auto& strip : strips) {
            int y, h;
            double w;
            tie(y, h, w) = strip;

            double stripArea = h * w;

            if (currArea + stripArea >= target) {
                double need = target - currArea;
                return y + need / w;
            }
            currArea += stripArea;
        }

        return 0.0; // fallback
    }
};
