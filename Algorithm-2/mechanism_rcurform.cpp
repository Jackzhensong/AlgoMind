typedef struct elem {
    int rd, pn, pf, q1, q2;
}ELEM；
class nonrec {
    private:
        stack<ELEM> S;
    public:
        nonrec(void) { }
        void replacel(int n, int& f);
};

void nonrec::replacel(int n, int& f) {
    ELEM x, tmp;
    x.rd = 3;
    x.pn = n;
    S.push(x);
    label 0: if((x = S.top()).pn < 2) {
        S.top();
        x.pf = x.pn + 1;
        S.push(x);
        goto label 3;
    }
    x.re = 1;
    x.pn = (int) (x.pn/2);
    S.push(x);
    goto label 0;
    
    label 1: tmp = S.top();
            S.pop();
            x = S.top();
            S.pop();
            x.q1 = tmp.pf;
            S.push(x);
            x.pn = (int) (x.pn/4);
            x.rd = 2;
            S.push(x);
            goto label 0;
    label 2: tmp = S.top();
            S.pop();
            x = S.top();
            S.pop();
            x.q2 = tmp.pf;
            x.pf = x.q1 * x.q2;
            S.push(x);
    label 3: x = S.top();
            switch(x.rd) {
                case 1: goto label 1; break;
                case 2: goto label 2; break;
                case 3: tmp = S.top();
                        S.pop();
                        f = tmp.pf;
                        break;
                default: cerr << "error label number in stack";
                break;
            }
}