class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else if (s[i] == ')' && !stack.empty() && s[stack.top()] == '(') {
                stack.pop();
            } else {
                stack.push(i);
            }
        }
        int ans = 0;
        int ub = s.size();
        while (!stack.empty()) {
            int lb = stack.top();
            ans = max(ans, ub - lb - 1);
            ub = lb;
            stack.pop();
        }
        int lb = -1;
        ans = max(ans, ub - lb - 1);

        return ans;
    }
};