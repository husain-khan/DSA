class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posCount = 0; // Count of positive integers
        int negCount = 0; // Count of negative integers
        
        for (int num : nums) {
            if (num > 0) {
                posCount++;
            } else if (num < 0) {
                negCount++;
            }
        }
        
        return max(posCount, negCount);
    }
};
