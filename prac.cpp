#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printseries(int n, int k,vector<int>&ans)
{
    if (n <= 0)
    {
       ans.push_back(n);
        return ;
    }

   ans.push_back(n);
    printseries(n - k, k,ans);
   ans.push_back(n);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    printseries(n, k,ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ",";
    }
    cout << endl;
}