#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    // Helper function to check if the number is positive or zero
    bool check_if_positive(int number){
        return number >= 0;
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            // If the asteroid is moving right (positive), push it onto the stack
            if (check_if_positive(asteroids[i])) {
                st.push(asteroids[i]);
            } else {
                // Process collisions only when stack is not empty and the top is a right-moving asteroid
                while (!st.empty() && st.top() > 0 && abs(asteroids[i]) > st.top()) {
                    st.pop(); // Pop the smaller right-moving asteroid
                }
                // If both asteroids are the same size and opposite directions, destroy both
                if (!st.empty() && st.top() > 0 && abs(asteroids[i]) == st.top()) {
                    st.pop(); // Remove the right-moving asteroid
                    // Do not push the current left-moving asteroid (both destroyed)
                    // 'break' here ensures we stop processing the current asteroid
                    // as it is also destroyed
                    // (No need to push anything or continue further)
                    continue;
                }
                // If no collision, or top is left-moving, push the current asteroid
                if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
                // If the stack top is positive and larger, do nothing (current asteroid destroyed)
                // No explicit action needed
            }
        }
        // Transfer stack contents to result vector (in reverse order)
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        std::reverse(ans.begin(), ans.end()); // Restore correct order
        return ans;
    }
};
