/*
539. Minimum Time Difference
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.

 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1

Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0

 

Constraints:

    2 <= timePoints.length <= 2 * 104
    timePoints[i] is in the format "HH:MM".
*/
class Solution {
public:
    int findMinDifference(vector<string>& time) {
        vector<int>v;
        for(auto it:time){
            string a=it.substr(0, 2), b=it.substr(3, 2);
            int h=stoi(a), m=stoi(b);
            v.push_back(h*60+m);
        }
        sort(v.begin(), v.end());
        int ans=INT_MAX;
        for(int i=1;i<v.size();i++) ans=min(ans, v[i]-v[i-1]);
        ans=min(ans, 1440-v[v.size()-1]+v[0]);
        return ans;
    }
};
