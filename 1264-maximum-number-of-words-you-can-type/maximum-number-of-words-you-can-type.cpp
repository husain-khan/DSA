#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        map<char, int> mapp;
        for (char c : brokenLetters) {
            mapp[c]++;
        }

        int count = 0;
        bool canType = true;
        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                if (canType) count++;
                canType = true;
            } else {
                if (mapp.count(text[i])) {
                    canType = false;
                }
            }
        }
        return count;
    }
};
