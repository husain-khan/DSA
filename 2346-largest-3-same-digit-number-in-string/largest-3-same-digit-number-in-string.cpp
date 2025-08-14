class Solution {
public:
    string largestGoodInteger(string num) {
        int bestDigit = -1;  // track the digit (0..9)

        for (int i = 0; i <= 9; ++i) {
            string c = to_string(i);
            size_t pos = num.find(c);
            while (pos != string::npos) {
                size_t j = pos;
                int cnt = 1;

                // count run length of the same digit
                while (j + 1 < num.size() && num[j] == num[j + 1]) {
                    ++cnt;
                    ++j;
                }

                if (cnt >= 3) bestDigit = max(bestDigit, i);

                // jump to search after this run
                pos = num.find(c, j + 1);
            }
        }

        if (bestDigit == -1) return "";
        return string(3, char('0' + bestDigit));  // preserves "000"
    }
};
