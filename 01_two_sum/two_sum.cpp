#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    // time limit exceeded
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        for (int i = 0; i < numbers.size() - 1; i++) {
            for (int j = i + 1; j < numbers.size() - 1; j++) {
                if (numbers[i] + numbers[j] == target) {
                    res.push_back(i + 1);
                    res.push_back(j + 1);
                }
            }
        }
        return res;
    }

    vector<int> twoSum2(vector<int> nums, int target) {
        vector<int> res;
        map<int, int> hmap;
        hmap.clear();
        for (int i = 0; i < nums.size(); i++) {
            hmap[nums[i]] = i;
        }
        
        for (map<int, int>::const_iterator it = hmap.begin(); it != hmap.end(); ++it) {
        cout << it->first << ' ' << it->second << endl;
        }
        
        cout << "-------";

        for (int i=0; i < nums.size(); i++) {
            if (hmap.find((target - nums[i])) != hmap.end()) {
                if (i < hmap[target - nums[i]]) {
                    res.push_back(i + 1);
                    res.push_back(hmap[target - nums[i]] + 1);
                    return res;
                }
                if (i > hmap[target - nums[i]]) {
                    res.push_back(hmap[target - nums[i]] + 1);
                    res.push_back(i + 1);
                    return res;
                }
            }
        }
    }
};

int main()
{
    vector<int> numbers;
    numbers.push_back(0);
    numbers.push_back(4);
    numbers.push_back(3);
    numbers.push_back(0);

    int target = 0;

    Solution so = Solution();
    // vector<int> res = so.twoSum(numbers, target);
    vector<int> res = so.twoSum2(numbers, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}

