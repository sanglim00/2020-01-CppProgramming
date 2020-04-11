/* **************************
Problem : 수직 수평 선분의 교차
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {

	int times;
	int x1, x2, x3, x4, y1, y2, y3, y4;


	cin  >> times;
	for (int i = 0; i < times; i++) {

		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		if (x1 == x2) {
			if (x3 < x1 && x1 < x4) {
				if (y2 < y3 && y3 < y1) {
					cout << 1 << endl;
				}
				else if (y1 == y3 ||y2 ==y3) {
					cout << 2 << endl;
				}
				else if(y3>y1 || y3<y2) {
					cout << 0 << endl;
				}
			}
			else if (x3 == x1 || x1 == x4 ) {
				if (y2 <= y3 && y3 <= y1) {
					cout << 2 << endl;
				}
				else if(y3<y2 ||y3>y1) {
					cout << 0 << endl;
				}
			}
			else {
				cout << 0 << endl;
			}
		}
	}
}
