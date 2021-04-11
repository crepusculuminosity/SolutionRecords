#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dx[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1 };

int R, C, K;
int A[55][55];
bool visited[51][51][21][21][7];

struct State {
	int x, y, vx, vy, p, dist;
	State(int x_, int y_, int vx_, int vy_, int p_, int dist_) { x = x_; y = y_; vx = vx_; vy = vy_; p = p_; dist = dist_; };
	bool isEnd() {
		return (A[x][y] == K+1 && vx == 0 && vy == 0 && p == K + 1);
	}
	bool isValid() {
		return (x >= 0 && y >= 0 && x < R&& y < C&& vx >= -10 && vy >= -10 && vx <= 10 && vy <= 10 && A[x][y] >= -1);
	}
};

vector<State> Q;

int main() {
	cin >> R >> C >> K;
	int startx, starty;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			if (str[j] == '.') A[i][j] = -1;
			else if (str[j] == '#') A[i][j] = -2;
			else A[i][j] = str[j] - '0';
			if (A[i][j] == 0) {
				startx = i; starty = j;
			}
		}
	}

	memset(visited, false, 51 * 51 * 21 * 21 * 7 * sizeof(bool));
	Q.clear();
	State start(startx, starty, 0, 0, 0, 0);
	visited[startx][starty][10][10][0] = true;
	Q.push_back(start);

	for (int y = 0; y < Q.size(); y++) {
		if (Q[y].isEnd()) {
			cout << Q[y].dist << endl;
			return 0;
		}
		for (int i = 0; i < 9; i++) {
			State S(Q[y].x + Q[y].vx + dx[i], Q[y].y + Q[y].vy + dy[i], Q[y].vx + dx[i], Q[y].vy + dy[i], Q[y].p, Q[y].dist + 1);
			if (S.isValid()) {
				if (A[S.x][S.y] == Q[y].p + 1) S.p++;
				if (visited[S.x][S.y][S.vx + 10][S.vy + 10][S.p]) continue;
				visited[S.x][S.y][S.vx + 10][S.vy + 10][S.p] = true;
				Q.push_back(S);
			}
		}
	}

	cout << "impossible" << endl;

	return 0;
}
