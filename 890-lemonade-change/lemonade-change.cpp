class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int notes[3]={0,0,0};//onr for 5,one for 10 one for 20
        int i=0;
        int n=bills.size();
        if(bills[0]!=5){
            return false;
        }
        for(i=0;i<n;i++){
            if(bills[i]==5){
                notes[0]++;
            }
            else if(bills[i]==10){
                if(notes[0]>=1){
                  notes[1]++;
                  notes[0]--;
                }
            }
            else if(bills[i]==20){
               if(notes[1]>=1 && notes[0]>=1){
                    notes[2]++;
                    notes[1]=notes[1]-1;
                    notes[0]=notes[0]-1;
                }
                else if(notes[0]>=3){
                  notes[2]++;
                  notes[0]=notes[0]-3;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        } 
        if(i==n){
            return true;
        }
        else{
            return false;
        }
    }
};