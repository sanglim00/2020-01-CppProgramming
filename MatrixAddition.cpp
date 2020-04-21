/* **************************
Problem : Çà·Ä µ¡¼À
20191584 ³²»ó¸²
****************************/

#include <iostream>

using namespace std;

int main() {
	int times, num, num2;
	int x, y;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> x >> y;
		int** arr = new int*[x];
		for (int p = 0; p < x; p++)
			arr[p] = new int[y];

		for (int j = 0; j < x; j++) {
			for (int k = 0; k < y; k++) {
				cin >> num;
				arr[j][k] = num;
			}
		}
		for (int j = 0; j < x; j++) {
			for (int k = 0; k < y; k++) {
				cin >> num2;
				arr[j][k] += num2;
			}
		}

		for (int j = 0; j < x; j++) {
			for (int k = 0; k < y; k++) {
				cout<<arr[j][k]<<" ";
			}
			cout << endl;
		}
	}
}