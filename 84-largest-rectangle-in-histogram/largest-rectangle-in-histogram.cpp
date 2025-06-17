class Solution {
public:
   vector<int> PreviousSmallerElement(vector<int>& arr,int size){
    stack<int> st;
    vector<int> result(size);
           for(int i=0;i<size;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            if(st.empty()){
                result[i]=-1;
                }
            else{
                result[i]=st.top();
            }

            st.push(i);
           }
           return result;
   }
    vector<int> NextSmallerElement(vector<int>& arr,int size){
    stack<int> st;
    vector<int> result(size);
           for(int i=size-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            if(st.empty()){
                result[i]=size;
                }
            else{
                result[i]=st.top();
            }

            st.push(i);
           }
           return result;
   }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
       vector<int>pse= PreviousSmallerElement(heights,n);
       vector<int>nse= NextSmallerElement(heights,n);
      int ans=0;
    for(int i=0;i<n;i++){
        cout<<nse[i];
    }
        for(int i=0;i<=n-1;i++){
            ans=max(ans,heights[i]*(nse[i]-pse[i]-1));
        }
        return ans;
    }
};