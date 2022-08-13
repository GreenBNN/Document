// ���� ���� N
// 0 �� �ƴ϶�� ���� �ֱ�
// 0 �̶�� ���� ����
// ���Ŵ� ���밪�� ���� ���� �� ����
// ��������� ���� ���� �� ���� ����
// ������� �� ����϶�� �ϸ� 0 ���

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int>> v1; // ��� �������� ( 1 2 3 4 5 )top
priority_queue<int> v2; // ���� �������� (-1 -2 -3 -4 )top


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
		else if (x > 0) // ����� ��
		{
			v1.push(x);
		}
		else // (x < 0)������ ��
		{
			v2.push(x);
		}
	}

}