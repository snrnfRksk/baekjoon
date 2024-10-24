//https://www.acmicpc.net/problem/1244

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    short switchCount;
    cin >> switchCount;

    vector<bool> switchStates(switchCount);
    bool switchState;
    for (int i = 0; i < switchCount; ++i)
    {
        cin >> switchState;
        switchStates[i] = switchState;
    }

    short studentCount;
    cin >> studentCount;
    for (int i = 0; i < studentCount; ++i)
    {
        short gender;
        short switchNumber;
        cin >> gender >> switchNumber;

        short switchIndex = switchNumber - 1;
        if (gender == 1)
        {
            //남학생
            for (int i = switchIndex; i < switchCount; i += switchNumber)
            {
                switchStates[i] = !switchStates[i];
            }
        }
        else
        {
            //여학생
            switchStates[switchIndex] = !switchStates[switchIndex];
            for (int i = 1; switchIndex - i >= 0 && switchIndex + i < switchCount; ++i)
            {
                if (switchStates[switchIndex + i] != switchStates[switchIndex - i])
                    break;

                switchStates[switchIndex - i] = switchStates[switchIndex + i] = !switchStates[switchIndex + i];
            }
        }
    }

    const short interval = 20;
    short share = switchCount / 20;
    for (short i = 0; i < share; ++i)
    {
        short startIndex = i * interval;
        for (int j = startIndex; j < startIndex + interval; ++j)
        {
            cout << switchStates[j] << " ";
        }

        cout << endl;
    }

    short startIndex = share * interval;
    for (short i = startIndex; i < switchCount; ++i)
    {
        cout << switchStates[i] << " ";
    }

    cout << endl;
}