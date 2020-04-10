/* **************************
Problem : 사각형과 점과의 거리
20191584 남상림
****************************/

###############################코드 1#####################################
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
	int times;
	int x1, y1, x2, y2;
	int px, py;
	int d1, d2;

	cin >> times;
	for (int i = 0; i < times; i++) {

		cin >> x1 >> y1 >> x2 >> y2;
		cin >> px >> py;

		if ((x1 <= px && px <= x2) && (y1 <= py && py <= y2))
			cout << 0 << " " << 0 << endl;
		else if (x1 <= px && px <= x2) {
			if (abs(py - y1) > abs(py - y2)) {
				d2 = (py - y2) * (py - y2);
				d1 = abs(py - y2);
				cout << d2 << " " << d1 << endl;
			}
			else {
				d2 = (py - y1) * (py - y1);
				d1 = abs(py - y1);
				cout << d2 << " " << d1 << endl;
			}
		}
		else if (y1 <= py && py <= y2) {
			if (abs(px - x1) > abs(px - x2)) {
				d2 = (px - x2) * (px - x2);
				d1 = abs(px - x2);
				cout << d2 << " " << d1 << endl;
			}
			else {
				d2 = (px - x1) * (px - x1);
				d1 = abs(px - x1);
				cout << d2 << " " << d1 << endl;
			}
		}
		else {
			d2 = (py - y2) * (py - y2) + (px - x2) * (px - x2);
			d1 = abs(py - y2) + abs(px - x2);
			cout << d2 << " " << d1 << endl;
		}
	}
}
##################################### 코드 2 #############################################
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
	int x1, y1, x2, y2;
	int px, py;
	int d1, d2;

	cin >> times;
	for (int i = 0; i < times; i++) {

		cin >> x1 >> y1 >> x2 >> y2;
		cin >> px >> py;

		if (x1 <= px && px <= x2) {
			if (y1 <= py && py <= y2) {
				cout << 0 << " " << 0 << endl;
			}
			else if(abs(y1- py) < abs(y2-py)){
				d2 = (py - y1) * (py - y1);
				d1 = abs(py - y1);
				cout << d2 << " " << d1 << endl;
			}
			else {
				d2 = (py - y2) * (py - y2);
				d1 = abs(py - y2);
				cout << d2 << " " << d1 << endl;
			}
		}
		else if (y1 <= py && py <= y2) {
			if (abs(x1- px) < abs(x2-px)) {
				d2 = (px - x1) * (px - x1);
				d1 =abs( px - x1);
				cout << d2 << " " << d1 << endl;
			}
			else {
				d2 = (px - x2) * (px - x2);
				d1 = abs(px - x2);
				cout << d2 << " " << d1 << endl;
			}
		}
		else {
			d2 = (py - y2) * (py - y2) + (px - x2) * (px - x2);
			d1 = abs(py - y2) + abs(px - x2);
			cout << d2 << " " << d1 << endl;
		}
	}
}
