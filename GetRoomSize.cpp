/* **************************
Problem : 방의 크기 구하기
20191584 남상림
****************************/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int times;
	int m, n;
	string line;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> m >> n;

		char** room = new char* [n];
		for (int j = 0; j < n; j++) room[j] = new char[m];

		for (int j = 0; j < n; j++) {
			cin >> line;
			for (int k = 0; k < m; k++) {
				room[j][k] = line[k];
			}
		}
		
	}
}