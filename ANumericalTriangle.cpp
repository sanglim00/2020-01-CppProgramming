/* **************************
Problem : 숫자로 삼각형 출력하기
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {
	int times;
	int num;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> num;
		int n = 1;
		int p;
		int n_now;
		for (int row = num; row > 0; row--) {
			cout << n << " ";
			n_now = n;
			n += 1;
			p = num-1;
			
			for (int col = 0; col < num-row; col++) {
				n_now += p;
				cout << n_now << " ";
				p -= 1;
			}
			cout << endl;
		}	
	}
}
