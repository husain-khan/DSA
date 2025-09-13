class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mapp;
         for(char c:s){
            mapp[c]++;
        }
        
         int ansvow=0;
         int anscon=0;
        for(auto it:mapp){
            if(it.first=='a'||it.first=='e'||it.first=='i'||it.first=='o'||it.first=='u'){
               if(it.second > ansvow){
                ansvow=it.second;
                }  
            }
            else{
                if(it.second > anscon){
                anscon=it.second;
                }  
            }
        }
        return  ansvow+anscon;
        
    }
};