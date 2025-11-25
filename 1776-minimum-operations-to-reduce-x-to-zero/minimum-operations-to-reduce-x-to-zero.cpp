class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n=nums.size();
        unordered_map<int,int> map;
        int sum=0;

        int longestlen=INT_MIN;
        
        map[0]=-1;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            map[sum]=i;
        }

        if(sum<x){
            return -1;
        }
        int target=sum-x;
        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int findsum=sum-target;

            if(map.find(findsum)!=map.end()){

                longestlen=max(longestlen,i-map[findsum]);

            }
        }

        return longestlen==INT_MIN ?-1:n-longestlen;

        
        
    }
};