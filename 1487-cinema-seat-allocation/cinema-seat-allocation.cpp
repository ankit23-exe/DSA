class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 0;
        unordered_map<int,unordered_set<int> > mp;
        for(auto &p:reservedSeats){
            mp[p[0]].insert(p[1]);
        }

        ans +=(n-mp.size())*2; //sara empty row sa humko 2 max team milega

        auto isValid = [&](auto p ,int seat){ //isvalid function
            if(p.second.count(seat)) return false;
            return true;
        };

        for(auto &p:mp){
            bool groupA = isValid(p,2) && isValid(p,3) && isValid(p,4) && isValid(p,5)  ;
            bool groupB =  isValid(p,4) && isValid(p,5) && isValid(p,6) && isValid(p,7)  ;
            bool groupC =  isValid(p,6) && isValid(p,7) && isValid(p,8) && isValid(p,9) ;

            if(groupA && groupC){
                ans+=2;
            }else if(groupA || groupB || groupC){
                ans+=1;
            }

        }
        return ans;

    }
};