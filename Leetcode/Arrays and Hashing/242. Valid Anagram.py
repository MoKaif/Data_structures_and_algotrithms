class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
           return False
        ssort = sorted(s)
        tsort = sorted(t)
        if ssort != tsort:
            return False
        else:
            return True