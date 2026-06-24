/*
    LeetCode 79 - Word Search

    Approach:
    - Use DFS + Backtracking to search for the word in the grid.
    - Start DFS from every cell in the board.
    - If the current cell matches the current character of the word,
      explore all four directions (up, down, left, right).
    - Mark the current cell as visited to avoid reusing it in the same path.
    - Restore the original value while backtracking.
    - If all characters are matched, return true.

    Time Complexity: O(M * N * 4^L)
        M = Number of rows
        N = Number of columns
        L = Length of the word

    Space Complexity: O(L)
        Recursion stack depth in the worst case.
*/
class Solution {
public:
    bool bfs(vector<vector<char>>& board, string word,int row,int col,int index){
        if(index == word.size()) return true;

        if(row<0||row>=board.size()||
        col<0||col>=board[0].size()||
        board[row][col]!=word[index]){
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';
        bool found = 
        bfs(board,word,row+1,col,index+1)||
        bfs(board,word,row-1,col,index+1)||
        bfs(board,word,row,col+1,index+1)||
        bfs(board,word,row,col-1,index+1);

        board[row][col] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(bfs(board,word,row,col,0)){
                    return true;
                }
            }
        }

        return false;
    }
};
