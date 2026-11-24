class Solution {
public:

    int find (int x,vector<int> &parent) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x],parent);
    }

    void Union (int x, int y,vector<int> &parent,vector<int> &rank) {
        int x_parent = find(x,parent);
        int y_parent = find(y,parent);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } 
        else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } 
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
     
        vector<int> parent(n,-1);
        vector<int> rank(n,0);
        
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }
        
        for(auto &vec : edges) {
            
            int u = vec[0];
            int v = vec[1];
            
            Union(u, v, parent, rank);
            
        }
       
        unordered_map<int, int> mp;
        
        for(int i = 0; i<n; i++) {
            int papa = find(i,parent);
            mp[papa]++;
        }
        
        long long result = 0;
        long long remainingNodes = n;
        
        for(auto &it : mp) {
            
            long long size = it.second;
            
            result += (size) * (remainingNodes-size);
            
            remainingNodes -= size;
            
        }
        
        return result;
        
    }
};