void helper(int i,int k,int n,vector<int>&subset,vector<vector<int>>&ans)
{
    if(k==0)
    {
        ans.push_back(subset);
        return;
    }
    if(k>n-i+1)
        return;
    if(i>n)
        return;
    
    //pick it up.
    subset.push_back(i);
    helper(i+1,k-1,n,subset,ans);
    subset.pop_back();
    
    helper(i+1,k,n,subset,ans);
}

vector<vector<int>> combinations(int n, int k)
{
    // Write your code here.
    vector<int>subset;
    vector<vector<int>>ans;
    helper(1,k,n,subset,ans);
    return ans;
}