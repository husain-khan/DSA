class Solution {
public:
    bool isPowerOfThree(int n) {
        unordered_map<long long,long long> store;

        // #include <climits>
for (long long i = 3; i <= LLONG_MAX / 3; i *= 3) {
    store[i]++;
}


       if (store.count(n)||n==1) {
    // Key exists
    return true;
} else {
    return false;
    // Key does not exist
}

        
    }
};