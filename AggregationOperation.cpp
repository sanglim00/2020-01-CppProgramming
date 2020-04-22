/* **************************
Problem : 집합 연산
20191584 남상림
****************************/

#include <iostream>
#include <algorithm>

using namespace std;

void gyo(int* arr, int* arr2) {
	int count = 0;
	for (int i = 0; i < 132; i++) {
		if (arr[i] == 1 && arr2[i] == 1)
			count++;
	}
	cout << count<<" ";
	for (int i = 0; i < 132; i++) {
		if (arr[i] == 1 && arr2[i] == 1)
			cout << i << " ";
	}
	cout << endl;
}

void hap(int* arr, int* arr2) {
	int count = 0;
	for (int i = 0; i < 132; i++) {
		if (arr[i] == 1 || arr2[i] == 1) {
			count++;
		}
	}
	cout << count << " ";
	for (int i = 0; i < 132; i++) {
		if (arr[i] == 1 || arr2[i] == 1) {
			cout << i << " ";
		}
	}
	cout << endl;
}
void cha(int* arr, int* arr2) {
	int count = 0;
	for (int i = 0; i < 132; i++) {
		if (arr[i] == 1 && arr2[i] == 1) {
			arr[i] = 0;
		}
	}
	for (int i = 0; i < 132; i++) {
		if (arr[i] == 1) count++;
	}
	cout << count << " ";
	for (int i = 0; i < 132; i++)
		if (arr[i] == 1) cout << i << " ";
	cout << endl;
	
}

int main() {
	int times, num;
	int a, b;
	int arr[132] = { 0, }, arr2[132] = { 0, };

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> a;
		for (int i = 0; i < a; i++) {
			cin >> num;
			arr[num] = 1;
		}
		cin >> b;
		for (int i = 0; i < b; i++) {
			cin >> num;
			arr2[num] = 1;
		}
		gyo(arr, arr2);
		hap(arr, arr2);
		cha(arr, arr2);

		a = 0, b = 0;
		for (int i = 0; i < 132; i++) {
			if (arr[i] == 1 || arr2[i] == 1) {
				arr[i] = 0, arr2[i] = 0;
			}
		}
	}
	
}
