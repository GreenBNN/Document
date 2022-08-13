// 연산 개수 N
// 0 이 아니라면 힙에 넣기
// 0 이라면 제거 실행
// 제거는 절대값이 가장 작은 수 제거
// 여러개라면 가장 작은 수 먼저 제거
// 비어있을 때 출력하라고 하면 0 출력

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int>> v1; // 양수 오름차순 ( 1 2 3 4 5 )top
priority_queue<int> v2; // 음수 내림차순 (-1 -2 -3 -4 )top


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 0)
		{
			if (v1.empty() && v2.empty()) 
				cout << "0\n";
			else 
			{
				if (v1.empty())
				{
					cout << v2.top() << '\n';
					v2.pop();
				}
				else if (v2.empty())
				{
					cout << v1.top() << '\n';
					v1.pop();
				}
				else
				{
					if (v1.top() < -v2.top())
					{
						cout << v1.top() << '\n';
						v1.pop();
					}
					else
					{
						cout << v2.top() << '\n';
						v2.pop();
					}
				}
			}
		}
		else if (x > 0) // 양수일 때
		{
			v1.push(x);
		}
		else // (x < 0)음수일 때
		{
			v2.push(x);
		}
	}

}