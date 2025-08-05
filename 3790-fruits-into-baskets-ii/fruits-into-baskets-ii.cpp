class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int fsize = fruits.size();
        int bsize = baskets.size();              // Fix here

        int count = 0;
        vector<bool> booli(bsize, true);         // Fix here

        for (int i = 0; i < fsize; i++) {
            for (int j = 0; j < bsize; j++) {
                if (fruits[i] <= baskets[j] && booli[j]) {
                    count++;
                    booli[j] = false;
                    break;
                }
            }
        }
        
        cout << count << endl;
        return fsize - count;
    }
};
