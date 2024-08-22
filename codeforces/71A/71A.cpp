#include <iostream>
#include <string.h>
using namespace std;
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string s, output;
        cin >> s;
        output = s;
        if (s.length() > 4){
            output = s[0]+ to_string(s.length()-2) + s[s.length()-1];
        }
        cout << output << endl;
    }
    return 0;
}