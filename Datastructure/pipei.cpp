
void BracketMarch(char *str)
{
    stack<char> s;
    char ch;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        switch (str[i])
        {
        case '(':
        case '[':
        case '{':
            s.push(str[i]);
            break;
        case ')':
        case ']':
        case '}':
            if (s.isempty())
            {
                cout << "右括号多余" << endl;
                return;
            }
            else
            {
                ch = s.top();
                if (Match(ch, str[i])) // if(strcmp(ch, str[i]) == 0)
                    ch = s.pop();
                else
                {
                    cout << "don't match" << endl;
                    return;
                }
            }
        }
    }
    if (s.isempty())
        cout << "bracketmatch" << endl;
    else
        cout << "左括号多余" << endl;
}


// c的顺序栈
void BracketMarch(char *str)
{
    SeqStack s;
    char ch;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        switch (str[i])
        {
        case '(':
        case '[':
        case '}':
            Push(&s, str[i]);
            break;
        case ')':
        case ']':
        case '}':
            if (Isempty(&s))
            {
                printf("\n 右括号多余");
                return;
            }
            else
            {
                Gettop(&s, &ch);
                if (Match(ch, str[i]))
                    Pop(&s, &ch);
                else
                {
                    printf("\n括号不匹配");
                    return;
                }
            }
        }
    }
    if (Isempty(&s))
        printf("\n 括号匹配");
    else
        prinf("\n 左括号多余");
}
