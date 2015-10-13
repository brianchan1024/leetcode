#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int max_len = 0;
        map<char, int> hmap;
        for(int idx = 0; idx < s.length(); idx++) {
            hmap[s[idx]] = -1;
        }

        for(int idx = 0; idx < s.length(); idx++) {
            if (hmap[s[idx]] != -1) {
                while(start <= hmap[s[idx]]) {
                    hmap[s[start]] = -1;
                    start += 1;
                }
            }
            hmap[s[idx]] = idx;
            max_len = max(max_len, idx - start + 1);
        }
        return max_len;
    }
};

int main()
{
    Solution so = Solution();
    int max_len = so.lengthOfLongestSubstring("abcdeahbdfd");
    cout << max_len << endl;
    return 0;
}
