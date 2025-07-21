class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        for(char c : s) {
            int len = ans.size();
            // Only add c if the last two chars in ans are NOT both equal to c
            if(len >= 2 && ans[len-1] == c && ans[len-2] == c) {
                continue; // Skip adding this char
            }
            ans.push_back(c); // Otherwise, add it
        }
        return ans;
    }
};
