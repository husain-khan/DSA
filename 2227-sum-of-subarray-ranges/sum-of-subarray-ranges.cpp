#include<bits/stdc++.h>
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
     for (int i = 0; i < n; i++) {
    long long maxi = nums[i]; // Initialize to current element
    long long mini = nums[i]; // Initialize to current element
    for (int j = i; j < n; j++) {
        maxi = std::max(maxi, static_cast<long long>(nums[j]));
        mini = std::min(mini, static_cast<long long>(nums[j]));
        sum += (maxi - mini);
    }
}

        return sum;
    }
};