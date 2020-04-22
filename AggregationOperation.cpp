/* **************************
Problem : 집합 연산
20191584 남상림
****************************/

#include <iostream>
#include <algorithm>

using namespace std;

void gyo(int* arr, int* arr2, int a, int b) {
	int count = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (arr[i] == arr2[j]) count++;
		}
	}
	cout << count<<" ";
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (arr[i] == arr2[j]) cout << arr[i] << " ";
		}
	}
	cout << endl;
}

void hap(int* arr, int* arr2, int a, int b) {
	
}

int main() {
	int times, num;
	int a, b;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> a;
		int* arr = new int[a];
		for (int i = 0; i < a; i++) {
			cin >> num;
			arr[i] = num;
		}
		sort(arr, arr+a);

		cin >> b;
		int* arr2 = new int[b];
		for (int i = 0; i < b; i++) {
			cin >> num;
			arr2[i] = num;
		}
		sort(arr2, arr2 + b);

		gyo(arr, arr2, a, b);
		hap(arr, arr2, a, b);
	}
}