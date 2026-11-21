class Solution {
public:
    bool has_cycle(vector<vector<int>> &adj,vector<bool> &visited,vector<bool> &in_recursion,stack<int> &s,int u){
        visited[u]=true;
        in_recursion[u]=true;

        for(int v : adj[u]){
            if(!visited[v] && has_cycle(adj,visited,in_recursion,s,v)){
                return true;
            }
            if(visited[v] && in_recursion[v] == true){
                return true;
            }

        }

        in_recursion[u]=false;
        s.push(u);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);

        for(auto p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> visited(numCourses,false);
        vector<bool> in_recursion(numCourses,false);

        stack<int> s;        
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && has_cycle(adj,visited,in_recursion,s,i) == true){
                return {};
            }
        }

        vector<int> ans;
        while(!s.empty()){
            int top_el=s.top();
            s.pop();

            ans.push_back(top_el);
        }

        return ans;
    }
};