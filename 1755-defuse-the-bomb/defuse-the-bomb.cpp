class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        
        if (k == 0) {
            return result; // If k is 0, return all zeros
        }
        
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            
            if (k > 0) {
                // Sum the next k numbers
                for (int j = 1; j <= k; ++j) {
                    sum += code[(i + j) % n];
                }
            } else {
                // Sum the previous k numbers
                for (int j = 1; j <= -k; ++j) {
                    sum += code[(i - j + n) % n];
                }
            }
            
            result[i] = sum;
        }
        
        return result;
    }
};
