class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1){
            return true;
        }
        if(n==2 || n==3 ||n==0){
            return false;
        }
        int r=n%4;
        if(n%4!=0){
            return false;
        }
        else{
           return isPowerOfFour(n/4);
        }
        
    }
};