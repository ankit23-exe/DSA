class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int freq =1;
        int n= nums.size();
        for(int i=1;i<n;i++){
            if(num==nums[i]){
                freq++;
            }else{
                freq--;
                if(freq<=0){
                    freq=1;
                    num=nums[i];
                }
            }
        }
        return num;
        

    }
};