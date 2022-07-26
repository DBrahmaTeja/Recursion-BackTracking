// https://www.codingninjas.com/codestudio/problems/letter-combinations-of-a-phone-number_983623

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>
void help(int i,string &s,unordered_map<char,string> &m,vector<string> &ans,string &temp){
    if(i==s.size()){
        ans.push_back(temp);
        return;
    }
    string str = m[s[i]];
    for(int j=0;j<str.size();j++){
        temp.push_back(str[j]);
        help(i+1,s,m,ans,temp);
        temp.pop_back();
    }
}

vector<string> combinations(string s){
	
	// Write your code here
	unordered_map<char,string> m;
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    vector<string> ans;
    string temp;
    help(0,s,m,ans,temp);
    return ans;
}
