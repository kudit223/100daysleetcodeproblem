/*Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.*/
//time complexity:O(n^2)
//space complexity:O(n+(n+1)^2)
class Solution {
public:
    int lcs(string &s,string &y,int n,int m,vector<vector<int>>&dp)
    {
        if(n==0||m==0)
        return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n-1]==y[m-1]) return dp[n][m]=1+lcs(s,y,n-1,m-1,dp);
        return dp[n][m]=max(lcs(s,y,n-1,m,dp),lcs(s,y,n,m-1,dp));

    }
    int minInsertions(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return n-lcs(s,s1,n,n,dp);
    }
};
