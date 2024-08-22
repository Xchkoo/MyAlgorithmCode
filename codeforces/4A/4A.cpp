#include <iostream>
#define ll long long
using namespace std;


int main(){
    ll a;
    cin >> a;
    if(a%2 == 0 && a > 2)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}