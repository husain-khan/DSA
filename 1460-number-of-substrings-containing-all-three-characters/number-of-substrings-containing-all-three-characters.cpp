class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0; // Initialize the count of substrings
        unordered_map<char, int> d; // Dictionary to store the latest index for 'a', 'b', and 'c'
        
        // Initialize the dictionary with -1 for 'a', 'b', and 'c'
        d['a'] = d['b'] = d['c'] = -1;
        
        for (int i = 0; i < s.size(); ++i) {
            // Update the latest index for the character at position i
            d[s[i]] = i;
            
            // Calculate the number of substrings ending at the current index i
            // The minimum index among 'a', 'b', and 'c' plus one gives the count
            ans += min({d['a'], d['b'], d['c']}) + 1;
        }
        
        return ans;
    }
};
