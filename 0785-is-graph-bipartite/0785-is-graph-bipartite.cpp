class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int> &colour,int u,int curr_colour){
        colour[u]=curr_colour;

        for(int v : graph[u]){
            if(colour[v] == colour[u]){
                return false;
            }
            if(colour[v] == -1){
                int colour_v = 1 - colour[u];

                if(dfs(graph,colour,v,colour_v) == false){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        vector<int> colour(graph.size(),-1);
        int curr_colour=1;

        for(int i=0;i<graph.size();i++){
            if(colour[i] == -1 && dfs(graph,colour,i,curr_colour) == false){
                return false;
            }
        }
        return true;
    }
};