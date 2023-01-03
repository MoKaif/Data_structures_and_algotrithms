class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        count = {}
        freq = [[] for i in range(len(nums) + 1)]
        # print(freq)/

        for n in nums:
            count[n] = 1 + count.get(n, 0)
        # print(count)
        for n,c in count.items():
            # print(n)
            # print('-')
            # print(c)
            freq[c].append(n)
        res = []
        for i in range(len(freq)-1, 0 ,-1):
            for n in freq[i]:
                res.append(n)
                if len(res) == k:
                    return res
        # return []
        