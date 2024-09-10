#include <bits/stdc++.h>
using namespace std;

int characterToNumber[10] = {13,1,2,3,5,4,4,2,2,2};

int main()
{
    int res = 0;
    for(int i = 2000; i <= 2024; i++){
        for(int j = 1; j <= 12; j++){
            int m;
            if(j == 1 || j == 3 || j == 5 || j == 7 || j == 8 ||
               j == 10 || j == 12)
                m = 31;
            else if (j == 2){
                if (i % 4 == 0 || i % 1000 == 0)
                    m = 29;
                else 
                    m = 28;
            }
            else 
                m = 30;
            for(int day = 1; day <= m; day++){
                string date = to_string(i) + to_string(j) + to_string(day);
                int sum = 0;
                for(int p = 0; p < 8; p++){
                    sum += characterToNumber[int(date[p])];
                }
                if(sum > 50){
                    res++;
                }
                cout << res << endl;
                return 0;
            }
        }
    }
    return 0;
}
