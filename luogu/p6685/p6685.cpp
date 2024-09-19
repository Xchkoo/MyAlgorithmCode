#include<iostream>
#include<math.h>
int n,m,cnt;
int main()
{
    std::cin >> n >> m;
    for(int i = 1;;i++)
    {
        if(pow(i,m) <= n)
            cnt++;
        else
        {
            std::cout<<cnt;
            return 0;
        }  
    }
    return 0;
}