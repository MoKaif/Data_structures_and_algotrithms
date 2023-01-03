class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        output = [1] * len(nums)
        prefix = 1
        for i in range(len(nums)): #prefix
            output[i] = prefix
            prefix *= nums[i]

        postfix = 1
        for i in range(len(nums)-1, -1, -1): #postfix
            output[i] *= postfix
            postfix *= nums[i]
        return output