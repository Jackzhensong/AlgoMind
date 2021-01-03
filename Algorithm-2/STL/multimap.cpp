#include <bits/stdc++.h>
using namespace std;
struct studentinfo
{
    int id;
    char name[20];
};
struct student
{
    int score;
    studentinfo info;
};
typedef multimap<int, studentinfo> map_std;
int main()
{
    map_std mp;
    student st;
    char cmd[20];
    while (cin >> cmd)
    {
        if (cmd[0] == 'A')
        {
            cin >> st.info.name >> st.info.id >> st.score;
            mp.insert(make_pair(st.score, st.info));
        }
        else if (cmd[0] == 'Q')
        {
            int score;
            cin >> score;
            map_std::iterator p = mp.lower_bound(score);
            if (p != mp.begin())
            {
                --p;
                score = p->first;
                map_std::iterator maxp = p;
                int maxid = p->second.id;
                for (; p != mp.begin() && p->first == score; --p)
                {
                    if (p->second.id > maxid)
                    {
                        maxp = p;
                        maxid = p->second.id;
                    }
                }
                if (p->first == score)
                {
                    if (p->second.id > maxid)
                    {
                        maxp = p;
                        maxid = p->second.id;
                    }
                }
                cout << maxp->second.name << " "
                     << maxp->second.id << " "
                     << maxp->first << endl;
            }
            else
                cout << "Nobody" << endl;
        }
    }
    return 0;
}