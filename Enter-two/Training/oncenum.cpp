
void Findonce(int* data, int length, int* num1, int* num2) {
    if(data == NULL || length < 2) return;

    int resultOR = 0;
    for(int i = 0; i < length; ++i) 
        resultOR ^= data[i];

    unsigned int idof1 = Findfirstbit1(resultOR);
    *num1 = *num2 = 0;
    for(int j = 0; j < length; ++j) {
        if(isbit1(data[j], idof1))
            *num1 ^= data[j];
        else *num2 ^= data[j];
    }
}

unsigned int Findfirstbit1(int num){
    int idof1 = 0;
    while(((num & 1) == 0) && (idbit < 8 * sizeof(int)))
    {
        num = num >> 1;
        ++idbit;
    }
    return idbit;
}

bool isbit1(int num, unsigned int idbit) {
    num = num >> idbit;
    return (num & 1);
}