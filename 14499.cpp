//https://www.acmicpc.net/problem/14499

#include <iostream>

using namespace std;

enum EDirection
{
	EAST = 1,
	WEST,
	NORTH,
	SOUTH,
	END,
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
			case EDirection::EAST:
			{
				RoleDirection_Front = EFace::RIGHT;
				RoleDirection_Back = EFace::LEFT;
				break;
			}
			case EDirection::WEST:
			{
				RoleDirection_Front = EFace::LEFT;
				RoleDirection_Back = EFace::RIGHT;
				break;
			}
			case EDirection::NORTH:
			{
				RoleDirection_Front = EFace::FRONT;
				RoleDirection_Back = EFace::BACK;
				break;
			}
			case EDirection::SOUTH:
			{
				RoleDirection_Front = EFace::BACK;
				RoleDirection_Back = EFace::FRONT;
				break;
			}
			default:
				return 0;
		}

		//주사위를 회전시킨 후
		short tempNumber = m_numbers[EFace::UP];
		m_numbers[EFace::UP] = m_numbers[RoleDirection_Back];
		m_numbers[RoleDirection_Back] = m_numbers[EFace::DOWN];
		m_numbers[EFace::DOWN] = m_numbers[RoleDirection_Front];
		m_numbers[RoleDirection_Front] = tempNumber;

		short returnValue = 0;
		//맵 숫자를 바닥에 복사하고
		if (_mapNumber == 0)
		{
			returnValue = m_numbers[EFace::DOWN];
		}
		else
		{
			m_numbers[EFace::DOWN] = _mapNumber;
			returnValue = 0;
		}

		//윗면을 Print한다
		cout << m_numbers[EFace::UP] << endl;

		return returnValue;
	}

private:
	short m_numbers[EFace::MAX];
};

int main()
{
	short n, m, x, y, k;

	cin >> n;	//size Y
	cin >> m;	//size X
	cin >> y;	//pos Y
	cin >> x;	//pos X
	cin >> k;	//Command Count

	char** map = new char* [n];

	for (short i = 0; i < n; ++i)
	{
		map[i] = new char[m];
		for (short j = 0; j < m; ++j)
		{
			int input;
			cin >> input;
			map[i][j] = (char)input;
		}
	}

	Dice* dice = new Dice();

	short command;
	for (int i = 0; i < k; ++i)
	{
		cin >> command;

		EDirection direction = (EDirection)command;
		switch (direction)
		{
			case EDirection::EAST:
			{
				if (x + 1 >= m)
					continue;

				++x;
				break;
			}
			case EDirection::WEST:
			{
				if (x - 1 < 0)
					continue;
				--x;
				break;
			}
			case EDirection::NORTH:
			{
				if (y - 1 < 0)
					continue;

				--y;
				break;
			}
			case EDirection::SOUTH:
			{
				if (y + 1 >= n)
					continue;

				++y;
				break;
			}
			default:
				continue;
		}

		int copyResultNumber = dice->Role(direction, map[y][x]);
		map[y][x] = copyResultNumber;
	}


	for (int i = 0; i < n; ++i)
	{
		delete[] map[i];
	}
	delete[] map;
	delete dice;

	return 0;
}