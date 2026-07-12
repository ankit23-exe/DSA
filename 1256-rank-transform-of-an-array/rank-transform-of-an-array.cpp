class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return {};
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp; //num->rank
        int rank =1;
        mp[temp[0]]=1;
        for(int i=1;i<temp.size();i++){
            if(temp[i]==temp[i-1]){
                mp[temp[i]]=rank;
            }else{
                mp[temp[i]]= ++rank;
            }
        }

        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};