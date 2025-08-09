class Solution {
    public boolean isPowerOfTwo(int n) {
        

        if(n<=0){
            return false;
        }
        if(n==1){
            return true;
        }

        int r=n%2;
        if(r!=0){
            return false;
        }
         return isPowerOfTwo(n/2);
    }
}