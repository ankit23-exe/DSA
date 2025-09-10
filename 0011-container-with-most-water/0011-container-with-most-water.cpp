class Solution {
public:
    int maxArea(vector<int>& height) {

        int ans = 0;
        int n = height.size();

        int i = 0, j = n - 1;
        while (i < j) {
            int hei = min(height[i], height[j]);
            int diff = j - i;
            ans = max(ans, hei * diff);

            // move the pointer with smaller height
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return ans;
    }
};