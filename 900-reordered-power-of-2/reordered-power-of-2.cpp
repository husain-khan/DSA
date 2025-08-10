class Solution {
public:
    bool reorderedPowerOf2(int n) {
    string s=to_string(n);
    sort(s.begin(),s.end());
     unordered_set<string> storage;
     for(int i=1;i<1e9;i=i*2){
        string temp=to_string(i);
        sort(temp.begin(),temp.end());
        storage.insert(temp);
     }

     
     return storage.count(s);   
    }
};