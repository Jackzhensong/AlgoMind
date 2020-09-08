
//压缩矩阵，三元组法
a[0][0] = n;  
a[0][1] = m;
for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    if(s[i][j]){
        a[tmp][0]= i;
        a[tmp][1]= j;
        a[tmp][2]= s[i][j];
        tmp++;
        size++;
    }
a[0][2]=size;