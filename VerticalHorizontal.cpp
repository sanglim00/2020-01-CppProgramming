/* **************************
Problem : 수직 수평 선분의 교차
20191584 남상림
****************************/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int times;
	int x1, x2, x3, x4, y1, y2, y3, y4;
	int minX, maxX, minY, maxY;

	cin  >> times;
	for (int i = 0; i < times; i++) {

		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		if (x1 == x2) {
			minX = min(x3, x4);
			maxX = max(x3, x4);
 			minY = min(y1, y2);
			maxY = max(y1, y2);
			if (minX < x1 && x1 < maxX) {
				if (minY < y3 && y3 < maxY) {
					cout << 1 << endl;
				}
				else if (minY == y3 || maxY == y3) {
					cout << 2 << endl;
				}
				else {
					cout << 0 << endl;
				}
			}
			else if (minX == x1 || x1 == maxX) {
				if (minY <= y3 && y3 <= maxY) {
					cout << 2 << endl;
				}
				else {
					cout << 0 << endl;
				}
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (x3 == x4) {
			minX = min(x1, x2);
			maxX = max(x1, x2);
			minY = min(y3, y4);
			maxY = max(y3, y4);
			if (minX < x3 && x3 < maxX) {
				if (minY < y1 && y1 < maxY) {
					cout << 1 << endl;
				}
				else if (minY == y1 || maxY == y1) {
					cout << 2 << endl;
				}
				else {
					cout << 0 << endl;
				}
			}
			else if (minX == x3 || maxX == x3) {
				if ( minY <= y1 && y1 <= maxY) {
					cout << 2 << endl;
				}
				else {
					cout << 0 << endl;
				}
			}
			else {
				cout << 0 << endl;
			}
		}
		else {
			cout << 0 << endl;
		}
	}
}
