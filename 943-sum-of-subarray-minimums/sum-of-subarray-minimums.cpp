class Solution {
public:

    int next_smallest_element(vector<int>& num,int element,int index,int siz){
       int count=1;
       for(int i=index+1;i<siz;i++){
        if(num[i]<=element){
            break;
        }
            count++;
       }
       return count;
    }
      
  int previous_smallest_element(vector<int>& num,int element,int index,int siz){
       int count=1;
       for(int i=index-1;i>=0;i--){
        if(num[i]<element){
            break;
        }
            count++;
                  
       }
    
       return count;
    }
          
    int sumSubarrayMins(vector<int>& arr) {
        long long total=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
           
           int right=next_smallest_element(arr,arr[i],i,n);
           int left=previous_smallest_element(arr,arr[i],i,n);
          total = (total + (long long)arr[i] * left * right) % 1000000007;
        }
        return total;
    }
};