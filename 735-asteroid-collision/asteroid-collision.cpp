#include <vector>
#include <algorithm>
class Solution {
public:

    bool check_if_positive(int number){
        if(number>=0){
            return true;
        }
        else{
            return false;
        }
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        vector<int> ans;

        for(int i=0;i<n;i++){

            // bool ;

            if(check_if_positive(asteroids[i])){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top()>0 && abs(asteroids[i])>st.top()){
                    st.pop();
                }
                if(!st.empty() && st.top()>0 && abs(asteroids[i])==st.top()){
                    st.pop();
                    continue;
                }

                if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                }    
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

