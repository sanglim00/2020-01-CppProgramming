/* **************************
Problem : 모래시계 출력하기
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {
	int times, num;

	cin >> times;
	for (int i = 0; i < times; i++) {
		
		cin >> num;
		int n = 0;
		for (int j = 0; j < num; j++) {
			if (j < num / 2 ) {
				for (int k = num/2; k >= 0 ; k--) {
					if (j > k)
						cout << "-";
					else
						cout << "*";
				}
			}
			else {
				for (int k = num / 2; k < num; k++) {
					if (k > j)
						cout << "-";
					else
						cout << "*";
				}
			}
			cout << endl;
		}
	}
}