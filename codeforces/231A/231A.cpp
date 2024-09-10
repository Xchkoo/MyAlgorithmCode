#include <bits/stdc++.h>
using namespace std;
int n,ans = 0;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a + b + c >= 2) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}