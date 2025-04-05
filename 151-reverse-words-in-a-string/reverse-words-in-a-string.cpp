#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.length();
        int i = 0;
        
        // Extract words from the string
        while (i < n) {
            // Skip leading spaces
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;
            
            // Find the end of the current word
            int j = i;
            while (j < n && s[j] != ' ') j++;
            
            // Extract and store the word
            words.push_back(s.substr(i, j - i));
            i = j;
        }
        
        // Reverse the order of words
        reverse(words.begin(), words.end());
        
        // Construct the result string
        string result;
        for (int k = 0; k < words.size(); ++k) {
            if (k > 0) result += " ";
            result += words[k];
        }
        
        return result;
    }
};
