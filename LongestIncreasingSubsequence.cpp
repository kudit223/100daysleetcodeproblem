
/*Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?*/
-----------------------------------approach1----------------------------------------
 time complexity =o(pow(n,2))
  this approach gives time limit exceed
class Solution {
public:
    int seq(vector<int>nu,vector<int>v,int n,int m,vector<vector<int>>&dp)
    {
        if(n==0||m==0)
        return 0;
        if(dp[n][m]!=-1)
        return dp[n][m];
        if(nu[n-1]==v[m-1])
        return dp[n][m]=1+seq(nu,v,n-1,m-1,dp);
        else
        return dp[n][m]=max(seq(nu,v,n-1,m,dp),seq(nu,v,n,m-1,dp));
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        set<int>s;
        for(auto value:nums)
        s.insert(value);
        for(auto value:s)
        v.push_back(value);
        int m=v.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return seq(nums,v,n,m,dp);

        
    }
};
----------------------------------------------------approach2------------------------------------------------
  class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n=nums.size();
      int dp[n];
      dp[n-1]=1;
      for(int i=n-2;i>=0;i--)
      {
        int maxx=1;
        for(int j=i+1;j<n;j++)
        {
          if(nums[i]<nums[j])
          maxx=max(maxx,1+dp[j]);
          else
          maxx=max(1,maxx);
        }
        dp[i]=maxx;
      }
      return *max_element(dp,dp+n);
        
    }
};
