import pandas as pd

class Solution(object):

    # time limit exceeded
    # dynamic programing
    def longestPalindrome2(self, s):
        slen = len(s)
        mat = [[False] * slen for i in xrange(slen)]
        max_len = 1
        max_start = 0
        for i in xrange(slen):
            mat[i][i] = True
        for i in xrange(slen-1):
            if s[i] == s[i+1]:
                mat[i+1][i] = True
                max_start = i
                max_len = 2

        for deta in xrange(2, slen):
            for i in xrange(deta, slen):
                #mat[i][i-deta]
                if (s[i] == s[i-deta]) and (mat[i-1][i-deta+1]):
                    mat[i][i-deta] = True
                    max_start = i - deta
                    max_len = deta
        return s[max_start : max_len]

    # from the center
    def longestPalindrome(self, s):
        longest = s[0]
        for i in xrange(len(s)):
            cur = self.get_from_center(s, i, i)
            if len(cur) > len(longest):
                longest = cur
            cur = self.get_from_center(s, i, i+1)
            if len(cur) > len(longest):
                longest = cur
        return longest

    def get_from_center(self, s, begin, end):
        while begin >= 0 and end < len(s) and s[begin]==s[end]:
            begin -= 1
            end += 1
        return s[begin+1 : end]

if __name__ == '__main__':
    so = Solution()
    s = 'bbbb'
    print so.longestPalindrome(s)



