class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> visited(numCourses,false);
        vector<int> indegree(numCourses,0);

        for(int i=0;i<adj.size();i++){
            for(int v : adj[i]){
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int top=q.front();
            q.pop();

            ans.push_back(top);

            for(int v : adj[top]){
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        if(ans.size() == numCourses){
            return ans;
        }
        return {};
    }
};