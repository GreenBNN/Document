#include <iostream> 
#include <vector> 

using namespace std;

struct node {
    char left;
    char right;
};

vector<node> v(26);

void recursive_preorder(char data) { // 재귀함수를 사용해  VLR 출력
	if (data == '.') 
		return;

	printf("%c", data);
	recursive_preorder(v[data].left);
	recursive_preorder(v[data].right);
}

void recursive_inorder(char data) { // 재귀함수를 사용해 LVR 출력 
	if (data == '.') 
		return;

	recursive_inorder(v[data].left);
	printf("%c", data);
	recursive_inorder(v[data].right);
}

void recursive_postorder(char data) { // 재귀함수를 사용해  LRV 출력
	if (data == '.') 
		return;

	recursive_postorder(v[data].left);
	recursive_postorder(v[data].right);
	printf("%c", data);
}

int main() {
	int n;
	scanf("%d", &n);

	char a, l, r;
	for (int i = 0; i < n; i++) {
		cin >> a >> l >> r;
		v[a].left = l;
		v[a].right = r;
	}

	recursive_preorder('A');
	printf("\n");

	recursive_inorder('A');
	printf("\n");

	recursive_postorder('A');

	return 0;
}