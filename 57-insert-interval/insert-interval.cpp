class Solution {
public:
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> newvec = intervals;
    newvec.push_back(newInterval);

    sort(newvec.begin(), newvec.end()); // sorted by start

    vector<vector<int>> ans;
    vector<int> curr = newvec[0];

    for (int i = 1; i < newvec.size(); i++) {
        if (curr[1] >= newvec[i][0]) { 
            // overlap
            curr[1] = max(curr[1], newvec[i][1]);
        } else {
            ans.push_back(curr);
            curr = newvec[i];
        }
    }
    ans.push_back(curr);
    return ans;
}
};