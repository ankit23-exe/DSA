class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        stack<long long> st;

        for(int i=0;i<n;i++){
            if(st.empty() || st.top()!=nums[i]){
                st.push(nums[i]);
            }else if(st.top()==nums[i]){
                st.pop();
                long long t = 2*nums[i];
                while(!st.empty() && st.top()==t){
                    st.pop();
                    t = 2*t;
                }
                st.push(t);
            }
        }
        vector<long long> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        int i =0;
        int j = ans.size()-1;
        while(i<=j){
            swap(ans[i],ans[j]);
            i++;j--;
        }

        return ans;
    }
};