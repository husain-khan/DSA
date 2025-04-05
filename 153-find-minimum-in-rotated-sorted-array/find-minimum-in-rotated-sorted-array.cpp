class Solution {
public:
    int findMin(vector<int>& nums) {

        int low=0;
        int high=nums.size()-1;
        int min=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]<min){
                min=nums[mid];
            }

            if(nums[mid]<nums[low]){
                if(nums[high]>min && nums[mid]<min){
                    low=mid+1;
                }
                else{
                high=mid-1;
            }

         }
          else { //if right part is sorted:
            if (nums[mid] <= min && min <= nums[high]) {
                //element exists:
                high = mid - 1;
                
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
            
        }
        return min;
        
    }
};