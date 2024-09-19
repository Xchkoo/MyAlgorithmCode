#include<iostream>
using namespace std;
#define MAXQ 1000
int r;
int triangle[MAXQ][MAXQ];
int dp[MAXQ][MAXQ];

int main()
{    
    cin >> r;
    for(int i=0;i<r;i++){
        for(int j=0;j<=i;j++){
            cin >> triangle[i][j];
        }
    }   
    //input

    // Initialize dp array
    for(int i=0;i<r;i++) {
        for(int j=0;j<=i;j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = triangle[0][0];
    for(int i=1;i<r;i++){
        for(int j=0;j<=i;j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            else if(j == i){
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j];
            }
        }
    }
    // calu dp


    // search for max end
    int max_sum = 0;
    for(int i = 0;i<r;i++){
        if(dp[r-1][i] > max_sum){
            max_sum = dp[r-1][i];
        } 
    }
    cout << max_sum;
    return 0;
}
