class Solution(object):

    # time limit exceeded
    def twoSum(self, nums, target):
        ndict = dict()
        for index, num in enumerate(nums):
            ndict[num] = index
        for key, value in enumerate(nums):
            # time limit exceeded
            # if (target - value) in ndict.keys():
            # should take advantage of dict hasp map to find the key
            if ndict.has_key(target - value):
                if ndict[target - value] < key:
                    return ndict[target - value] + 1, key + 1
                if ndict[target - value] > key:
                    return key + 1, ndict[target -value] + 1

if __name__ == '__main__':
    nums = [3, 2, 4]
    target = 6
    so = Solution()
    print so.twoSum(nums, target)
