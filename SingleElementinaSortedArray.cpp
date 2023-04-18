/*You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105*/
class Solution {
public:
    int solve(vector<int>&nums,int s,int e,int n)
    {
        int mid=s+(e-s)/2;
        if(s>e)
        return -1;
        if(mid-1>-1&&nums[mid]==nums[mid-1])
        return max(solve(nums,s,mid-2,n),solve(nums,mid+1,e,n));
        else if(mid+1<n&&nums[mid]==nums[mid+1])
        return max(solve(nums,mid+2,e,n),solve(nums,s,mid-1,n));
        return nums[mid];
    }
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,0,n-1,n);
        
    }
};
