int dp[101][101];

int n;



int find(int x, int y, vector<vector<int>>& g)

{

    if(x == n)

        return 0;



    if(dp[x][y] != -100000)

        return dp[x][y];



    int ans = g[x][y] + find(x+1, y, g);



    if(y-1>=0)

        ans = min(ans, g[x][y] + find(x+1, y-1, g) );



    if(y+1!=n)

        ans = min(ans, g[x][y] + find(x+1, y+1, g) );

    

    return dp[x][y] = ans;

}



class Solution {

public:

    int minFallingPathSum(vector<vector<int>>& mat) {

        

        n = mat.size();

        int ans = 1e9;

        

        for(int I=0; I<101; ++I)

            for(int j=0; j<101; ++j)

                dp[I][j] = -100000;



        for(int I=0; I<mat.size(); ++I)

            ans = min(ans, find(0, I, mat));

        

        return ans;

    }

};