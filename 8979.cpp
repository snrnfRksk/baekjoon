//https://www.acmicpc.net/problem/8979

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum EMedal
{
    GOLD,
    SILVER,
    BRONZE,
    MAX,
};

class Nation
{
    short m_nationCode = 0;
    int m_medalCount[EMedal::MAX] = { 0, };

public:

    void Init(short _nationCode, int _medalCounts[EMedal::MAX])
    {
        m_nationCode = _nationCode;
        for (int i = 0; i < EMedal::MAX; ++i)
        {
            m_medalCount[i] = _medalCounts[i];
        }
    }

    inline short GetNationCode() const { return m_nationCode; }
    inline int GetMedalCount(EMedal _medalType) const { return m_medalCount[_medalType]; }

    bool operator == (const Nation& _other)
    {
        return GetMedalCount(EMedal::GOLD) == _other.GetMedalCount(EMedal::GOLD) &&
            GetMedalCount(EMedal::SILVER) == _other.GetMedalCount(EMedal::SILVER) &&
            GetMedalCount(EMedal::BRONZE) == _other.GetMedalCount(EMedal::BRONZE);
    }

    bool operator < (const Nation& _other)
    {
        int medalCount = GetMedalCount(EMedal::GOLD);
        int otherMedalCount = _other.GetMedalCount(EMedal::GOLD);
        if (medalCount != otherMedalCount)
        {
            return medalCount < otherMedalCount;
        }

        medalCount = GetMedalCount(EMedal::SILVER);
        otherMedalCount = _other.GetMedalCount(EMedal::SILVER);
        if (medalCount != otherMedalCount)
        {
            return medalCount < otherMedalCount;
        }

        medalCount = GetMedalCount(EMedal::BRONZE);
        otherMedalCount = _other.GetMedalCount(EMedal::BRONZE);

        return medalCount < otherMedalCount;
    }
};

int main()
{
    short N, K;

    cin >> N >> K;

    vector<Nation> nations(N);

    Nation* targetNation = NULL;

    for (int i = 0; i < N; ++i)
    {
        short nationCode;
        int medalCounts[EMedal::MAX];
        cin >> nationCode >> medalCounts[EMedal::GOLD] >> medalCounts[EMedal::SILVER] >> medalCounts[EMedal::BRONZE];
        nations[i].Init(nationCode, medalCounts);

        if (nationCode == K)
        {
            targetNation = &nations[i];
        }
    }

    if (targetNation == NULL)
        return 0;

    int smallNationCount = 0;
    for (int i = 0; i < N; ++i)
    {
        Nation nation = nations[i];
        if (nation.GetNationCode() == K)
        {
            continue;
        }

        if (*targetNation < nation)
            ++smallNationCount;
    }

    cout << smallNationCount + 1 << endl;

    return 0;
}