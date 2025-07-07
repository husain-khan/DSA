class Solution {
public: 
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> str=nums;
        vector<int> opt;
        backtrack(str,0,opt);
        return ans;
    }


     void backtrack(vector<int>& nums, int index, vector<int>& op) {
    if (index == nums.size()) {
        ans.push_back(op);
        return;
    }

    // Exclude nums[index]
    backtrack(nums, index + 1, op);

    // Include nums[index]
    op.push_back(nums[index]);
    backtrack(nums, index + 1, op);
    op.pop_back();  // backtrack
}
};
