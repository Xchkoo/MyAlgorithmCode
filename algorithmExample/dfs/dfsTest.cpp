/*
https://oi-wiki.org/search/dfs/ 

例题

把正整数 n 分解为 3 个不同的正整数，如 6=1+2+3，排在后面的数必须大于等于前面的数，输出所有方案。

 */
#include<iostream>
using namespace std;

int  n, m, arr[103];  // arr 用于记录方案

void dfs(int n, int i, int a) { // n 剩余数量 、i 第几层 、a 从几开始
    if (n == 0) {
        for (int j = 1; j <= i - 1; ++j) 
            cout << arr[j] << endl;
    }
    if (i <= m) {
        for (int j = a; j <= n; ++j) {
            arr[i] = j;
            dfs(n - j, i + 1, j);  // 请仔细思考该行含义。
        }
    }
}

int main(){
    cin >> n >> m;
    dfs(n, 1, 1);
    return 0;
}