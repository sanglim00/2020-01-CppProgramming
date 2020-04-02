/* **************************
Problem : 숫자로 삼각형 출력하기
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {
	int times;
	int num;
	int n = 1;
	int col, row;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> num;
		for (row = num; row >= 0; row--) {
			for (col = row + 1; col <= num; col++) {
				cout << n;
				n++;
			}
			cout << endl;
		}
		n = 1, row = 0;
	}
	
}
