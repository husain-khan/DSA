class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // ❌ wrong type here
        // vector<vector<int,int>> newvec;
        // ✅ should be just vector<vector<int>>
        vector<vector<int>> newvec = intervals;  

        newvec.push_back(newInterval);
        sort(newvec.begin(), newvec.end());  // ✅ this works fine

        vector<vector<int>> ans;  // ✅ you need this to store result

        // ❌ you didn't declare nis, nie
        int nis = newvec[0][0];  
        int nie = newvec[0][1];

        for (int i = 1; i < newvec.size(); i++) {
            // check overlap
            if (newvec[i][0] <= nie) {
                // merge
                nie = max(nie, newvec[i][1]);
            } else {
                // push previous merged interval
                ans.push_back({nis, nie});
                // start new interval
                nis = newvec[i][0];
                nie = newvec[i][1];
            }
        }

        // push last interval
        ans.push_back({nis, nie});
        return ans;
    }
};
