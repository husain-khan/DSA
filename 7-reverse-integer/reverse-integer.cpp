#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool check = x >= 0;
        long long ans = 0;
        vector<int> nums;

        long long val = x;
        val = abs(val);  // Use long long abs to avoid overflow with INT_MIN

        // Extract digits
        while (val / 10 != 0) {
            int t = val % 10;
            nums.push_back(t);
            val = val / 10;
        }
        nums.push_back(val);

        // Reconstruct reversed number with overflow check
        for (int i = 0; i < (int)nums.size(); ++i) {
            ans = ans * 10 + nums[i];
            if (ans > INT_MAX) return 0;
        }

        if (!check) ans = -ans;

        if (ans < INT_MIN || ans > INT_MAX) return 0;

        return (int)ans;
    }
};
