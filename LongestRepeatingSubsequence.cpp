/*Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

Example 1:

Input:
str = "axxzxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x z x y 
0 1 2 3 4 5

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
Example 2:

Input:
str = "axxxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x x y 
0 1 2 3 4

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 3  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.

Your Task:
You don't need to read or print anything. Your task is to complete the LongestRepeatingSubsequence() which takes str as input parameter and returns the length of the longest repeating subsequnece.


Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)*/
public:
	   // int solve(string &x,string &y,int n,int m,vector<vector<int>>&dp)
	   // {
	   //     if(n==0||m==0)
	   //     return 0;
	   //     if(dp[n][m]!=0)
	   //     return dp[n][m];
	   //     if(n==m||x[n-1]!=y[m-1])
	   //     return dp[n][m]=max(solve(x,y,n-1,m,dp),solve(x,y,n,m-1,dp));
	   //     return dp[n][m]=1+solve(x,y,n-1,m-1,dp);
	   // }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    string s=str;
		    int n=s.size();
		    int dp[n+1][n+1];
		    for(int i=0;i<n+1;i++)
		    dp[0][i]=0;
		    for(int i=0;i<n+1;i++)
		    dp[i][0]=0;
		    for(int i=1;i<n+1;i++)
		    for(int j=1;j<n+1;j++)
		    {
		        if(i==j||s[i-1]!=str[j-1])
		        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		        else
		        dp[i][j]=1+dp[i-1][j-1];
		    }
		    return dp[n][n];
		    
		}
