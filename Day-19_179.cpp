/*
179. Largest Number
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"

Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"

 

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 109

*/
class Solution {
public:
    static bool comp(int &a, int &b) {
        string s = to_string(a), p = to_string(b);
        return s + p > p + s;   
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);

        string ans = "";
        for (auto it : nums) {
            ans += to_string(it); 
        }
        if(ans[0]=='0') return "0";
        return ans;
    }
};

