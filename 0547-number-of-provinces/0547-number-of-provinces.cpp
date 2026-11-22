class Solution {
public:
    void solve_dfs(vector<vector<int>>& isConnected,vector<int> &visited,int u){
        visited[u]=true;

        for(int v = 0; v < isConnected.size(); v++){
            if(!visited[v] && isConnected[u][v] == 1){
                solve_dfs(isConnected,visited,v);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected){

        int n = isConnected.size();
        vector<int> visited(n,0);

        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){

                ans++;
                solve_dfs(isConnected,visited,i);

            }
        }

        return ans;
    }
};