void helper(int i,int k,int present_sum,int n,vector<int>&subset,vector<vector<int>>&ans)
{
    if(k<0)
        return;
    if(k==0)
    {
        if(present_sum==n)
        {
            ans.push_back(subset);
        }
        return;
    }
    if(i==10)
        return;
    //pickup
    present_sum+=i;
    subset.push_back(i);
    helper(i+1,k-1,present_sum,n,subset,ans);
    subset.pop_back();
    present_sum-=i;
    
    //not picking up
    helper(i+1,k,present_sum,n,subset,ans);
}
vector<vector<int>> combinationSum3(int k, int n) {
    // Write your code here.
    vector<int>subset;
    vector<vector<int>>ans;
    helper(1,k,0,n,subset,ans);
    return ans;
}
