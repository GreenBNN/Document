#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*##### DFS,BFS https://devuna.tistory.com/32 
		� �����͸� � ������� ó���ϰ� ������?
			��(1) �� ã���� �� �ٸ� �̾��� ���� ����ΰ� �ʹ� (link, array ...)  #####*/

#define MAX_SIZE 60

int map[MAX_SIZE][MAX_SIZE]; // int **map ���� ���߿� �����Ҵ��� ���ַ��� scanf �� �Է¹��� ���ڵ��� �ϳ��ϳ� �����̽� �������
int visited[MAX_SIZE][MAX_SIZE] = { 0 }; // �湮 �������� 0
int side[8] = { 1, 1, 0, -1, -1, -1, 0,1 }; // struct �� �ϸ� dir[8] ����� �ٽ� �ʱ�ȭ�������
int up[8] = { 0, -1, -1, -1, 0, 1, 1,1 }; //  �����ʺ��� �ݽð����
int w, h;
int landNum = 0;

void runTest();
void visit(int h, int w);
void reset();

int main() {

	while (1) {
		runTest();
		if (h == 0 && w == 0) { // h= 0, w = 0 �̸� ��������
			break;
		}
		printf("%d\n", landNum);
		reset();
	}

	return 0;
}
void runTest() {
	scanf("%d %d", &w, &h);
	for (int i = 0; i < h; i++) { // map ����
		for (int j = 0; j < w; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < h; i++) { // ��ã��������~
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				landNum++;
				visit(i, j);
			}
		}
	}
}
void visit(int h,int w) { // ���޹��� ���� ����� ��� �� �湮
	visited[h][w] = 1;

	for (int i = 0; i < 8; i++) {
		if (map[h + up[i]][w + side[i]] == 1 && visited[h + up[i]][w + side[i]] == 0) { //  ���� ��嵵 ���̰� ���� visit �������� stack �� �ֱ�
			visit(h+up[i], w+side[i]);
		}
	}
}

void reset() {
	for (int i = 0; i < h; i++) { 
		for (int j = 0; j < w; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	landNum = 0;
}
