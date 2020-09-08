
int GetfirstK(int *data, int length, int k, int start, int end) {
    if(start > end) return -1;

    int midID = (start + end) / 2;
    int middata = data[midID];

    if(middata == k) {
        if((midID > 0 && data[midID - 1] != k) || midID == 0)
            return midID;
        else end = midID - 1;
    }
    else if(middata > k)    end = midID - 1;
    else    start = midID + 1;

    return GetfirstK(data, length, k, start, end);
}

int GetlastK(int ) {
    if(start > end) return -1;

    int midID = (start + end) / 2;
    int middata = data[midID];

    if(middata == k) {
        if((midID < length - 1 && data[midID + 1] != k) || midID == length - 1)
            return midID;
        else  start = midID + 1;
    }
    else if(middata < k)    start = midID + 1;
    else    end = midID - 1;

    return GetlastK(data, length, k, start, end);
}

int GetnumofK(int* data, int length, int k) {
    int num = 0; 
    if(data != NULL && length > 0) {
        int first = GetfirstK(data, length, k, 0, length - 1);
        int last = GetlastK(data, length, k, 0, length -1 );
        
        if(first > -1 && last > -1)
            num = last - first + 1;
    }
    return num;
}