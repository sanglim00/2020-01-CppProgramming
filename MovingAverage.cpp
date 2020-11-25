/* **************************
Problem : 이동 평균
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {
	int times, num;
	int N, K;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> num;
		int* arr = new int[num];
		for (int j = 0; j < num; j++) {
			cin >> N;
			arr[j] = N;
		}
		cin >> K;
		
		int count = num - K + 1;
		int* sum = new int[count];

		int P = 0;
		for (int q = 0; q < count; q++) {
			sum[q] = 0;
			for (int p = 0; p < K; p++) {
				sum[q] += arr[p+P];
			}
			sum[q] = sum[q] / K;
			P++;
		}
		cout << count << " ";
		for (int j = 0; j < count; j++)
			cout << sum[j] << " ";
		cout << endl;
	}	
}
