class Solution {
    public boolean checkDivisibility(int n) {
        int a = n;
        int i;
        int j = 0;
        int k = 1;
        while(a>0)
        {
            i = a%10;
            a = a/10;
            j = j+i;
            k = k*i;
        }
        if(n%(j+k)==0)
        {
            return true;
        }
        return false;
    }
}