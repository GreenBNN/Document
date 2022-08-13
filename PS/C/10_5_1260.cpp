// edge �־�����
// DFS, BFS �湮�� ���� ���

#include <iostream>
#include <queue>

using namespace std;

int N; // ���� ����
int M; // �� ����
int V; // ���� ��
int map[1001][1001];
int visited[1001];
queue <int> q;

void DFS(int v) {
	visited[v] = 1;
	cout << v << " ";

	for (int i = 1; i <= N; i++) {
		if (map[v][i] == 1 && visited[i] == 0) { // ���� ���� �����̶� ����, ���� �湮 �������� DFS
			DFS(i);
		}
	}
}

void BFS(int v) {
	q.push(v);
	visited[v] = true;
	cout << v << " ";

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int w = 1; w <= N; w++) {
			if (map[v][w] == 1 && visited[w] == 0) { // ���� ���� �����̶� ����, ���� �湮 �������� BFS
				q.push(w);
				visited[w] = true;
				cout << w << " ";
			}
		}
	}
}

int main() {
	
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}

	DFS(V); // �湮����

	cout << '\n';

	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}

	BFS(V);
	

	return 0;
}