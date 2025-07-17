class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> op;
        vector<vector<int>>ans;
        set<vector<int>> myset;
        solve(candidates,op,target,ans,0,myset);
        return ans;
        
    }
    void solve(vector<int>& arr,vector<int>&op,int sum,vector<vector<int>>&ans,int idx, set<vector<int>> &myset){
        if(idx==arr.size() || sum<0){
            return;
        }
        if(sum==0){
         if (myset.find(op) == myset.end()) {
            myset.insert(op);
             ans.push_back(op);
             }
        return;

            
        }
            
            op.push_back(arr[idx]);
            solve(arr,op,sum-arr[idx],ans,idx+1,myset);
            solve(arr,op,sum-arr[idx],ans,idx,myset);
            op.pop_back();
            solve(arr,op,sum,ans,idx+1,myset);

        }
    }; 