#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        // Define the binary search range
        int left = 0, right = *max_element(candies.begin(), candies.end());
        
        // Perform binary search
        while (left < right) {
            int mid = (left + right + 1) / 2;
            long long count = 0;
            
            // Calculate how many children can be served with `mid` candies each
            for (int candy : candies) {
                count += candy / mid;
            }
            
            // Check if we can serve at least `k` children
            if (count >= k) {
                left = mid;  // Increase the lower bound
            } else {
                right = mid - 1;  // Decrease the upper bound
            }
        }
        
        return left;
    }
};
