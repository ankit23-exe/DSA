class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adjlist;
        vector<int>indegree(numCourses,0);
        for(auto &p:prerequisites){
            adjlist[p[1]].push_back(p[0]);
            indegree[p[0]]++;

        }

        queue<int> que;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){     
                que.push(i);
            }
        }
        //queue work
        while(!que.empty()){
            int f = que.front();
            que.pop();
            for(int neigh:adjlist[f]){
                indegree[neigh]--;
                if(indegree[neigh]==0) que.push(neigh);
            }
        }

         


        for(int i=0;i<numCourses;i++){
            if(indegree[i]>0) return false;  
        }
        return true;

    }
};