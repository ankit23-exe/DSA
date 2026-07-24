class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2) return false;
        vector<int>vec1(26);
        vector<int>vec2(26);
        for(int i=0;i<n1;i++){
            vec1[s1[i]-'a']++;
        }
        for(int i=0;i<n1;i++){
            vec2[s2[i]-'a']++;
        }
        if(vec1==vec2) return true;
        for(int i=n1;i<n2;i++){
            vec2[s2[i]-'a']++;
            vec2[s2[i-n1]-'a']--;
            if(vec1==vec2) return true;
        }
        return false;



    }
};