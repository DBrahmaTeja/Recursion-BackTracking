// https://www.codingninjas.com/codestudio/contests/recursion-contest-by-mohammad-fraz/5038397/problems/8857

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void helper(long long n,vector<long long> &ans,long long sum){
    if(sum){
        ans.push_back(sum);
    }
    if(sum*10+2<=n){
        helper(n,ans,sum*10+2);
    }
    if(sum*10+5<=n){
        helper(n,ans,sum*10+5);
    }
}

vector<long long> createSequence(long long n){
    // Write your code here.
    vector<long long> ans;
    int sum=0;
    helper(n,ans,0);
    sort(ans.begin(),ans.end());
    return ans;
}
