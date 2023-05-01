/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109*/
//time complexity:O(logn)
class Solution {
public:
    int solve1(vector<int>&v,int s,int e,int k,int &fpos)
    {
        int mid=s+(e-s)/2;
        if(s>e)
        return fpos;
        if(v[mid]==k)
        {
            fpos=mid;
            return solve1(v,s,mid-1,k,fpos);
        }
        if(v[mid]>k)
        return solve1(v,s,mid-1,k,fpos);
        return solve1(v,mid+1,e,k,fpos);
    }
    int solve2(vector<int>&v,int s,int e,int k,int &lpos)
    {
        int mid=s+(e-s)/2;
        if(s>e)
        return lpos;
        if(v[mid]==k)
        {
            lpos=mid;
            return solve2(v,mid+1,e,k,lpos);
        }
        if(v[mid]>k)
        return solve2(v,s,mid-1,k,lpos);
        return solve2(v,mid+1,e,k,lpos);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int fpos=-1,lpos=-1;
        solve1(nums,0,n-1,target,fpos);
        solve2(nums,0,n-1,target,lpos);
        return {fpos,lpos};

    }
};
