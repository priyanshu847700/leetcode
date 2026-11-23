class Solution {
public: 
    int find(int el,vector<int> &parent){
        if(el == parent[el]){
            return el;
        }

        return parent[el]=find(parent[el],parent);
    }

    void setunion(int x,int y,vector<int> &parent,vector<int> &rank){

        int x_parent=find(x,parent);
        int y_parent=find(y,parent);

        if(x_parent == y_parent){
            return;
        }

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else{                        // rank[x_parent] == rank[y_parent]
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
        
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1){
            return -1;
        }

        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        vector<int> rank(n,0);

        int component=n;
        for(auto vec : connections ){
            if( find(vec[0],parent) != find(vec[1],parent) ){

                setunion(vec[0],vec[1],parent,rank);
                component--;
            }
        }
        return component-1;
    }
};