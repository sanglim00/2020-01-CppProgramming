/* **************************
Problem : 부활절 날짜 계산
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {
	int times;
	int Y = 0, C = 0, N = 0, T = 0, I = 0, J = 0, K = 0, L = 0, P = 0, Q = 0, M = 0, D = 0;
	cin >> times;

	for (int i = 0; i < times; i++) {
		cin >> Y;
		C = Y / 100;
		N = Y - (Y / 19) * 19 ;
		T = (C - 17) / 25;
		I = C - (C / 4) - (C - T) / 3 + (N * 19) + 15;
		J = I - I / 30 * 30 ;
		K = J - J / 28 * (1 - J / 28) * (29 / (J + 1)) * ((21 - N) / 11);
		L = (Y + Y / 4 + J + 2) - C + C / 4;
		P = L - ((L / 7) * 7);
		Q = K - P;
		M = (Q + 40) / 44 + 3;
		D = (Q + 28) - (M / 4 * 31);

		cout << M << " " << D << endl;
		Y= 0, C= 0, N= 0, T= 0, I= 0, J= 0, K= 0, L= 0, P =0, Q = 0, M= 0, D = 0;
	}
}