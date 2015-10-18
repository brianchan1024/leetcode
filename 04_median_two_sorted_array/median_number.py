
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        #return float
        lenn1 = len(nums1)
        lenn2 = len(nums2)
        if ((lenn1 + lenn2) % 2 == 0):
            return float(self.fms(nums1, nums2, (lenn1 + lenn2) / 2)
                   + self.fms(nums1, nums2, (lenn1 + lenn2) / 2 + 1)) / 2
        else:
            return self.fms(nums1, nums2, (lenn1 + lenn2) / 2 + 1)
        
    def fms(self, nums1, nums2, k):
        if len(nums1) > len(nums2):
            return self.fms(nums2, nums1, k)
        if len(nums1) == 0:
            return nums2[k-1]
        if k == 1:
            return min(nums1[0], nums2[0])

        dlen = min(k/2, len(nums1))
        if nums1[dlen - 1] <= nums2[dlen - 1]:
            return self.fms(nums1[dlen:], nums2, k - dlen)
        else:
            return self.fms(nums1, nums2[dlen:], k - dlen)

if __name__ == '__main__':
    nums1 = [5]
    nums2 = [2,4,6,8,10]

    so = Solution()
    print so.findMedianSortedArrays(nums1, nums2)


