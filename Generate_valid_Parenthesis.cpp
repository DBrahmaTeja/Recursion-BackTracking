void printall(int ind,int n,int opencnt,int closecnt,string &str)
{
    if(ind==2*n)
    {
        cout<<str<<endl;
        return;
    }
    if(opencnt<n)
    {
        str.push_back('(');
        printall(ind+1,n,opencnt+1,closecnt,str);
        str.pop_back();
    }
    if(opencnt>closecnt)
    {
        str.push_back(')');
        printall(ind+1,n,opencnt,closecnt+1,str);
        str.pop_back();
    }
}
/*
Our complexity analysis rests on understanding how many elements there are in generateParenthesis(n).
 This analysis is outside the scope of this article, but it turns out this is the n-th Catalan number
    1
        (2n)
   ---  
        (n)
   n+1 
    which is bounded asymptotically by 4^n/n*sqrt(n);
    TC: O(4^n/sqrt(n)) Each valid sequence has at most n steps during the backtracking procedure.
    sc:O(4^n/sqrt(n)) , as described above, and using O(n) space to store the sequence.

*/