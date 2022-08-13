#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*##### DFS,BFS https://devuna.tistory.com/32 
		어떤 데이터를 어떤 방식으로 처리하고 싶은가?
			섬(1) 을 찾았을 때 다른 이어진 섬을 묶어두고 싶다 (link, array ...)  #####*/

#define MAX_SIZE 60

int map[MAX_SIZE][MAX_SIZE]; // int **map 으로 나중에 동적할당을 해주려면 scanf 로 입력받은 숫자들을 하나하나 슬라이싱 해줘야함
int visited[MAX_SIZE][MAX_SIZE] = { 0 }; // 방문 안했으면 0
int side[8] = { 1, 1, 0, -1, -1, -1, 0,1 }; // struct 로 하면 dir[8] 만들고 다시 초기화해줘야함
int up[8] = { 0, -1, -1, -1, 0, 1, 1,1 }; //  오른쪽부터 반시계방향
int w, h;
int landNum = 0;

void runTest();
void visit(int h, int w);
void reset();

int main() {

	while (1) {
		runTest();
		if (h == 0 && w == 0) { // h= 0, w = 0 이면 실행종료
			break;
		}
		printf("%d\n", landNum);
		reset();
	}

	return 0;
}
void runTest() {
	scanf("%d %d", &w, &h);
	for (int i = 0; i < h; i++) { // map 생성
		for (int j = 0; j < w; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < h; i++) { // 섬찾으러가자~
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				landNum++;
				visit(i, j);
			}
		}
	}
}
void visit(int h,int w) { // 전달받은 섬과 연결된 놈들 다 방문
	visited[h][w] = 1;

	for (int i = 0; i < 8; i++) {
		if (map[h + up[i]][w + side[i]] == 1 && visited[h + up[i]][w + side[i]] == 0) { //  다음 노드도 섬이고 아직 visit 안했으면 stack 에 넣기
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
