#include <iostream>
#include <cctype> 
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        return recursivecheck(s,start,end);
        
    }

    bool recursivecheck(string &s,int start,int end){
        if(start>=end){  
            return true;
        }
        if(!isalnum(s[start])){
            return recursivecheck(s,start+1,end);
        }
        if(!isalnum(s[end])){
            return recursivecheck(s,start,end-1);
        }
         if(tolower(s[start])!=tolower(s[end])){
                return false;
             }

        if(tolower(s[start])==tolower(s[end])){
           return recursivecheck(s,start+1,end-1);
        }
        return true;
    }
};