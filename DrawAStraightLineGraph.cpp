/* **************************
Problem : 직선 그래프 출력하기
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {
	int times;
	int num ;
	
	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> num;

		int len = num / 2;
		int n = num;

		for (int j = num; j > 0; j--) {
			for (int k = 0; k < num; k++) {
				if (j == k + 1 && j-1 == len)
					cout << "0";
				else if (j == k+1)
					cout << "*";
				else
					cout << ".";
			}
			cout << endl;
		}
	}
}
