class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        rev =0
        t=False
        if x<0:
            x=abs(x)
            t=True
        while x>0:
            d=x%10
            rev=rev*10+d
            x//=10

        if rev<-2**31 or rev>2**31:
            return 0
        if t==True :
            return -rev
        return rev
