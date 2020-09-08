

bool farmer(int status) {
    return ((status & 0x08) != 0);
}
bool wolf(int status) {
    return ((status & 0x04) != 0);
}
bool cabbage(int status) {
    return ((status & 0x02) != 0);
}
bool goat(int status) {
    return ((status & 0x01) != 0);
}

bool safe(int status) {
    if((goat(status) == cabbage(status)) && 
        (goat(status) != farmer(status)))
        return false;
    if((goat(status) == wolf(status)) && 
        (goat(status) != farmer(status)))
        return false;
    return true;
}

void solve() {
    int movers, i, location, newlocation;
    vector<int> route(END + 1, -1);
    queue<int> moveTo;
    moveTo.push(0x00);
    route[0] = 0;
    while(!moveTo.empty() && route[15] == -1) {
        status = moveTo.front();
        moveTo.pop();
        for(movers = 1; movers <= 8; movers <<= 1) {
            if(farmer(status) == (bool) (status & movers)) {
                neewstatus = status ^ (0x08 | movers);
                if(safe(neewstatus) && (route[neewstatus] == -1)) {
                    route[neewstatus] = status;
                    moveTo.push(neewstatus);
                }
            }
        }
    }
    if(route[15] != -1) {
        cout << "The reverse path is:" << endl;
        for(int status = 15; status >= 0; status = route[status]) {
            cout << "The status is: " << status << endl;
            if(status == 0) break;
        }
    }
    else cout << "No solution" << endl;
}