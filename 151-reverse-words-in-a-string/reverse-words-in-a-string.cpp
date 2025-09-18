class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = n - 1;
        string word;
        string ans;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') i--;

        while (i >= 0) {
            if (s[i] != ' ') {
                word.push_back(s[i]);
                i--;
            } else {
                // Reverse the collected word and append to ans
                reverse(word.begin(), word.end());
                ans.append(word);
                ans.push_back(' ');
                word.clear();

                // Skip spaces between words
                while (i >= 0 && s[i] == ' ') i--;
            }
        }

        // Append last word if any
        if (!word.empty()) {
            reverse(word.begin(), word.end());
            ans.append(word);
        } else if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();  // Remove trailing space if needed
        }

        return ans;
    }
};
