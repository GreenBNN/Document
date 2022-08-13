//	N * N 개의 map 1은 집 0 은 빈 곳
// 붙어있는 집은 하나의 단지
// 단지의 집 개수를 출력
// 1. DFS 를 사용하는데 붙어있는 집을 찾아야 한다 > dir 사용?
// 2. 하나 DFS로 찾고 집 count 해서 출력해주고 초기화 해줘야 한다.

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int graph[25][25];
int visited[25][25] = { 0 };
int house[25]; // 각 단지 집 개수 배열
int cnt = 0;
int num = 0; // 단지 개수
// 우,하,좌,상
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int DFS(int v,int w) {
	visited[v][w] = 1;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = v + dx[i];
		int ny = w + dy[i];

		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			// 집이면서 방문하지 않았다면 -> 방문
			if (graph[nx][ny] == 1 && visited[nx][ny] == 0) {
				DFS(nx, ny);
			}
		}
	}

	return 0;
}

int main() {
	// 입력받기
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 1 && visited[i][j] == 0) { // 집이면서 아직 방문 X
				DFS(i, j);
				num++;
				house[num] = cnt;
				cnt = 0; // 집개수 초기화
			}
		}
	}
	
	printf("%d\n", num);
	sort(house, house + num + 1);
	for (int i = 0; i < num; i++) {
		printf("%d\n", house[i+1]);
	}

	return 0;
}