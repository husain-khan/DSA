class Solution {
public:

   int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<int> s;

    // Previous Less
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
        left[i] = s.empty() ? i + 1 : i - s.top();
        s.push(i);
    }

    // Clear stack for next phase
    while (!s.empty()) s.pop();

    // Next Less or Equal
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
        right[i] = s.empty() ? n - i : s.top() - i;
        s.push(i);
    }

    // Calculate result
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res = (res + (long long)arr[i] * left[i] * right[i]) % 1000000007;
    }
    return res;
}

};