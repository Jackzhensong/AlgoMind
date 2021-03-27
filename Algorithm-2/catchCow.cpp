#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 100000;
int visited[MAX + 10];

struct Step
{
    int x;
    int steps;
    Step(int xx, int s) : x(xx), steps(s) {}
};

queue<Step> q;

int main()
{
    int N, K;
    cin >> N >> K;
    memset(visited, 0, sizeof(visited));
    q.push(Step(N, 0));
    visited[N] = 1;
    while (!q.empty()) {
        Step s = q.front();
        if (s.x == K) {
            cout << s.steps << endl;
            return 0;
        }
        else {
            if (s.x - 1 >= 0 && !visited[s.x - 1]) {
                q.push(Step(s.x - 1, s.steps + 1));
                visited[s.x - 1] = 1;
            }
            if (s.x + 1 <= MAX && !visited[s.x + 1]) {
                q.push(Step(s.x + 1, s.steps + 1));
                visited[s.x + 1] = 1;
            }
            if (s.x * 2 <= MAX && !visited[s.x * 2]) {
                q.push(Step(s.x * 2, s.steps + 1));
                visited[s.x * 2] = 1;
            }
            q.pop();
        }
    }
    return 0;
}
