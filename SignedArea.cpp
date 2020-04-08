/* **************************
Problem : 삼각형 면적
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {

	int times, num;
	int Carray[3][2];
	int signedArea;

	cin >> times;
	for (int i = 0; i < times; i++) {

		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 2; k++) {
				cin >> num;
				Carray[j][k] = num;
			}
		}
		signedArea = (Carray[1][0] - Carray[0][0]) * (Carray[2][1] - Carray[0][1]) - (Carray[2][0] - Carray[0][0]) * (Carray[1][1] - Carray[0][1]);
		if (signedArea > 0) {
			cout << signedArea << " " << 1 << endl;
		}
		else if (signedArea < 0) {
			cout << signedArea * (-1) << " " << -1 << endl;
		}
		else
			cout << 0 << " " << 0 << endl;
	}

}