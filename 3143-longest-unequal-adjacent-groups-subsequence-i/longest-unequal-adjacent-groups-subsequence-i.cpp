class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
         vector<string> ans;
    int groupId = -1;
    int n=words.size();

    for (int i = 0; i < n; ++i)
      if (groups[i] != groupId) {
        groupId = groups[i];
        ans.push_back(words[i]);
      }

    return ans;
    }
};