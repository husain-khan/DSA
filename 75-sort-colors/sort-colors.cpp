class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countzero=0;
        int countone=0;
        int counttwo=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)countzero++;
            if(nums[i]==1)countone++;
            if(nums[i]==2)counttwo++;
        }
        int sum=countzero+countone+counttwo;
        int j=0;
            while(countzero!=0 && j!=sum){
                nums[j]=0;
                countzero--;
                j++;
            }
             while(countone!=0 && j!=sum){
                nums[j]=1;
                countone--;
                j++;
            }
             while(counttwo!=0 && j!=sum){
                nums[j]=2;
                counttwo--;
                j++;
            }
    }
};