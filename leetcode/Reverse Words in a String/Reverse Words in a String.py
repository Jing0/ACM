class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        li = s.split(" ")
        ans = ""
        for w in li:
            if w != "":
                ans = w + " " + ans
        if ans[len(ans)-1:] == " ":
            return ans[:len(ans) - 1]
        return ans
