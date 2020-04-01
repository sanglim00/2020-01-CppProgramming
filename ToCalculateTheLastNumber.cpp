/* **************************
Problem : 끝자리 숫자 계산하기
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {
	int times, n, num;
	int multiply = 1;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> num;

			if (num > 99 )
				multiply *= num % 10;
			else 
				multiply *= num;
			if (multiply > 99)
				multiply = multiply % 10;

		}
		cout << multiply %10 << endl;
		multiply = 1;
	}
}