class Solution {
public:
    bool isvalid(vector<vector<char>> board,int row,int col,char dig){
        for(int i=0;i<9;i++){
            if((i!=col) && board[row][i] == dig){
                return false;
            }
            if((i!=row) && board[i][col] == dig){
                return false;
            }
        }
        
        int strow=(row/3)*3;
        int stcol=(col/3)*3;
        for(int i=strow;i<=strow+2;i++){
            for(int j=stcol;j<=stcol+2;j++){
                if((i!=row || j!=col) && board[i][j] == dig){ // && -> to skip only the particular digit
                    return false;                             // we can also use || -> beacuse we have already check vertically & horizontally
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if( board[i][j] == '.' ){
                    continue;
                }
                else{
                    char dig=board[i][j];
                    if(isvalid(board,i,j,dig) == false){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};