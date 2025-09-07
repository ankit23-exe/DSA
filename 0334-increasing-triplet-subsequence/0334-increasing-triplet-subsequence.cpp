class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3){
            return false;
        }

        vector<int> l;
        vector<int> r;
        int n =nums.size();
//left smallest is formed
        int lsmallest=nums[0];

        for(int i =0;i<n;i++){
            l.push_back(lsmallest);
            if(lsmallest>nums[i]){
                lsmallest=nums[i];
            }
        }
//right largest now
        int rbiggest = nums[n-1];
        for(int i =n-1;i>=0;i--){
            r.push_back(rbiggest);
            if(rbiggest<nums[i]){
                rbiggest=nums[i];
            }
        }
        reverse(r.begin(),r.end());

        for(int i = 0 ; i<n;i++){
            if(l[i]<nums[i] && nums[i]<r[i] ){
                return true;
            }
        }

        return false;


        

    }
        
};