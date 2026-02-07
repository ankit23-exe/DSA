class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int count =0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(st.empty()){
                st.push(c);
            }else{
                if(c == st.top()){
                    st.push(c);
                }else if(c=='b'&& st.top()=='a'){
                    st.push(c);
                }else if(c=='a' && st.top()=='b'){
                    count++;
                    st.pop();
                   
                }
            }
        }

        return count;
    }
};