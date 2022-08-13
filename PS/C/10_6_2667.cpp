//	N * N ���� map 1�� �� 0 �� �� ��
// �پ��ִ� ���� �ϳ��� ����
// ������ �� ������ ���
// 1. DFS �� ����ϴµ� �پ��ִ� ���� ã�ƾ� �Ѵ� > dir ���?
// 2. �ϳ� DFS�� ã�� �� count �ؼ� ������ְ� �ʱ�ȭ ����� �Ѵ�.

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int graph[25][25];
int visited[25][25] = { 0 };
int house[25]; // �� ���� �� ���� �迭
int cnt = 0;
int num = 0; // ���� ����
// ��,��,��,��
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int DFS(int v,int w) {
	visited[v][w] = 1;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = v + dx[i];
		int ny = w + dy[i];

		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			// ���̸鼭 �湮���� �ʾҴٸ� -> �湮
			if (graph[nx][ny] == 1 && visited[nx][ny] == 0) {
				DFS(nx, ny);
			}
		}
	}

	return 0;
}

int main() {
	// �Է¹ޱ�
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 1 && visited[i][j] == 0) { // ���̸鼭 ���� �湮 X
				DFS(i, j);
				num++;
				house[num] = cnt;
				cnt = 0; // ������ �ʱ�ȭ
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