//https://www.acmicpc.net/problem/2164

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    queue<int> deck;
    for (int i = 2; i <= N; i += 2)
    {
        deck.push(i);
    }

    if (N % 2 == 1)
    {
        int front = deck.front();
        deck.pop();
        deck.push(front);
    }

    while (deck.size() > 1)
    {
        deck.pop();
        int front = deck.front();
        deck.pop();
        deck.push(front);
    }

    cout << deck.front() << endl;

    return 0;
}