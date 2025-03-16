#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    long long repairCars(std::vector<int>& ranks, int cars) {
        // Binary search boundaries
        long long left = 0, right = 1LL * *std::min_element(ranks.begin(), ranks.end()) * cars * cars;

        while (left < right) {
            long long mid = (left + right) / 2;
            long long count = 0;

            // Calculate the number of cars each mechanic can repair in 'mid' time
            for (int rank : ranks) {
                count += std::sqrt(mid / rank);
            }

            // Check if the current time allows repairing all cars
            if (count >= cars) {
                right = mid; // Reduce the upper bound
            } else {
                left = mid + 1; // Increase the lower bound
            }
        }

        return left; // Minimum time needed to repair all cars
    }
};
