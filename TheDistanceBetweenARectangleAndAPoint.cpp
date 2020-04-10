/* **************************
Problem : 사각형과 점과의 거리
20191584 남상림
****************************/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
	int times;
	int x1S, y1S, x2S, y2S;
	int px, py;
	int d1, d2;

	cin >> times;
	for (int i = 0; i < times; i++) {

		cin >> x1S >> y1S >> x2S >> y2S;
		cin >> px >> py;

		if ((x1S <= px && px <= x2S) && (y1S <= py && py <= y2S))
			cout << 0 << " " << 0 << endl;
		else if (x1S <= px && px <= x2S) {
				d2 = (py - y2S) * (py - y2S);
				d1 = abs(py - y2S);
				cout << d2 << " " << d1 << endl;
		}
		else if (y1S <= py && py <= y2S) {
			d2 = (px - x2S) * (px - x2S);
			d1 = abs(px - x2S);
			cout << d2 << " " << d1 << endl;
		}
		else {
			d2 = (py - y2S) * (py - y2S) + (px - x2S) * (px - x2S);
			d1 = abs(py - y2S) + abs(px - x2S);
			cout << d2 << " " << d1 << endl;
		}
	}
}