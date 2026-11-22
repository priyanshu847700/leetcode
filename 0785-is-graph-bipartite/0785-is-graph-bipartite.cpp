class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int> &colour,int u,int curr_colour){

        queue<int> q;
        q.push(u);
        colour[u]=curr_colour;

        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(int v : graph[top]){

                if(colour[v] == colour[top]){
                    return false;
                }
                if(colour[v] == -1){
                    colour[v] = 1 - colour[top];
                    q.push(v);
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n=graph.size();
        vector<int> colour(n,-1);

        int curr_colour = 1;     // red -> 1  |  green -> 0 
        for(int i=0;i<n;i++){
            if(colour[i] == -1 && bfs(graph,colour,i,curr_colour) == false){
                return false;
            }
        }
        return true;
    }
};