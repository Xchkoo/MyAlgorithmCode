#include <iostream>
using namespace std;

int main() {
    long long v;
    long long count = 0;
    cin >> v;
    for(int i=0;i<v;i++){
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        if(a1 > b1){
            if(a2 >= b2){
                count++;
            }
        }
        if(a1 > b2){
            if(a2 >= b1)
                count++;
        }
        if(a2 > b1){
            if(a1 >= b2)
                count++;
        }        
        if(a2 > b2){
            if(a1 >= b1)
                count++;
        }
        cout << count << endl;
        count = 0;
    }
}