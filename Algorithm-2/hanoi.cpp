
void move(char x,char y){
    cout<< x <<" -> " << y << endl;
}

void hanoi(int n,char one,char two,char three)
{
    if(n==1) move(one, three);
    else
    {
        hanoi(n-1, one, three, two);
        move(one, three);
        hanoi(n-1, two, one, three);
    }
}