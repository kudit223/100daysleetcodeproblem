/*Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.*/
------------------------------------------------------approach1----------------------------------------------
  class Solution {
public:
    string lcs(string x,string y,int n,int m,vector<vector<string>>&dp)
    {
        if(n==0||m==0)
        return "";
        if(dp[n][m]!="")
        return dp[n][m];
        if(x[n-1]==y[m-1])
        return dp[n][m]=lcs(x,y,n-1,m-1,dp)+x[n-1];
        string s1=lcs(x,y,n-1,m,dp);
        string s2=lcs(x,y,n,m-1,dp);
        return dp[n][m]=(s1.size()>s2.size())?s1:s2;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<string>>dp(n+1,vector<string>(m+1,""));
        string s=lcs(str1,str2,n,m,dp);
        cout<<s<<"\n";
        int sn=s.size();
        int i=0,j=0;
        while(m--&&j<sn)
        {
            if(str2[i]!=s[j])
            {
                str1.insert(str1.begin()+i,str2[i]);   
                i++;
            }
            else
            {
                i++;
                j++;
            }

        }
        cout<<i;
        if(i!=str2.size())
        str1+=str2.substr(i);
            
        return str1;
        
    }
};
------------------------------------------------------------approach2-------------------------------------------
  //time complexity:O(nm(m||n))
  //space complexity:O(nm)
  class Solution {
public:
    string lcs(string &x,string &y,int n,int m,vector<vector<string>>&dp)
    {
        if(n==0)
        return dp[n][m]=y.substr(0,m);
        if(m==0)
        return dp[n][m]=x.substr(0,n);
        if(dp[n][m]!="-1")
        return dp[n][m];
        if(x[n-1]==y[m-1])
        return dp[n][m]=lcs(x,y,n-1,m-1,dp)+x[n-1];
        string s1=lcs(x,y,n-1,m,dp)+x[n-1];
        string s2=lcs(x,y,n,m-1,dp)+y[m-1];
        return dp[n][m]=(s1.size()>s2.size())?s2:s1;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<string>>dp(n+1,vector<string>(m+1,"-1"));
        lcs(str1,str2,n,m,dp);
        for(int i=0;i<n+1;i++)
        {
            for(auto value:dp[i])
            cout<<value<<" ";
            cout<<'\n';
        }
        return lcs(str1,str2,n,m,dp);
    }
};
-------------------------------------------------------approach3---------------------------------------
