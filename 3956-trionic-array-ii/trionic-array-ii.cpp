class Solution {
public:
    typedef long long ll;
    int n ;
    vector<vector<ll>> memo;
    ll solve(int i , int trend,vector<int>& nums){

        if(i==n){
            if(trend==3)
                return 0;
            else{
                return LLONG_MIN/2;
            }
        }

        if(memo[i][trend]!=LLONG_MIN){
            return memo[i][trend];
        }
        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        if(trend == 0){
            skip = solve(i+1,0,nums);
        }

        if(trend == 3){
            take = nums[i];
        }

        if(i+1<n){
            ll curr = nums[i];
            ll next = nums[i+1];
            if(trend==0 && curr<next){
                take = max(take, curr+ solve(i+1,1,nums)); 
            }else if(trend==1 && curr<next){
                take= max(take,curr+solve(i+1,1,nums));
            }else if(trend==1 && curr>next){
                take = max(take,curr+solve(i+1,2,nums));
            }else if(trend ==2){
                if(curr>next){
                    take =max(take,curr+solve(i+1,2,nums));
                }else if(curr<next){
                    take =max(take,curr+solve(i+1,3,nums));
                }
            }else if(trend == 3){
                if(curr<next){
                    take = max(take, curr+ solve(i+1,3,nums));
                }
            }
        }

        return  memo[i][trend]=max(take,skip);
    }

    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        memo.assign(n+1,vector<ll>(4,LLONG_MIN));
        return solve(0,0,nums); //passing i , trend =0, and nums
    }
};