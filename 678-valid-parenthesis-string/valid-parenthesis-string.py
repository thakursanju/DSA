class Solution(object):

    def dr(self ,i,j,dp,s,n):
        if j<0:
            return False
        if i==n:
            return j==0
        if dp[i][j]!=-1:
            return dp[i][j]
        if s[i]=='(':
            dp[i][j]=self.dr(i+1,j+1,dp,s,n)
            
        elif s[i]==')':
            dp[i][j]=self.dr(i+1,j-1,dp,s,n)
            
        else:
             dp[i][j]=(self.dr(i+1,j+1,dp,s,n)or self.dr(i+1,j-1,dp,s,n)or self.dr(i+1,j,dp,s,n))
        return dp[i][j]
        
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        n = len(s)

        dp = []
        for i in range(n):
            dp.append([-1] * (n + 1))

        return self.dr(0, 0, dp, s, n)
