// https://www.codingninjas.com/codestudio/problems/string-concatination_2195424

#include<bits/stdc++.h>
bool isrepeat(vector<int>selected,string str)
{
    vector<int>self_check(26);
    for(int i=0;i<str.size();i++)
    {
        if(self_check[str[i]-'a']==1) return true;
        self_check[str[i]-'a']=1;
    }
    for(int i=0;i<26;i++)
    {
        if(selected[i]==1 and self_check[i]==1)
            return true;
    }
    return false;
}


int help(int i,int len,vector<string>&arr,int n,vector<int>&selected)
{
    if(i==n)
    {
        return len;
    }
    
    if(isrepeat(selected,arr[i]))
    {
        //skip
        return help(i+1,len,arr,n,selected);
    }
    else
    {
        //consider
        len+=arr[i].size();
        for(int j=0;j<arr[i].size();j++)
        {
            selected[arr[i][j]-'a']=1;
        }
        int op1=help(i+1,len,arr,n,selected);
        len-=arr[i].size();
        for(int j=0;j<arr[i].size();j++)
        {
            selected[arr[i][j]-'a']=0;
        }
        //skip
        int op2=help(i+1,len,arr,n,selected);
        return max(op1,op2);
    }
}
    



int stringConcatenation(vector<string> &arr)
{
    // Write your code here
    vector<int>selected(26);
    return help(0,0,arr,arr.size(),selected);
}
