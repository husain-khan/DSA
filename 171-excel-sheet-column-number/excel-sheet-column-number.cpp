class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        
        for (char c : columnTitle) {
            // Convert the character to its corresponding number (A=1, B=2, ..., Z=26)
            int digit = c - 'A' + 1;
            
            // Multiply the current result by 26 (base) and add the new digit
            result = result * 26 + digit;
        }
        
        return result;
    }
};
