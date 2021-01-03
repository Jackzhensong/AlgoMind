#include<iostream>
#include<cstring>
using namespace std;

int r, c;
int rooms[60][60], color[60][60];
int maxRoomArea = 0, roomNum = 0;
int roomArea;

void dfs(int i, int k) {
    if(color[i][k]) return;     // 剪枝
    ++roomArea;
    color[i][k] = roomNum;      // 染色
    
    if((rooms[i][k] & 1) == 0) dfs(i, k-1);
    if((rooms[i][k] & 2) == 0) dfs(i-1, k);
    if((rooms[i][k] & 4) == 0) dfs(i, k+1);
    if((rooms[i][k] & 8) == 0) dfs(i+1, k);
}

int main() {
    cin >> r >> c;
    for(int i = 1; i <= r; ++i) 
        for(int k = 1; k <= c; ++k) 
            cin >> rooms[i][k];
    memset(color, 0, sizeof(color));

    for(int i = 1; i <= r; ++i) 
        for(int k = 1; k <= c; ++k) {
            if(color[i][k] == 0) {
                ++roomNum;
                roomArea = 0;
                dfs(i, k);
                maxRoomArea = max(roomArea, maxRoomArea);
            }
        }
    cout << roomNum << endl << maxRoomArea << endl;
    return 0;
}