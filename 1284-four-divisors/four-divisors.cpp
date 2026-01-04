class Solution {
public:
    unordered_map<int,int> mp;  //num -> sum of divisor (if valid)

    int checker(int num){
        if(mp.count(num)){
            return mp[num];
        }
        int count= 0;
        int sum =0;
        for(int i=1;i<=sqrt(num);i++){
            if(num%i==0){
                sum+= i;
                int otherfac= num/i;
                count+=2;
                sum+=otherfac;
                if(otherfac==i){
                    count--;
                    sum-=otherfac;
                }

            }
        }
        if(count==4){
            mp[num]=sum;
            return sum;
        }else{
            return 0;
        }
    }

    int sumFourDivisors(vector<int>& nums) {
        int n =nums.size();
        int ans =0;
        for(int i =0 ; i<n;i++){

            ans+=checker(nums[i]);  // return sum if valid  else return 0
        }

        return ans;
    }
};