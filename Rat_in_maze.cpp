/*
You are given a 'N' * 'N' maze with a rat placed at 'MAZE[0][0]'. Find and print all paths that rat can follow to reach its destination i.e. 'MAZE['N' - 1]['N' - 1]'. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the 'MAZE' can either be 0 or 1. Cells with value 0 are blocked means the rat can­not enter into those cells and those with value 1 are open.
Input Format:
The first line of input contains an integer 'N' representing the dimension of the maze.

The next 'N' lines of input contain 'N' space-separated integers representing the type of the cell.
Output Format :
For each test case, return the path from the start position to the destination position and only cells that are part of the solution path should be 1, rest all cells should be 0.

Output for every test case will be printed in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= N <= 10
0 <= MAZE[i][j] <=1

Where 'MAZE[i][j]' denotes the value in the cell of 'MAZE'.

Time Limit: 1 sec
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1
Explanation For Sample Output 1:
Only 1 path is possible which contains coordinate < (1,1), (2,1), (3,1), (3,2) and (3,3) >

So our path matrix will look like this:

1 0 0
1 0 0
1 1 1

Which is returned from left to right and then top to bottom in one line.
*/
void solve(vector<vector<int>> &board, vector<vector<int>> &vis, vector<vector<int>> &ans,
           vector<vector<int>> maze, int n, int row, int col)
{
    if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0)
        return;
    if (row == n - 1 and col == n - 1)
    {
        vector<int> temp(n * n);
        board[row][col] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                temp[i * n + j] = board[i][j];
            }
        ans.push_back(temp);
        return;
    }
    if (!vis[row][col])
    {
        vis[row][col] = 1;
        board[row][col] = 1;
        // right
        solve(board, vis, ans, maze, n, row, col + 1);
        // left
        solve(board, vis, ans, maze, n, row, col - 1);
        // up
        solve(board, vis, ans, maze, n, row - 1, col);
        // down
        solve(board, vis, ans, maze, n, row + 1, col);
        // backtrack;
        vis[row][col] = 0;
        board[row][col] = 0;
    }
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    // Write your code here.
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(board, vis, ans, maze, n, 0, 0);
    return ans;
}
Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.

Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space).
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --class Solution
/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at
(3, 3) from (0, 0) by two paths - DRDDRR
and DDRDRR, when printed in sorted order
we get DDRDRR DRDDRR.
*/
{
    void solve(string &path, vector<vector<int>> &vis, vector<string> &ans,
               vector<vector<int>> maze, int n, int row, int col)
    {
        if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0)
            return;
        if (row == n - 1 and col == n - 1)
        {
            ans.push_back(path);
            return;
        }
        if (!vis[row][col])
        {
            vis[row][col] = 1;

            // right
            path.push_back('R');
            solve(path, vis, ans, maze, n, row, col + 1);
            path.pop_back();
            // left
            path.push_back('L');
            solve(path, vis, ans, maze, n, row, col - 1);
            path.pop_back();
            // up
            path.push_back('U');
            solve(path, vis, ans, maze, n, row - 1, col);
            path.pop_back();
            // down
            path.push_back('D');
            solve(path, vis, ans, maze, n, row + 1, col);
            path.pop_back();
            // backtrack;
            vis[row][col] = 0;
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        string path;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        solve(path, vis, ans, m, n, 0, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.

Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space).