#include <bits/stdc++.h>
#define MAXTIME 240
typedef long long ll;

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int spareTime = MAXTIME - k;
    int l=0,mid,r=n,ans;
    while(l <= r){
        mid = (l+r)/2;
        int totalTime = 5 * (mid + 1) * mid / 2;

        if(totalTime > spareTime){
            r = mid - 1;
        }
        else {
            ans = mid;
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}


