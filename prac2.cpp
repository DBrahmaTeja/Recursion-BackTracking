#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void createsequence(long long n,int i,vector<long long>&ans)
{
    if(ans[ans.size()-1]>n)
    {
        ans.pop_back();
        return;
    }
    
    long long top=ans[i];
     ans.push_back(top*10+2);
        i++;
    if(ans[ans.size()-1]>n)
    {
        ans.pop_back();
        return;
    }
        ans.push_back(top*10+5);
        i++;
   createsequence(n,i,ans);
}

int main()
{
    int n;
    cin >> n ;
    vector<long long>ans;
    if(n<2)
        return 0;
    if(n>=2)
    {
        ans.push_back(2);
        if(n>=5)
            ans.push_back(5);
        else
            return 0;
    }
    createsequence(n,0,ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ",";
    }
    cout << endl;
}