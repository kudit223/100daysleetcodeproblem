
/*You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105*/
---------------------------------------------------------------approach1----------------------------------------------------
  //time complexity:O(n^2)
  //space complexity:O(n)
class Solution {
public:
    bool canJump(vector<int>& v) {
        int n=v.size();
        bool dp[n];
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--)
        for(int j=1;j<n-i;j++)
        {
            if(v[i]==0)
            dp[i]=false;
            else if(v[i]>=j&&dp[i+j]==true)
            {
                dp[i]=true;
                break;
            }
            dp[i]=false;
        }
        return dp[0];
        
    }
};
------------------------------------------------------approach2----------------------------------------------------------------------------------
  //time complexity:O(n)
  //space complexity:O(1)
  class Solution {
public:
    bool canJump(vector<int>& v) {
        
        int n=v.size();
        int j=1;
        for(int i=n-2;i>=0;i--)
        {
            if(v[i]>=j)
            j=1;
            else
            j++;
        }
        if(j!=1)
        return false;
        return true;
    }
};
