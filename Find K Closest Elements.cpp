/*Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104*/
using heap
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxh;
        vector<int>v;
        for(const auto& value:arr)
        {
            maxh.push(make_pair(abs(value-x),value));
            if(maxh.size()>k)
            maxh.pop();
        }
        while(!maxh.empty())
        {
            v.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(v.begin(),v.end());
    return v;
    
    }
};
------------------------------------------------------------------------------
  using map
  class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        multimap<int,int>m;
        vector<int>v;
        for(const auto &value:arr)
        m.insert(pair<int,int>(abs(value-x),value));
        
       for(auto it=m.begin();it!=m.end(),k>0;it++,k--)
        v.push_back(it->second);
        sort(v.begin(),v.end());
        return v;
        
    }
};
