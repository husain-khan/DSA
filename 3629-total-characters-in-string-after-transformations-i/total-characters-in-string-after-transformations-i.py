MOD = 10**9 + 7

class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        dp_prev = [1] * 26  # Base case: each character contributes 1 at t=0
        
        for _ in range(t):
            dp_current = [0] * 26
            for c in range(26):
                if c == 25:
                    # 'z' transforms to 'a' and 'b', sum their contributions from previous step
                    dp_current[c] = (dp_prev[0] + dp_prev[1]) % MOD
                else:
                    # Other characters transform to next character, take its contribution from previous step
                    dp_current[c] = dp_prev[c + 1] % MOD
            dp_prev = dp_current
        
        total = 0
        for ch in s:
            total = (total + dp_prev[ord(ch) - ord('a')]) % MOD
        
        return total
