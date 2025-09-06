#define ll long long
class Solution {
public:
    ll get(int x){ // 1 to x => ops for all the nums
        int cur = 1;
        ll res = 0, mul = 1;
        while(cur <= x){
            ll nxt = min(cur*4 , x+1);
            ll cnt = nxt - cur;
            res += (cnt*mul); mul++;
            cur = nxt;
        }
        return res;
    }
    long long minOperations(vector<vector<int>>& queries) {
        ll ans = 0;
        for(auto &q : queries){
            ll cnt = (get(q[1]) - get(q[0]-1)); // cnt = 5 -> ans = 3 , cnt = 6 -> ans = 3; 
            ans += (cnt+1)/2;
        }
        return ans;
    }
};