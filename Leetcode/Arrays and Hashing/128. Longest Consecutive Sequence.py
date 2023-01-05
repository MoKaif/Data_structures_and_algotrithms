class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        myset = set(nums)

        count = 0
        for i in nums:
            if (i-1) not in myset:
                length = 0
                while(i+length) in myset:
                    length+=1
                count = max(count, length) 
        return count