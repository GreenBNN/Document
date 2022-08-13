#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int alpha[97];
string odd, even;

int main()
{
    string s;
    cin >> s;
    for (char i : s) // for i in s 처럼 s 안에 있는 원소들 불러오기
    {
        alpha[i]++;
    }
    for (char i = 'A'; i <= 'Z'; i++)
    {
        if (alpha[i] % 2)
        {
            odd += i;
        }
        for (int j = 0; j < alpha[i] / 2; j++)
        {
            even += i;
        }
    }
    if (odd.size() > 1)
    {
        printf("I'm Sorry Hansoo");
    }
    else
    {
        cout << even;
        cout << odd;
        reverse(even.begin(), even.end());
        cout << even;
    }
}