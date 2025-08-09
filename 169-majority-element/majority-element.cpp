#include<bits/stdc++.h>
#include <algorithm> 
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
         if (n == 0) return -1;
        std::sort(nums.begin(), nums.end());
        
        int maxelement =nums[0];
        int count=1;
        int maxcount=1;
        for(int i=0;i<nums.size()-1;i++){
           if (nums[i] == nums[i + 1]) {
                count++;
            } else {
                count = 1;
            }

            if (count > maxcount) {
                maxcount = count;
                maxelement = nums[i];
            }
        }
        return maxelement;
    }
};