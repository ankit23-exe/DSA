class Solution {
public:

    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                result[i] = -1;
            } else {
                while (!st.empty() && arr[st.top()] > arr[i]) {
                    st.pop();
                }
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return result;
    }
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                result[i] = n;
            } else {
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return result;
    }

    long long maximumSumOfHeights(vector<int>& Heights) {

        long long n=Heights.size();
        long long ans=0;
        //we got the idex
        vector<int> lidx=getNSL(Heights,n);
        vector<int> ridx=getNSR(Heights,n);

        //abb humko
        //left prefix and right prefix chahiya using lidx, and ridx
        vector<long long> lprefix(n);
        vector<long long> rprefix(n);
        lprefix[0]=Heights[0];
        for(int i=1;i<n;i++){    //we calculate the lprefix,
            long long v= 1LL *(i-lidx[i])*Heights[i];
            if(lidx[i]!=-1){
                v+=lprefix[lidx[i]];
            }
            lprefix[i]=v;
        }


        //abb rprefix calculate krenga
        rprefix[n-1]=Heights[n-1];
        for(int i=n-2;i>=0;i--){
            long long v= 1LL *(ridx[i]-i)*Heights[i];
            if(ridx[i]!=n){
                v+=rprefix[ridx[i]];
            }
            rprefix[i]=v;
        }

        //abb final solution calculate krenga
        //
        for(int i=0;i<n;i++){
            long long csum=lprefix[i]+rprefix[i]-Heights[i];
            ans=max(ans,csum);
        }


        return ans;


    }
};