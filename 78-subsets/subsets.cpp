class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;  // To store all subsets
        vector<int> subset;         // Temporary subset
        backtrack(0, nums, subset, result);
        return result;
    }
    
private:
    void backtrack(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(subset);
        
        // Explore further subsets
        for (int i = index; i < nums.size(); ++i) {
            subset.push_back(nums[i]);  // Include nums[i] in the subset
            backtrack(i + 1, nums, subset, result);  // Recur for the next elements
            subset.pop_back();  // Backtrack: remove nums[i] from the subset
        }
    }
};
