// https://www.codingninjas.com/codestudio/contests/recursion-contest-by-mohammad-fraz/5038397/problems/9679

#include<iostream>
#include<vector>
using namespace std;

void helper(int n,int k,vector<int> &ans){
    if(n<=0){
        ans.push_back(n);
        return;
    }
    ans.push_back(n);
    helper(n-k,k,ans);
    ans.push_back(n);
}

vector<int> printSeries(int n, int k)
{
    // Write your code here
    vector<int> ans;
    helper(n,k,ans);
    return ans;
}