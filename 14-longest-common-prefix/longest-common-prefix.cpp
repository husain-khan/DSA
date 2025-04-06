#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // Return empty string if input is empty

        // Start with the first string as a reference
        string prefix = strs[0];

        // Compare with each string in the array
        for (int i = 1; i < strs.size(); i++) {
            // Update prefix by comparing with current string
            while (strs[i].find(prefix) != 0) { // While current prefix is not a prefix of strs[i]
                prefix = prefix.substr(0, prefix.size() - 1); // Reduce prefix by one character
                if (prefix.empty()) return ""; // Return empty if no common prefix
            }
        }

        return prefix; // Return the longest common prefix found
    }
};

// Example usage
