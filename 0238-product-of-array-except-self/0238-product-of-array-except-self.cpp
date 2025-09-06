class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        vector<int> right;


        
        left.push_back(1);
        for(int i =1;i<nums.size();i++){
            left.push_back(nums[i-1]*left.back());
        }
        
        reverse(nums.begin(),nums.end()); //reversing the original array 
        right.push_back(1);
        for(int i =1;i<nums.size();i++){
            right.push_back(nums[i-1]*right.back());
        }
        reverse(right.begin(),right.end()); //right array , is in correct order 

        vector<int> ans;

        for(int i =0;i<nums.size();i++){
            ans.push_back(left[i]*right[i]);
        }


        


           
            
           
        

        return ans;

        
    }
};