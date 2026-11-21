class Solution {
public:
    bool hasCycle(vector<vector<int>>& adj,vector<bool> &visited,vector<bool> &in_recursion,int u){
        visited[u]=true;
        in_recursion[u]=true;

        for(int v : adj[u]){
            if(!visited[v] && hasCycle(adj,visited,in_recursion,v)){
                return true;
            }
            else if(visited[v] && in_recursion[v] == true){
                return true;
            }
        }

        in_recursion[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto p : prerequisites){
            adj[p[0]].push_back(p[1]);
        }

        vector<bool> visited(numCourses,false);
        vector<bool> in_recursion(numCourses,false); 

        for(int i=0;i<numCourses;i++){
            if(!visited[i] && hasCycle(adj,visited,in_recursion,i) == true ){
                return false;               
            }
        }

        return true;
    }
};