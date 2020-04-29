/* **************************
Problem : 행렬곱셈
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {
	int times, num;
	int r, s, t;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> r >> s >> t;

		int** arr = new int* [r];
		for (int j = 0; j < r; j++) arr[j] = new int[s];

		for (int j = 0; j < r; j++) {
			for (int k = 0; k < s; k++) {
				cin >> num;
				arr[j][k] = num;
			}
		}

		int** arr2 = new int* [s];
		for (int j = 0; j < s; j++) arr2[j] = new int[t];

		for (int j = 0; j < s; j++) {
			for (int k = 0; k < t; k++) {
				cin >> num;
				arr2[j][k] = num;
			}
		}

		int** multi = new int* [r];
		for (int j = 0; j < r; j++) multi[j] = new int[t];

		for (int a = 0; a < r; r++) {
			for (int b = 0; b < t; b++) {
				multi[a][b] = 0;
				for (int c = 0; c < s; c++) {
					multi[a][b] += arr[a][c] * arr2[c][b];
				}
			}
		}
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < t; k++) {
				cout << multi[j][k] << " ";
			}
			cout << endl;
		}
	}
}
