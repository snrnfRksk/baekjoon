//https://www.acmicpc.net/problem/2292

#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int roomCount = 1;
    int maxNumber = 1;
    while (maxNumber < N)
    {
        maxNumber += 6 * roomCount;
        ++roomCount;
    }

    cout << roomCount << endl;

    return 0;
}