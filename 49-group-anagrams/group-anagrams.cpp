class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>> mapp;

        for(auto it:strs){

            string tempsorted=it;
            sort(tempsorted.begin(),tempsorted.end());

            mapp[tempsorted].push_back(it);
        }
        vector<vector<string>>ans;
        for(auto it:mapp){
                ans.push_back(it.second);
           }
        return ans;
        
    }
};