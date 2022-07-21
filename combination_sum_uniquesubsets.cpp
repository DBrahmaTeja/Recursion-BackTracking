#include<bits/stdc++.h>
void helper(int i,int sum,int target,vector<int>arr,vector<int>&subset,vector<vector<int>>&ans)
{
    if(sum==target)
    {
        ans.push_back(subset);
        return ;
    }
    if(sum>target)
        return;
    if(i>=arr.size())
        return ;
    
    //picking up;
    sum+=arr[i];
    subset.push_back(arr[i]);
    helper(i+1,sum,target,arr,subset,ans);
    subset.pop_back();
    sum-=arr[i];
    
    //not picking up so skip for same values 
    while(i+1<arr.size() and arr[i]==arr[i+1])
        i++;
    helper(i+1,sum,target,arr,subset,ans);
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    vector<int>subset;
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    helper(0,0,target,arr,subset,ans);
    return ans;
}
