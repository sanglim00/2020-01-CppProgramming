/* **************************
Problem : 주어진 정수의 최대최소 구하기
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {
	int times;
	int howmany ;
	int input;
	int min = 999, max = -999;

	cin >> times ;

	for (int i = 0; i < times; i++) {
		cin >> howmany;
		for (int j = 0; j < howmany; j++) {
			cin >> input;
			if (input > max)
				max = input;
			if (input < min)
				min = input;
		}
		input = 0;
		cout << max << " "<< min << endl;
		min = 999, max = -999;
	}

}