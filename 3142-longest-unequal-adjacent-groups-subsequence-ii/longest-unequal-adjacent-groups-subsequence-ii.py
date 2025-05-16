class Solution(object):
    def getWordsInLongestSubsequence(self, words, groups):
        """
        :type words: List[str]
        :type groups: List[int]
        :rtype: List[str]
        """
        def hamming_distance(s1, s2):
            # Count positions where characters differ
            return sum(c1 != c2 for c1, c2 in zip(s1, s2))

        n = len(words)
        # dp[i] will store the list of indices forming the longest valid subsequence ending at i
        dp = [[i] for i in range(n)]

        for i in range(n):
            for j in range(i):
                if groups[i] != groups[j] and len(words[i]) == len(words[j]) and hamming_distance(words[i], words[j]) == 1:
                    if len(dp[j]) + 1 > len(dp[i]):
                        dp[i] = dp[j] + [i]

        # Find the longest subsequence among all dp[i]
        longest_subseq_indices = max(dp, key=len)
        return [words[i] for i in longest_subseq_indices]
