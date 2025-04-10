#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(t.size()!=s.size()){return false;}


     unordered_map<char,int> charCountmap;

     for(char c: s){
        if(charCountmap.find(c)!=charCountmap.end()){
            charCountmap[c]++;

        }
        else{
            charCountmap[c]=1;
        }

     }
    for(char c: t){
        if(charCountmap.find(c)!=charCountmap.end()){
            charCountmap[c]--;

        }
        else{
            return false;
        }
        
     }
     for(auto& pair:charCountmap){
     if(pair.second!=0){
        return false;
     }
    }
       return true;
    }
};