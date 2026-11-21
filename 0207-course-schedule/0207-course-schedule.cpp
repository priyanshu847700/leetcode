class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto p : prerequisites){
            adj[p[0]].push_back(p[1]);
        }

        vector<bool> visited(adj.size(),false);
        vector<int> indegree(adj.size(),0);

        for(int u=0;u<adj.size();u++){
            for(int v : adj[u]){
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> topological_order;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            topological_order.push_back(u);

            for(int v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        if(topological_order.size() == numCourses){
            return true;
        }
        return false;
    }
};