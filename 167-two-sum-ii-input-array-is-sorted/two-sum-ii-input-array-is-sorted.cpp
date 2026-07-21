class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        if(n==2){
            if(numbers[0]+numbers[1]==target) return {1,2};
        }
        for(int i=0;i<=n-2;i++){
            int left = target-numbers[i];
            int s =i+1;
            int e = n-1;
            while(s<=e){
                int mid = s+(e-s)/2;
                if(numbers[mid]==left){
                    return {i+1,mid+1};
                }else if(numbers[mid]>left){
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }
        }
        return {-1,-1};
    }
};