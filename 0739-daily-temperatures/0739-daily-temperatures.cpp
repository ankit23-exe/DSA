class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        vector<int> v(temp.size(),0);

        for(int i=0;i<temp.size();i++){
            while(!st.empty() && temp[i]>temp[st.top()]){
                v[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return v;
        
    }
};