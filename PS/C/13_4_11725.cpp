// ����� ���� N
// ����� �� ���� edge
// 2���� matrix �� v[v][w] == v[w][v] == 1 �� �ϸ� �޸� �ʰ�
// vector �� ����� vecter v[] ��� linkedlist ���� ����
// 1�� �ְ� 1 �� link �ȳ� queue �� push �ϰ� �׳���� �θ�� 1
// �ݺ�

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

