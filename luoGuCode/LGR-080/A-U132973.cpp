#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int a[3];
int gethax(){
    int ret[2];
    char res[2];
    res[0] = getchar();
    res[1] = getchar();
    for(int i = 0;i<=1;i++)
    {
        if(res[i] >= '0' && res[i] <= '9')
            ret[i] = res[i] - '0';
        if(res[i] >= 'A' && res[i] <= 'F')
            ret[i] = res[i] - 'A' + 10;
    }
    return (ret[1] + ret[0]*16);
}
int reduction(int a){a = 255 - a;}
void __output__(){
	cout<<"#";
	for(int j = 1;j <= 3;j++){
		if( a[j] < 16 && a[j] >= 0 ){ 
			if(a[j] == 0)
				cout << "00"; 
				
            if(a[j] < 10 && a[j] > 0)
				cout << "0" <<a[j];
				
			if(a[j] < 16 && a[j] >= 10)
				switch (a[j] - 10){ 
				case 0:
					cout << '0' << "A";
					break;
				case 1:
					cout << '0' << "B";
					break;
				case 2:
					cout << '0' << "C";
					break;
				case 3:
					cout << '0' << "D";
					break;
				case 4:
					cout << '0' << "E";
					break;
				case 5:	
					cout << '0' << "F";
					break;
				} 
			} 
        else
            printf( "%X" ,a[j]);
    } 
}

int main(){
    int useless = getchar();
    for(int j = 1;j <= 3;j++){
        a[j] = gethax();
        a[j] = reduction(a[j]);
    }
    __output__();
	cout<<endl;
    return 0;
}
