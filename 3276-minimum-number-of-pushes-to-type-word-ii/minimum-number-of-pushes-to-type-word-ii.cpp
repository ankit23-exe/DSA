class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[word[i]-'a']++;
        }

        priority_queue<int> pq; //max heap
        for(int f:freq){
            pq.push(f);
        }

        int ans = 0;
        int multiple =1;
        int count =0;

        while(!pq.empty()){
            ans+=pq.top()*multiple;
            pq.pop();
            count++;
            if(count==8){
                multiple++;
                count=0;
            }

        }
        return ans;
    }
};