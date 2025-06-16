class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        // if(n==k){
        //     return "0";
        // }
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && (st.top()-'0')>(num[i]-'0') && k>0){
                st.pop(); 
                k--;
            }
            st.push(num[i]);
        }

        while(!st.empty() &&k>0){
            st.pop();
            k--;
        }
         string result="";  
          while(!st.empty()){
             result.push_back(st.top());
             st.pop();
          }
          reverse(result.begin(),result.end());
         
         int start = 0;
        while (start < result.size() && result[start] == '0') start++;
        result=result.substr(start);
        if (result.empty()) return "0";
        return result;
    }
};