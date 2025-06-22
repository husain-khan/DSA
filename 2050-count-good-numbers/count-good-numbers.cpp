class Solution {
public:

    long long myPow(long long x, long long n, int MODD) {
        if (n == 0) return 1;
        long long half = myPow((x * x) % MODD, n / 2, MODD);
        if (n % 2 == 1) {
            return (x % MODD * half) % MODD;
        } else {
            return half % MODD;
        }
    }

    int countGoodNumbers(long long n) {
        const int MOD = 1000000007;
        // Number of even positions = (n + 1) / 2
        // Number of odd positions = n / 2
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;

        long long pow5 = myPow(5, even_positions, MOD);
        long long pow4 = myPow(4, odd_positions, MOD);

        return (pow5 * pow4) % MOD;
    }
};
