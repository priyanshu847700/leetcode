class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> child_to_parent;

        // only 1 parent -
        for(int i=0;i<n;i++){
            int parent = i;
            int leftC=leftChild[i];
            int rightC=rightChild[i];

            if(leftC != -1){
                adj[i].push_back(leftC);

                if(child_to_parent.find(leftC) != child_to_parent.end()){
                    return false;
                }
                child_to_parent[leftC]=parent;
            }

            if(rightC != -1){
                adj[i].push_back(rightC);

                if(child_to_parent.find(rightC) != child_to_parent.end()){
                    return false;
                }
                child_to_parent[rightC]=parent;
            }
        }

        // only one root
        int root=-1;
        for(int i=0;i<n;i++){
            if(child_to_parent.find(i) == child_to_parent.end()){
                if(root != -1){
                    return false;
                }
                root= i;
            }
        }
        if(root == -1){
            return false;
        }

        //BFS traversal count;
        int count=0;
        queue<int> q;
        vector<int> visited(n,0);

        q.push(root);
        visited[root]=true;
        count++;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int v: adj[node]){
                if(!visited[v]){
                    count++;
                    visited[v]=true;
                    q.push(v);
                }
            }
        }

        if(count == n){
            return true;
        }
        return false;
    }
};