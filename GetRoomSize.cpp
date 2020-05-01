/* **************************
Problem : 방의 크기 구하기
20191584 남상림
****************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 100;

struct element { char y, x; };
element moveD[4]= { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
 
char room[MAX][MAX];
bool visited[MAX][MAX];

int m, n;
int cnt;
void HowManyRoom(int y, int x) {
	visited[y][x] = true;
	
	cnt ++;
	for (int i = 0; i < 4; i++) {
		int nextY = y + moveD[i].y;
		int nextX = x + moveD[i].x;

		if (0 <= nextY && nextY < m && 0 <= nextX && nextX < n) {
			if (room[nextY][nextX] == '.'&& !visited[nextY][nextX]) HowManyRoom(nextY,nextX);
		}
	}
}
int main(){
	int times;

	cin >> times;
	for (int i = 0; i < times; i++) {
		string line;
		cin >> m >> n;
		for (int j = 0; j < n; j++) {
			cin >> line;
			for (int k = 0; k < m; k++) {
				room[j][k] = line[k];
			}
		}
		vector<int>Rcount;
		
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (room[j][k] == '.' && !visited[j][k]) {
					cnt = 0;
					HowManyRoom(j, k);
					Rcount.push_back(cnt);
				}
			}
		}
		cout << Rcount.size() << endl;
		for (int c = 0; c < Rcount.size(); c++) cout << Rcount[c] << " ";
		cout << endl;
		sort(Rcount.begin(), Rcount.end(), greater<int>());
		for (int c = 0; c < Rcount.size(); c++) cout << Rcount[c] << " ";

	}
}