class Solution {
public:
    int totalFruit(vector<int>& s) {
        int maxlength=0;
        int left=0;
        int right=0;
        unordered_map<int,int>map;

        while(right < s.size()){
            map[s[right]]++;

            if(map.size()>2){
                while(map.size()>2){
                    if(map[s[left]]) map[s[left]]--;
                    if(map[s[left]]==0){
                        map.erase(s[left]);
                    }
                    left++;
                }
            }
            
            maxlength = max(maxlength, right - left + 1);
            right++;
        }
        
        return maxlength;
    }
};