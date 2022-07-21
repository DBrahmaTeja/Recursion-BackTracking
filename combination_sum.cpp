#include<bits/stdc++.h>
void helper(int i,int present_sum,vector<int>&arr,int sum,vector<int>&subset,vector<vector<int>>&ans)
{
    if(present_sum==sum)
    {
        ans.push_back(subset);
        return;
    }
    if(i>=arr.size() or present_sum>sum)
        return;
    present_sum+= arr[i];
    subset.push_back(arr[i]);
    helper(i,present_sum,arr,sum,subset,ans);
    subset.pop_back();
    present_sum-=arr[i];
    helper(i+1,present_sum,arr,sum,subset,ans);
}


vector<vector<int>> combSum(vector<int>& ARR, int B)
{
	// Write your code here
	// Return a vector of sorted vectors/combinations
    vector<int>subset;
    vector<vector<int>>ans;
    sort(ARR.begin(),ARR.end());
    helper(0,0,ARR,B,subset,ans);
    return ans;
}
