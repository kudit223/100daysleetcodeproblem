/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400*/
-------------------------------------------------------------approach1-----------------------------------------------
  //time complexity:O(n^2)
  //space complexity:O(n)
class Solution {
public:
    int rob(vector<int>& v) {
        int n=v.size();
        int dp[n];
        dp[n-1]=v[n-1];
        int maxx=v[n-1];
        for(int i=n-2;i>=0;i--)
        {
            dp[i]=v[i];
            for(int j=2;j<n-i;j++)
            dp[i]=max(dp[i],v[i]+dp[i+j]);
            maxx=max(maxx,dp[i]);
        }
        return maxx;

        
    }
};

-----------------------------------------------------approach2-----------------------------------------------
  //time complexity:O(n)
  //space complexity:O(n)
  class Solution {
public:
    int rob(vector<int>& v) {
        int n=v.size();
        int dp[n];
        dp[n-1]=v[n-1];
        if(n==1) return v[0];
        for(int i=n-2;i>=0;i--)
        {
           if(i==n-2)
           dp[i]=max(v[i],v[i+1]);
           else if(i==n-3)
           dp[i]=max(v[i]+dp[i+2],dp[i+1]);
           else
           dp[i]=max(v[i]+dp[i+2],v[i]+dp[i+3]);    
        }
        return max(dp[0],dp[1]);

        
    }
};
