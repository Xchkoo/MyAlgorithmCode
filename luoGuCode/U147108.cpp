/*
 * Copyright © 2021 Xchkoo. All rights reserved.
 *
 * AUTHOR: Xchkoo
 * DATE: 2021-01-17
 * PURPOSE: 
 */
#include <iostream>
#include <algorithm>
#include <math.h>
typedef long long ll;
typedef size_t s_t;
const int MAXN = 10e7;
using namespace std;
/*variable declaration*/
ll n,m,k,a[MAXN];
ll res;
/******main function******/
int __func(int n){
	int nx = n;
if(nx == 1)	return 1;
for(int x = 2; x <= nx; x++){	
	if (nx % x == 0){
        nx /= x;
        a[x]++;
        x--;                           
	}
}
ll _maxn = -1;
for(int x = 2;x<=n;x++){
	if(_maxn <= a[x])
		_maxn = a[x];
}
return _maxn;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
			res += (ll)(max(m - __func(__gcd(i,j)) + 1,(ll)0)*(int)pow(n,k)) % 998244353;
        }
    }
    cout << res % 998244353 <<endl;
    return 0;
}
