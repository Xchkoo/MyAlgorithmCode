/*AUTH:XCHKOO
 *DATE:19:03 2020/12/18
 *LISENCE:CC v1.0
 */
#include <iostream>
#include <string>
using namespace std;
int next[100];
int extend[100];
string S, T;
int n, m;
void GetNext(string & T, int & m, int next[]) {
	int a = 0, p = 0;
	next[0] = m;
	for (int i = 1; i < m; i++) {
		if (i >= p || i + next[i - a] >= p) {
			if (i >= p)
				p = i;
			while (p < m && T[p] == T[p - i])
				p++;
			next[i] = p - i;
			a = i;
			}
		else
			next[i] = next[i - a];
		}
	}

void GetExtend(string & S, int & n, string & T,\
			   int & m, int extend[], int next[]) {
	int a = 0, p = 0;
	GetNext(T, m, next);
	for (int i = 0; i < n; i++) {
		if (i >= p || i + next[i - a] >= p)
			// i >= p 的作用：举个典型例子，S 和 T 无一字符相同
			{
			if (i >= p)
				p = i;
			while (p < n && p - i < m && S[p] == T[p - i])
				p++;
			extend[i] = p - i;
			a = i;
			}
		else
			extend[i] = next[i - a];
		}
	}
int main() {

	while (cin >> S >> T) {
		n = S.size();
		m = T.size();
		GetExtend(S, n, T, m, extend, next);
		
		cout << "next: ";
		for (int i = 0; i < m; i++)
			cout << next[i] << " ";
		
		cout << endl <<"extend: ";
		for (int i = 0; i < n; i++)
			cout << extend[i] << " ";
		cout << endl << endl;
		return 0;
		}
	return 0;
	}
