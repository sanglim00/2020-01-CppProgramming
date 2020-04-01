/* **************************
Problem : 두 정수 사이의 모든 정수의 합 구하기
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {
	int times = 0;
	int min = 0, max = 999;
	int sum = 0;

	cin >> times ;
	for (int i = 0; i < times; i++) {
		cin >> min >> max;
		for (; min <= max; min++) {
			sum += min;
		}
		cout << sum << endl;
		sum = 0;
	}
}