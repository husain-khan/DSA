class Solution {
public:
    bool isValid(string s) {
        stack<char> st;


        int i = 0;
    while (i < s.size()) {
      char c = s[i];
        if(c=='(' ||c=='['||c=='{'){
            st.push(c);
        }
        else{
             if(st.empty()){
            return false;
        }
            
            if(st.top()=='(' && c==')'){
                st.pop();
            }
            else if(st.top()=='[' && c==']'){
                st.pop();
            }
            else if(st.top()=='{' && c=='}'){
                st.pop();
            }
            else{
                return false;
            }
        }
        
       i++;
      }
      if(st.empty()){
            return true;
        }
        else{
            return false;
        }



    }
};