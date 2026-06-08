class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> more;
        int pcount=0;

        for(int i =0;i<nums.size();i++){
            if(nums[i]<pivot){
                less.push_back(nums[i]);
            }else if(nums[i]==pivot){
                pcount+=1;
            }else{
                more.push_back(nums[i]);
            }
        }

        while(pcount>0){
            less.push_back(pivot);
            pcount--;
        }
        for(int i =0;i<more.size();i++){
            less.push_back(more[i]);
        }

        return less;
        
    }
};