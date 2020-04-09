/* **************************
Problem : 삼각형의 종류 02
20191584 남상림
****************************/

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double times, num;
	double Carray[3][2];
	double a, b, c;

	cin >> times;
	for (int i = 0; i < times; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 2; k++) {
				cin >> num;
				Carray[j][k] = num;
			}
		}
		a = sqrt((Carray[1][0] - Carray[0][0]) * (Carray[1][0] - Carray[0][0]) + (Carray[1][1] - Carray[0][1]) * (Carray[1][1] - Carray[0][1]));
		b = sqrt((Carray[2][0] - Carray[0][0]) * (Carray[2][0] - Carray[0][0]) + (Carray[2][1] - Carray[0][1]) * (Carray[2][1] - Carray[0][1]));
		c = sqrt((Carray[2][0] - Carray[1][0]) * (Carray[2][0] - Carray[1][0]) + (Carray[2][1] - Carray[1][1]) * (Carray[2][1] - Carray[1][1]));

		if (a + b > c) {
			if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
				cout << 1 << endl;
			else if (((Carray[1][1] - Carray[0][1]) / (Carray[1][0] - Carray[0][0])) == ((Carray[2][1] - Carray[1][1]) / (Carray[2][0] - Carray[1][0])))
				cout << 0 << endl;
			else if (a * a + b * b < c * c || a * a + c * c < b * b || b * b + c * c < a * a)
				cout << 2 << endl;
			else if (a * a + b * b > c* c || a * a + c * c > b* b || b * b + c * c > a* a)
				cout << 3 << endl;
		}
		else
			cout << 0 << endl;

		
	}
}
