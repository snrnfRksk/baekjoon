//https://www.acmicpc.net/problem/14499

#include <iostream>
#include <vector>

using namespace std;

enum EDirection
{
    EAST = 1,
    WEST,
    NORTH,
    SOUTH,
};

class Dice
{
public:
    enum EFace
    {
        UP,
        FRONT,
        RIGHT,
        LEFT,
        BACK,
        DOWN,
        MAX,
    };

    short Role(EDirection _moveDireciton, short _mapNumber)
    {
        EFace RoleDirection_Front;
        EFace RoleDirection_Back;
        switch (_moveDireciton)
        {
            case EAST:
                RoleDirection_Front = RIGHT;
                RoleDirection_Back = LEFT;
                break;
            case WEST:
                RoleDirection_Front = LEFT;
                RoleDirection_Back = RIGHT;
                break;
            case NORTH:
                RoleDirection_Front = FRONT;
                RoleDirection_Back = BACK;
                break;
            case SOUTH:
                RoleDirection_Front = BACK;
                RoleDirection_Back = FRONT;
                break;
            default:
                return 0;
        }

        short tempNumber = m_numbers[UP];
        m_numbers[UP] = m_numbers[RoleDirection_Back];
        m_numbers[RoleDirection_Back] = m_numbers[DOWN];
        m_numbers[DOWN] = m_numbers[RoleDirection_Front];
        m_numbers[RoleDirection_Front] = tempNumber;

        cout << m_numbers[UP] << endl;

        if (_mapNumber == 0)
        {
            return m_numbers[DOWN];
        }
        else
        {
            m_numbers[DOWN] = _mapNumber;
            return 0;
        }
    }

private:
    short m_numbers[EFace::MAX] = { 0, };
};

int main()
{
    short n, m, x, y, k;

    cin >> n >> m >> y >> x >> k;

    vector<vector<int>> map(n, vector<int>(m, 0));

    for (short i = 0; i < n; ++i)
    {
        for (short j = 0; j < m; ++j)
        {
            cin >> map[i][j];
        }
    }

    Dice dice;

    short command;
    for (int i = 0; i < k; ++i)
    {
        cin >> command;
        EDirection direction = static_cast<EDirection>(command);

        switch (direction)
        {
            case EAST:
                if (x + 1 >= m) continue;
                ++x;
                break;
            case WEST:
                if (x - 1 < 0) continue;
                --x;
                break;
            case NORTH:
                if (y - 1 < 0) continue;
                --y;
                break;
            case SOUTH:
                if (y + 1 >= n) continue;
                ++y;
                break;
            default:
                continue;
        }

        int copyResultNumber = dice.Role(direction, map[y][x]);
        map[y][x] = copyResultNumber;
    }

    return 0;
}