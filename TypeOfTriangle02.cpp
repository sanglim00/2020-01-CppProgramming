/* **************************
Problem : 삼각형의 종류 02
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {
	int times, num;
	int Carray[3][2];
	int a, b, c;

	cin >> times;
	for (int i = 0; i < times; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 2; k++) {
				cin >> num;
				Carray[j][k] = num;
			}
		}
		a = (Carray[1][0] - Carray[0][0]) * (Carray[1][0] - Carray[0][0]) + (Carray[1][1] - Carray[0][1]) * (Carray[1][1] - Carray[0][1]);
		b = (Carray[2][0] - Carray[0][0]) * (Carray[2][0] - Carray[0][0]) + (Carray[2][1] - Carray[0][1]) * (Carray[2][1] - Carray[0][1]);
		c = (Carray[2][0] - Carray[1][0]) * (Carray[2][0] - Carray[1][0]) + (Carray[2][1] - Carray[1][1]) * (Carray[2][1] - Carray[1][1]);
		
		int Slope = ((Carray[1][1] - Carray[0][1]) / (Carray[1][0] - Carray[0][0])) == ((Carray[2][1] - Carray[1][1]) / (Carray[2][0] - Carray[1][0]));
		if (a + b == c || a + c == b || b + c == a)
			cout << 1 << endl;
		else if (Slope)
			cout << 0 << endl;
		else if (a + b < c || a + c < b || b + c < a)
			cout << 2 << endl;
		else if (a + b > c || a + c > b || b + c > a)
			cout << 3 << endl;
		
	}
}