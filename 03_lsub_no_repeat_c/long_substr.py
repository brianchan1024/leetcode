class Solution(object):
    def lengthOfLongestSubstring(self, s):
        start = 0
        max_len = 0
        hmap = {}
        for ch in s:
            hmap[ch] = -1
        for idx in xrange(len(s)):
            if hmap[s[idx]] != -1:
                while start <= hmap[s[idx]]:
                    hmap[s[start]] = -1
                    start += 1
            hmap[s[idx]] = idx
            if idx - start + 1 > max_len:
                max_len = idx - start + 1
        return max_len

if __name__ == '__main__':
    s = 'abcdeaghijklm'
    so = Solution()
    print so.lengthOfLongestSubstring(s)




