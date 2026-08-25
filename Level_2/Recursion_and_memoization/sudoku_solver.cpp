class Solution {
    public:
    
        bool isValid(vector<vector<char>>& board, int i, int j, int ind){
            for(int m=0;m<9;m++){
                char ch = ind + '0';
                if(board[m][j] == ch || board[i][m] == ch) return false;
                int x = m/3 + 3*(i/3);
                int y = m%3 + 3*(j/3);
                if(board[x][y]==ch) return false;
            }
            return true;
        }
    
        bool rec(vector<vector<char>>& board){
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[i].size();j++){
                    if(board[i][j]!='.') continue;
                    for(int l=1;l<10;l++){
                        if(isValid(board,i,j,l)){
                            board[i][j]=l + '0';
                            if(rec(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
                
            }
            return true;
        }
    
        void solveSudoku(vector<vector<char>>& board) {
            bool val = rec(board);
        }
    };