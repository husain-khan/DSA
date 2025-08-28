class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return {};  // edge case

        sort(intervals.begin(), intervals.end()); // sort by start time

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);  // first interval in ans
        int l_i = 0; // index of last inserted interval in ans

        for(int i = 1; i < n; i++) {   // start from 1 since 0 is already in ans
            if(intervals[i][0] <= ans[l_i][1]) {
                // merge with the last interval
                ans[l_i][1] = max(ans[l_i][1], intervals[i][1]);
            } else {
                // no overlap → add new interval
                ans.push_back(intervals[i]);
                l_i++;
            }
        }
        return ans;
    }
};
