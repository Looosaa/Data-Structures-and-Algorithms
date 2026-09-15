//最短公共超序列
//本题用动态规划求LCS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string X,Y;
    cin>>X>>Y;

    int m=X.length();
    int n=Y.length();

    //vector<vector<int>> dp(m+1,vector<int>(n+1,0)); 
    //创建m+1行、n+1列的二维数组vector,所有位置初始为0
    //也可以这么写\
    //可访问dp[i][j]

    vector<vector<int> > dp;
    for(int i=0;i<m+1;i++){
        vector<int> row(n+1,0);
        dp.push_back(row);
    }
//定义dp[i][j]为X前i个字符和Y前j个字符的最长公共子序列长度
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int ans=X.length()+Y.length()-dp[m][n];

    cout<<ans<<endl;
    return 0;
}

