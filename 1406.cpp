//https://www.acmicpc.net/problem/1406

#include <iostream>
#include <list>

using namespace std;

int main()
{
    string input;
    cin >> input;

    list<char> charList;
    for (int i = 0; i < input.length(); ++i)
    {
        charList.push_back(input[i]);
    }

    int inputCount;
    cin >> inputCount;

    auto iterator = charList.end();

    for (int i = 0; i < inputCount; ++i)
    {
        char command;
        cin >> command;
        switch (command)
        {
            case 'L':
            {
                if (iterator == charList.begin())
                {
                    continue;
                }

                --iterator;

                break;
            }
            case 'D':
            {
                if (iterator == charList.end())
                {
                    continue;
                }

                ++iterator;
                break;
            }
            case 'B':
            {
                if (iterator == charList.begin())
                {
                    continue;
                }

                auto tempIterator = iterator;
                --tempIterator;

                charList.erase(tempIterator);
                break;
            }
            case 'P':
            {
                string addString;
                cin >> addString;

                for (int i = 0; i < addString.length(); ++i)
                {
                    charList.insert(iterator, addString[i]);
                }

                break;
            }
        }
    }

    for (iterator = charList.begin(); iterator != charList.end(); ++iterator)
    {
        cout << *iterator;
    }

    cout << endl;

    return 0;
}