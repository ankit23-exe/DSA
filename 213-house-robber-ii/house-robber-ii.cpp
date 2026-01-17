class Solution {
public:
    vector<int> t;
    int solve(int i ,vector<int>& nums){
        if(i>=nums.size()){
            return 0;
        } 
        //memorisation use kr rha hai
        if(t[i]!=-1){
            return t[i];
        }

        //steal
        int steal = nums[i] +solve(i+2,nums);
        //skip
        int skip = solve(i+1,nums);

        return t[i] = max(steal,skip);
    }
    int rob(vector<int>& nums) {

        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        t.resize(nums.size() ,-1);
        //1 house mai chori krenga
        int lastno = nums.back();
        nums.pop_back(); 
        int ans1 = solve(0,nums);

        //1st house mai nhi krenga 
        nums.push_back(lastno);
        t.assign(nums.size(),-1);
        int ans2= solve(1,nums);

        return max (ans1, ans2);
    }
};