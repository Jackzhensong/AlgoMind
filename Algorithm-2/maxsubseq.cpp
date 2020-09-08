

int maxsubseqSum(int a[], int N)   //最大子列和
{
    int thissum, maxsum;
    thissum = maxsum = 0;
    for(int i = 0; i < N; ++i){
        thissum += a[i];
        if(thissum > maxsum) maxsum = thissum;
        else if(thissum < 0) thissum = 0;
    }
    return maxsum;
}