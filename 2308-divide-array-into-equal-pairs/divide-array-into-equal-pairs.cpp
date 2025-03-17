class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Create a frequency map
        unordered_map<int, int> freqMap;
        
        // Count the frequency of each number
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // Check if each number's frequency is even
        for (auto& pair : freqMap) {
            if (pair.second % 2 != 0) {
                return false; // If any number's frequency is odd, return false
            }
        }
        
        return true; // If all numbers have even frequencies, return true
    }
};
