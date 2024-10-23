//https://www.acmicpc.net/problem/13458

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int N, B, C;

    cin >> N;

    vector<int> A(N, 0);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    cin >> B >> C;

    long long result = 0;
    for (int i = 0; i < N; ++i)
    {
        int addValue = 1 + max(0, (int)ceil((A[i] - B) / (float)C));
        result += addValue;
    }

    cout << result << endl;
    
    return 0;
}