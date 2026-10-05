class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        n=len(nums)
        maxi=nums[0]
        sum=0
        for i in range(n):
            sum+=nums[i]
            maxi=max(maxi,sum)
            if sum<0:
                sum=0

        return maxi