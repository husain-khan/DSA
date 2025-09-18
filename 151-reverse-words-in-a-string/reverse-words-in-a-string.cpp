class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;        
        int n=s.size();
        string ans;
        int i=0;
        string word;
        while (i < n && s[i] == ' ') i++;
        while(i<=n){
            
          if(i==n||s[i]==' '){
            if (!word.empty()){st.push(word);
            word="";
            }
          }
          else{
            
              word.push_back(s[i]);
          }

            i++;
        }

        while(!st.empty()){
            ans.append(st.top());
            st.pop();
            if(!st.empty()) ans.push_back(' ');
        }
        return ans;
    }
};