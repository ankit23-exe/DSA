class Solution {
public:
    vector<int> getNSL(vector<int>& heights, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                result[i] = -1;
            } else {
                while (!st.empty() && heights[st.top()] > heights[i]) {
                    st.pop();
                }
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return result;
    }

    vector<int> getNSR(vector<int>& heights, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                result[i] = n;
            } else {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return result;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        // height calculate krna hai
        // row wise travel and add in 1 array
        int r = matrix.size();
        int c = matrix[0].size();

        vector<int> height(c);
        int maxarea = 0;

        // taking first row
        for (int j = 0; j < c; j++) {
            height[j] = matrix[0][j] == '1' ? 1 : 0;
        }
        vector<int> nsl = getNSL(height, c);
        vector<int> nsr = getNSR(height, c);
        // checking maximum height for row 1
        for (int j = 0; j < c; j++) {
            int area = height[j] * (nsr[j] - nsl[j] - 1);
            maxarea = max(area, maxarea);
        }
        // now baki ka area ko
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < c; j++) {
                height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1;
            }
            vector<int> nsl = getNSL(height, c);
            vector<int> nsr = getNSR(height, c);
            for (int j = 0; j < c; j++) {
                int area = height[j] * (nsr[j] - nsl[j] - 1);
                maxarea = max(area, maxarea);
            }
        }

        return maxarea;
    }
};