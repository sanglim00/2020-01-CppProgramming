/* **************************
Problem : 해밍수
20191584 남상림
****************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Hamming(int num) {
	int Hamlist[3] = { 2, 3, 5 };
	int ham = 1;
	vector<long int> hamming;
	hamming.push_back(ham);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 3; j++) {
			hamming.push_back(ham * Hamlist[j]);
		}
		ham++;
	}
	sort(hamming.begin(), hamming.end());
	hamming.erase(unique(hamming.begin(), hamming.end()), hamming.end());
	
	for (int i = 0; i < num; i++)
		cout << hamming[i] << " ";
	cout << endl;
}

int main() {
	int times, num;

	cin >> times;
	for (int i = 0; i < times; i++) {

		cin >> num;
		Hamming(num);
		
	}

}