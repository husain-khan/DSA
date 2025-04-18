#include<stdio.h>
#include<bits/stdc++.h>
class Solution {
public:
    string frequencySort(string s) {

        vector<int> freq(128);
        vector<vector<char>> charlist_under_count(s.size()+1);
        string ans;
        for (auto c : s) {
            int temp = int(c);
            freq[temp]++;
        }
        cout << freq[98];

        for(int i=0;i<128;i++){

            if(freq[i]>0){
                charlist_under_count[freq[i]].push_back(char(i));
            }
        }
        int x=charlist_under_count.size();

         for(int i=x-1;i>0;i--){
            for(char c:charlist_under_count[i]){
            ans=ans+string(i,c);
            }
         }   

         


        return ans;
    }
};