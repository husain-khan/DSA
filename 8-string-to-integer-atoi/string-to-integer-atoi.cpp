class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        int neg_check=1;
        int ans=0;
        if(n==0){return 0;}
        while(i<n && s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            neg_check=-1;
            i++;
        }
         else if(s[i]=='+'){
            neg_check=1;
            i++;
        }
         while(i<n && s[i]=='0'){
            i++;
        }
       
        while(i<n){
            int temp=int(s[i]);
            if(temp<48 ||temp>57){
                break;
            }
         if (ans > (INT_MAX - (temp - 48)) / 10) {
      return neg_check == 1 ? INT_MAX : INT_MIN;
}

            ans=10*ans+(temp-48);
            i++;
        }
        return ans*neg_check;
    }
};