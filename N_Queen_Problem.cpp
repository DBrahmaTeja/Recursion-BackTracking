/*
           top left
   left
           bottom left
   T0hese checks are sufficient as we are filling from left to right.

*/
/*bool issafe(vector<string>board,int row,int col,int n)
   {
       for(int i=col;i>=0;i--)
       {
           if(board[row][i]=='Q')
               return false;

       }
       int x=row,y=col;
       while(x>=0 and y>=0)
       {
           if(board[x][y]=='Q')
               return false;
           x--;
           y--;
       }
       x=row,y=col;
       while(x<n and y>=0)
       {
           if(board[x][y]=='Q')
               return false;
           x++;
           y--;
       }
       return true;
   }

   void solve(vector<string>&board,vector<vector<string>>&ans,int col,int n)
   {
       if(col==n)
       {
           ans.push_back(board);
           return;
       }
       for(int row=0;row<n;row++)
       {
           if(issafe(board,row,col,n))
           {
               board[row][col]='Q';
               solve(board,ans,col+1,n);
               board[row][col]='.';
           }
       }
   }*/
void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftrow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
            board[row][col] = '.';
            leftrow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

public:
vector<vector<string>> solveNQueens(int n)
{
    /*vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
        board[i]=s;
    solve(board,ans,0,n);
    return ans;*/
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
    return ans;
}
Time Complexity: Exponential in nature since we are trying out all ways, to be precise it is O(N! * N).
After optimised it will be N!.
Space Complexity: O(N^2)