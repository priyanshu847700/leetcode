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

    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();

        vector<int> parent(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }

        vector<int> rank(26,0);

        for(auto s : equations){
            if(s[1] == '='){ // a == b
                setunion(s[0]-'a',s[3]-'a',parent,rank);
            }   
        }

        for(auto s : equations){
            if(s[1] == '!'){ // a != b

                int u_parent=find((int)s[0]-'a',parent);
                int v_parent=find((int)s[3]-'a',parent);

                if(u_parent == v_parent){
                    return false;
                }
            }  
        }
        return true;
    }
};