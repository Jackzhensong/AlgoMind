
// 括号匹配--栈实现
void BracketMatch(char *str) {
    stack<char> s;
    char ch;
    for (int i = 0; str[i] != '\0'; ++i) {
        switch (str[i]) {
        case '(':
        case '[':
        case '{':
            s.push(str[i]);
            break;
        case ')':
        case ']':
        case '}':
            if (s.empty()) {
                cout << "right bracket redundance" << endl;
                return;
            }
            else {
                ch = s.top();
                if (ch == str[i] - 1 || ch == str[i] - 2) 
                    s.pop();
                else {
                    cout << "don't match" << endl;
                    return;
                }
            }
        }
    }
    if (s.empty())
        cout << "bracket match" << endl;
    else
        cout << "left bracket redundance" << endl;
}
