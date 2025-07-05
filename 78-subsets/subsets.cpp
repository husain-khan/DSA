#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;  // member variable to store all subsets
    
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();            // clear previous results if any
        vector<int> current;    // temporary vector to build subsets
        backtrack(nums, 0, current);
        return ans;             // return the updated ans
    }
    
private:
    void backtrack(const vector<int>& nums, int index, vector<int>& current) {
        if (index == nums.size()) {
            ans.push_back(current);  // update member variable here
            return;
        }
        
        // Exclude nums[index]
        backtrack(nums, index + 1, current);
        
        // Include nums[index]
        current.push_back(nums[index]);
        backtrack(nums, index + 1, current);
        current.pop_back();  // backtrack
    }
};
