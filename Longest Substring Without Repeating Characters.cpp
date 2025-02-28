#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string temp = "", maxStr = "";
        int k = 0;  // Start pointer
        
        for (int i = 0; i < s.length(); i++) {
            size_t found = temp.find(s[i]); // Check if s[i] exists in temp
            
            if (found != string::npos) { // If duplicate found
                if (temp.length() > maxStr.length()) { 
                    maxStr = temp; // Update max string
                }
                k++; // Move start index forward
                temp.clear();
                i = k - 1; // Restart checking from new start
            } else {
                temp += s[i]; // Add character to temp
            }
        }

        // Check one last time after loop ends
        if (temp.length() > maxStr.length()) {
            maxStr = temp;
        }

        return maxStr.length();
    }
};
