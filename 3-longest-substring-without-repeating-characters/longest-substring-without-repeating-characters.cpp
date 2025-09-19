class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;

        int ans=0;
        unordered_map<char,int>map;

        while(right<s.size()){

            map[s[right]]++;

            while(map[s[right]]>1){
                map[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};