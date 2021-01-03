
// 字符串切割， str - 原串， temp - 分割符号
vector<string> split(string str, const string &temp) {
    vector<string> ret;

    char* s = new char[strlen(str.c_str() + 1)];   // str.c_str()   字符串转为字符数组
    strcpy(s, str.c_str());
    
    char* p = strtok(s, temp.c_str());
    while (p != NULL) {
        ret.push_back(p);
        p = strtok(NULL, temp.c_str());
    }

    delete[] s;
    return ret;
}