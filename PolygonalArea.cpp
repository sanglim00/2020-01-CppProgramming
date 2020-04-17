/* **************************
Problem : 다각형 면적
20191584 남상림
****************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int times, num;
	int x, y, D;
	int area = 0;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> num;
		int *arrX = new int[num];
		int* arrY = new int[num];
		for (int j = 0; j < num; j++) {
			cin >> x >> y;
			arrX[j] = x;
			arrY[j] = y;
		}
		area = (arrX[0] + arrX[num - 1]) * (arrY[0] - arrY[num - 1]);
		for (int a = 0; a < num - 1; a++) {
			area += (arrX[a] + arrX[a + 1]) * (arrY[a + 1] - arrY[a]);
		}
		D = (area > 0) ? 1 : -1;
		cout << abs(area) << " " << D << endl;
		delete[] arrX;
		delete[] arrY;
	}
}
