class Solution {
public:
    void solve_bfs(vector<vector<int>>& isConnected,vector<int> &visited,int u){
        
        queue<int> q;
        q.push(u);
        visited[u]=true;

        while( !q.empty() ){
            int u=q.front();
            q.pop();

            for(int v = 0; v < isConnected.size(); v++){
                if(!visited[v] && isConnected[u][v] == 1){
                    q.push(v);
                    visited[v]=true;
                }
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
                solve_bfs(isConnected,visited,i);

            }
        }

        return ans;
    }
};