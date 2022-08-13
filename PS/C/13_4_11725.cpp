// 노드의 개수 N
// 연결된 두 정점 edge
// 2차원 matrix 로 v[v][w] == v[w][v] == 1 로 하면 메모리 초과
// vector 를 사용해 vecter v[] 사용 linkedlist 같은 느낌
// 1을 넣고 1 과 link 된놈 queue 에 push 하고 그놈들의 부모는 1
// 반복

#include <iostream> 
#include <vector> 

using namespace std; 
#define MAX 100001 

int N; 
int arr[MAX]; 
bool visited[MAX]; 
vector<int> v[MAX]; 

void dfs(int k) { 
	visited[k]=true; 

	for(int i=0;i<v[k].size();i++) { 

		int dx = v[k][i]; 

		if(!visited[dx]) { 
			arr[dx]=k; 
			dfs(dx); 
		} 
	}
} 

int main() { 

	cin >> N; 

	for(int i=0;i<N;i++) { 
		int x,y; 
		cin >> x >> y; 
		v[x].push_back(y); 
		v[y].push_back(x); 
	} 

	dfs(1); 

	for(int i=2;i<=N;i++) 
		cout << arr[i] << "\n";

}

