#include <iostream>
using namespace std;

int main(){
    int v;
    cin >> v;
    for(int i=0;i<v;i++){
        int n,s,m,begin,end,prev_end;
        bool r;
        cin >> n >> s >> m;
        prev_end = 0;
        for(int j=0;j<n;j++){
            cin >> begin >> end;
            if (begin - prev_end >= s){
                r = true;
            }
            else{
                prev_end = end;
            }
            if(j == n-1){
                if(m - end >= s)
                    r = true;
            }
        }
        if(r){    
            cout << "YES" << endl;
            r = false;
        }
        else{
            cout << "NO" << endl;
        }
        // cout << "the '" << i << "' times" << endl;
    }
    return 0;
}