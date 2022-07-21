#include<bits/stdc++.h>
void fill_subset(vector<int>arr,int i,vector<int>&subset,vector<vector<int>>&ans)
{
    if(i>=arr.size())
    {
        ans.push_back(subset);
        return;
    }
    subset.push_back(arr[i]);
    fill_subset(arr,i+1,subset,ans);
    subset.pop_back();
    
    while(i+1<arr.size() and arr[i]==arr[i+1])
        i++;
    fill_subset(arr,i+1,subset,ans);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>subset;
    sort(arr.begin(),arr.end());
    fill_subset(arr,0,subset,ans);
    sort(ans.begin(),ans.end());
    return ans;
}