class Solution {
public:
    int t[101][101][201];
    bool validpath(vector<vector<char>>& grid,int ans,int row,int col,int i,int j){
        if(i>=row || j>=col){
            return false;
        }

        if(grid[i][j] == '('){
            ans++;
        }
        else{
            ans--;
        }

        if(ans<0){
            return false;
        }

        if(t[i][j][ans] != -1){
            return t[i][j][ans];
        }

        if(i==row-1 && j==col-1){
            return t[i][j][ans]= (ans==0);
        }

        if(validpath(grid,ans,row,col,i+1,j)){
            return t[i][j][ans] = true;
        }
        
        if(validpath(grid,ans,row,col,i,j+1)){
            return t[i][j][ans] = true;
        }

        return t[i][j][ans] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ans;

        if((row + col - 1) % 2 != 0)
            return false;

        if(grid[0][0] == ')')
            return false;

        if(grid[row-1][col-1] == '(')
            return false;

        memset(t,-1,sizeof(t));

        return(validpath(grid,0,row,col,0,0)); 
    }
};