#include<iostream>
#include<string>
#include<vector>
using namespace std;
std::ios::sync_with_stdio(false);

vector<string> master;

int n;
int main(){
	cin >> n;
	string a;
	for(int i = 1;i <= n;i++){
		cin >> a;
		master.push_back(a);
		cout >> master.front();
	}
	return 0;	
}

