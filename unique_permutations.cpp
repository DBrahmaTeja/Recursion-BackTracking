#include<bits/stdc++.h>
void fill_unq_perm(int pos,vector<int>&arr,vector<vector<int>>&ans)
{
    if(pos>=arr.size())
    {
        ans.push_back(arr);
        return;
    }
    unordered_set<int>hs;
    for(int i=pos;i<arr.size();i++)
    {
        if(hs.find(arr[i])!=hs.end())
            continue;
        hs.insert(arr[i]);
        swap(arr[i],arr[pos]);
        fill_unq_perm(pos+1,arr,ans);
        swap(arr[i],arr[pos]);
    }
}


vector<vector<int> > uniquePermutations(vector<int> &arr, int n) {
	// Write your code here.
    vector<vector<int>>ans;
    fill_unq_perm(0,arr,ans);
    return ans;
        
}