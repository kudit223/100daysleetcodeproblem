/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104*/
class Solution {
public:

    int binary(vector<int>v,int target,int r,int l)
    {
        int mid=(r+l+1)/2;
        if(l-r==1)
        {
            if(v[r]>=target)
            return r;
            else
            return l;
        }

        if(v[mid]==target)
        return mid;
        else if(v[mid]>target)
        return binary(v,target,r,mid);
        else 
        return binary(v,target,mid,l);
    }
    bool binaryy(vector<int>v,int target,int r,int l)
    {
        int mid=(r+l+1)/2;
        if(l-r==1)
        {
            if(v[r]==target)
            return true;
            else if(v[l]==target)
            return true;
            else
            return false;
        }

        if(v[mid]==target)
        return true;
        else if(v[mid]>target)
        return binaryy(v,target,r,mid);
        else 
        return binaryy(v,target,mid,l);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> v;
        for(int i=0;i<n;i++)
        v.push_back(matrix[i][m-1]);
        int r=0,l=n-1,a=0;
        if(v.size()>1)
        a=binary(v,target,r,l);
        cout<<a;
        v.clear();
        for(int i=0;i<m;i++)
        v.push_back(matrix[a][i]);
        int t=0,x=m-1;
        if(v.size()>1)
        return binaryy(v,target,t,x);
        else
        return v[0]==target?true:false;

        
    }
};
