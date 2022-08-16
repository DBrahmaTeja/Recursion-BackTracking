// https://www.codingninjas.com/codestudio/problems/flood-fill-algorithm_1089687

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void help(int old,vector<vector<int>> &image,int i,int j,int newcolor,int m,int n){
    if(i<0 || j<0 || i==m || j==n || image[i][j]!=old) return;
    image[i][j] = newcolor;
    help(old,image,i,j+1,newcolor,m,n);
    help(old,image,i,j-1,newcolor,m,n);
    help(old,image,i+1,j,newcolor,m,n);
    help(old,image,i-1,j,newcolor,m,n);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int old = image[x][y];
    if(old == newColor){
        return image;
    }
    int m = image.size();
    int n = image[0].size();
    help(old,image,x,y,newColor,m,n);
    return image;
}