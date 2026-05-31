class Solution {
public:
    void dfs(int i,unordered_map<int,vector<int>> &adjlist,vector<bool> &vis,stack<int> &st,vector<bool> &currPath,bool &flag){
        vis[i]=true;
        currPath[i]=true;
        for(int &v:adjlist[i]){
            if(!vis[v]){
                dfs(v,adjlist,vis,st,currPath,flag);
            }else if(currPath[v]){
                flag=true;
            }
            
        }
        currPath[i] = false;
        st.push(i);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //if(numCourses==1) return {0};
        
        unordered_map<int,vector<int>> adjlist;
        for(auto &e:prerequisites){
            adjlist[e[1]].push_back(e[0]);
        }

        


        vector<bool>vis(numCourses,false);
        stack<int> st;
        bool flag = false;
        vector<bool>currPath(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                dfs(i,adjlist,vis,st,currPath,flag);
            }
            currPath.assign(numCourses, false);

        }
        if(flag) return {};
        //coping stack
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};