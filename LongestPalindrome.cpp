/*Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.*/
//time complexity:O(n)
//space compexity:O(m) (m<=n)
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>m;
        for(auto value:s)
        {
            if(m.find(value)==m.end())
            m[value]=1;
            else
            m[value]++;
        }
        int ans=0;
        int p=false;
        for(auto value:m)
        {
            if(value.second%2==0)
            ans=ans+value.second;
            else
            {
                ans=ans+value.second-1;
                p=true;
            }

        }
        if(p)
        ans++;
        return ans;
        
    }
};
