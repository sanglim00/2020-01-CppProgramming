/* **************************
Problem : 시간 계산
20191584 남상림
****************************/

#include <iostream>

using namespace std;

int main() {
	int times, member;
	int H, M, S, h, m, s;
	int day = 0, hour = 0, min = 0, sec = 0;
	int sum = 0, sum2 = 0;
	int T = 0;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> member;
		for (int j = 0; j < member; j++) {
			cin >> H >> M >> S >> h >> m >> s;
			sum2 = H * 3600 + M * 60 + S;
			sum = h * 3600 + m * 60 + s;
			T += sum - sum2;
		}

		day = T / 86400;
		hour = T % 86400 / 3600;
		min = T % 86400 % 3600 / 60;
		sec = T % 86400 % 3600 % 60;

		cout << day << " " << hour  << " " << min << " " << sec << endl;
		day = 0, hour = 0, min = 0, sec = 0;
		sum = 0, sum2 = 0, T = 0;
	}
}
