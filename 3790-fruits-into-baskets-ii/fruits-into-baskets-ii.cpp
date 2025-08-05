class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int fsize=fruits.size();
        int bsize=baskets.size();
        int count=0;
        vector<bool>booli(bsize,true);
        for(int i=0;i<fsize;i++){
            for(int j=0;j<bsize;j++){
                if(fruits[i]<=baskets[j] && booli[j]==true){
                    count++;
                    booli[j]=false;
                    break;
                }
            }
        }
        cout<<count;
        return fsize-count;
    }
};