/*Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1*/
---------------------------------------------------------------approach1---------------------------------
  //time complexity:O(sqrt(n))
  //space complexity:O(1)
class Solution {
public:
    int mySqrt(int n) {
        long long i=0;
        while(n>=0)
        {
           if(n>=i*i)
           i++;
           else
           return --i;
        }
        return 0;
    }
};
-----------------------------------------------------------------approach2-------------------------------------
  //time complexity:O(logn)
  //space complexity:O(1)
  class Solution {
public:
    int binaryy(int x ,int s,int e)
    {
        long long mid=s+(e-s)/2;
        if(s>e)
        return mid-1;
        if(x==mid*mid)
        return mid;
        else if(x>mid*mid)
        return binaryy(x,mid+1,e);
        else
        return binaryy(x,s,mid-1);
    }
    int mySqrt(int n) {
        return binaryy(n,1,n);
    }
};
