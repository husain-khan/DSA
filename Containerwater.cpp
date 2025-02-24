class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            // Calculate the area
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, area);

            // Move the pointer of the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};
