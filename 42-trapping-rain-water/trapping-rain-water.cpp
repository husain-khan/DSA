class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();
        vector<int> right(n);
        right[n-1]=height[n-1];
     
        for(int i=n-2;i>=0;i--){
         right[i]=max(right[i+1],height[i]);
        }
       int leftmax=0;
       int total=0;
      for(int i=0;i<n;i++){
          if(height[i]> leftmax){
            leftmax=height[i];
          }
          int rightmax=right[i];
          total=total+min(leftmax,rightmax)-height[i];

      }   

        return total;
    }
};