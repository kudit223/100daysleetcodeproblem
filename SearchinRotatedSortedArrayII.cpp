/*There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
 

Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?*/
//time complexity:O(logn)
//space complexity:O(1)
class Solution {
public:
    int binaryy(vector<int>&v,int mn,int s,int e)
    {
        int mid=s+(e-s)/2;
        if(s>e)
        return mn;
        if(v[mid]>v[mn])
        return binaryy(v,mn,mid+1,e);
        else
        {
            mn=mid;
            return binaryy(v,mn,s,mid-1);
        }
    }
    bool solve(vector<int>&v,int s,int e,int &k)
    {
        int mid=s+(e-s)/2;
        if(s>e)
        return false;
        if(k==v[mid])
        return true;
        if(v[mid]>k)
        return solve(v,s,mid-1,k);
        return solve(v,mid+1,e,k);
    }
    bool search(vector<int>&v, int &k) {
        int n=v.size();
        int mn=0;
        int i=1,j=n-1;
        while(i<j)
        {
          if(v[mn]==v[j])
          j--;
          else if(v[mn]==v[i])
          i++;
          else 
          break;

        }
        int mnindex= binaryy(v,mn,i,j);
        cout<<mnindex<<i<<" "<<j;
        return solve(v,i-1,mnindex-1,k)||solve(v,mnindex,j,k);
    }
};
