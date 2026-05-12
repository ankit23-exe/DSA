class Solution {
public:
    bool ispossible(int x,vector<vector<int>>& tasks){
        for(auto &t:tasks){
            if(t[1]>x){
                return false;
            }else{
                x-=t[0];
            }
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int s =0;
        int e = 1e9;

        // for(auto &p:tasks){
        //     s+=p[0];
        //     e+=p[1];
        // }
        int ans =INT_MAX;

        auto lambda = [](auto task1, auto task2){
            int diff1 = task1[1]-task1[0];
            int diff2 = task2[1]-task2[0];
            return diff1 > diff2;
        };

        sort(begin(tasks),end(tasks),lambda);

        while(s<=e){
            int mid = s +(e-s)/2;
            if(ispossible(mid,tasks)){
                e = mid-1;
                ans = mid;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};