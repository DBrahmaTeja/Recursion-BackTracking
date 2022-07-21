void fill_subsets(vector<int>v,int i,vector<int>&subset,vector<vector<int>>&ans)
{
    if(i>=v.size())
    {
        ans.push_back(subset);
        return;
    }
    subset.push_back(v[i]);
    fill_subsets(v,i+1,subset,ans);
    subset.pop_back();
    fill_subsets(v,i+1,subset,ans);
}

vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>>ans;
    vector<int>subset;
    fill_subsets(v,0,subset,ans);
    return ans;
}