class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>small;
        vector<int>large;
        vector<int>ans(nums.size(),pivot);
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) small.push_back(nums[i]);

            if(nums[i]>pivot) large.push_back(nums[i]);
        }
        
        for(int i=0;i<small.size();i++){
            ans[i]=small[i];
        }
        int j=n-1;
        for(int i=large.size()-1;i>=0;i--){
            ans[j]=large[i];
            j--;
        }

        return ans;
    }
};