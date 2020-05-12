/* **************************
Problem : 해밍 거리
20191584 남상림
****************************/

#include <iostream>

using namespace std;

void to_bin(int n, int* Harr) {
	for (int i = 31; i >= 0; i--) {
		Harr[i] = n % 2;
		n /= 2;
	}
}

int countNum(int* Harr) {
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if (Harr[i] == 1) count++;
	}
	return count;
}
int differentNum(int* arr, int* arr2) {
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if (arr[i] != arr2[i]) count++;
	}
	return count;
}
int main() {
	int times, num;
	cin >> times;
	for (int i = 0; i < times; i++) {
		int arr[32], arr2[32];
		cin >> num;
		to_bin(num, arr);
		cin >> num;
		to_bin(num, arr2);

		cout << countNum(arr) << " " << countNum(arr2)<<" "<<differentNum(arr, arr2)<<endl;
	}
}