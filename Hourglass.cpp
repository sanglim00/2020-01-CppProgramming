/* **************************
Problem : 모래시계 출력하기
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {
	int times, num, len;
	int row = 1, col =1;

	cin >> times;
	for (int i = 0; i < times; i++) {

		cin >> num;
		len = num / 2;
		while (row <= num) {
			if (row % 2 == 1) {
				if (col % 2 == 1) {
					cout << "*";
					col++;
				}
				else {
					cout << "+";
					col++;
				}
				row++;	
			}
			else {
				if (col % 2 == 1) {
					cout << "*";
					col++;
				}
				else {
					cout << "+";
					col++;
				}
				row++;
			}
		}
	}
}