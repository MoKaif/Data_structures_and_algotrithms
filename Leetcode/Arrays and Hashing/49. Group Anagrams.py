class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        hmap = defaultdict(list) #list

        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1

            hmap[tuple(count)].append(s)
        
        print(hmap.values())
        return hmap.values()