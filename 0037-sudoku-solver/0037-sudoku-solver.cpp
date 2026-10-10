class Solution {
public:
    bool isvalid(vector<vector<char>>& board,int row,int col,char dig){
        for(int i=0;i<9;i++){
            if(board[row][i]==dig && (i!=col) ){
                return false;
            }
            if(board[i][col]==dig && (i!=row) ){
                return false;
            }
        }

        int strow=(row/3)*3;
        int stcol=(col/3)*3;

        for(int i=strow;i<=strow+2;i++){
            for(int j=stcol;j<=stcol+2;j++){
                if( ( i!=row || j!=col ) && board[i][j] == dig){
                    return false;
                }
            }
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j] == '.'){

                    for(char dig='1';dig<='9';dig++){
                        if(isvalid(board,i,j,dig)){
                            board[i][j]=dig;
                            if(solveSudoku(board) == true){
                                return true; 
                            }
                            board[i][j]='.';
                        }
                    }
                    
                    return false;
                }
            }
        }
        return true;
    }
};