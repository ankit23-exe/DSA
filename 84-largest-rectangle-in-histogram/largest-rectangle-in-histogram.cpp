class Solution {
public:
    vector<int>getNSL(vector<int>& heights,int n){
        vector<int> result(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                result[i]=-1;
            }else{
                while(!st.empty()&& heights[st.top()]>heights[i]){
                    st.pop();
                }
                result[i]=st.empty()?-1:st.top();

            }
            st.push(i);
        }
        return result;
    }

vector<int>getNSR(vector<int>& heights,int n){
        vector<int> result(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                result[i]=n;
            }else{
                while(!st.empty()&& heights[st.top()]>=heights[i]){
                    st.pop();
                }
                result[i]=st.empty()?n:st.top();

            }
            st.push(i);
        }
        return result;
    }


    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nsl=getNSL(heights,n);
        vector<int> nsr=getNSR(heights,n);
        int ans=0;

        for(int i=0;i<n;i++){
            int csum=heights[i]*(nsr[i]-nsl[i]-1);
            ans=max(csum,ans);
        }
        return ans;

        
    }
};