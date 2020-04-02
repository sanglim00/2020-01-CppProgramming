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
		
		for (int n = num; n >0; n--) {
			for (int j = 0; j < num; j++) {
				if (j < n - 1)
					cout << ".";
				else
					cout << "*";
			}
			cout << endl;
		}
	}
}