#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int spareTime = 240 - k;
    int sum;
    for(int i=1;i<=n+1;i++){
        sum += i*5;
        if (spareTime < sum){
            cout << i-1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}