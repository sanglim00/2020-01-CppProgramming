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

		int n=0;
		for (int j = num; j >= 1; j--) {
			cout << endl;
			for (int k = 0; k < num; k++) {
				if (j <=num / 2 + 1&& k < j - 1) { 
					cout << "-";
				}

				else if (j > num / 2  && j <= k ) {
					cout << "-";
				}

				else if (j < num - k && j / 2 <= num / 2 && k < num / 2 && j>k + 1) {
					cout << "-";
				}
				else if (j <= num / 2 && k >num/2 && k +n>j/2 ) {
					cout << "-";
					n--;
				}
				
				else {
					if (k % 2 == 1)
						if (j % 2 == 0)
							cout << "*";
						else
							cout << "+";
					else {
						if (j % 2 == 1)
							cout << "*";
						else
							cout << "+";
					}
				}
			}
		}
	}
}
