#include<bits/stdc++.h>
using namespace std;
char mapn[]="222333444555666777788889999";
char str[80], telnum[100000][9];

int compare(const void *elem1,const void* elem2){
    return (strcmp ((char*)elem1,(char*)elem2));
}
void standard(int n) {
    int j,k;
    j=k=-1; 
    while(k<8) {
        j++;
        if(str[j]=='-') continue;
        k++;
        if(k==3) {
            telnum[n][k]='-';
            k++;
        }
        if(str[j]>='A'&&str[j]<='Z') {
            telnum[n][k]=mapn[str[j]-'A'];
            continue;
        }
        telnum[n][k]=str[j];
    }
    telnum[n][k]='\0';
    return;
}

int main() {
    int n,i,j;
    bool noduplicate;
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>str;
        standard(i);
    }
        qsort(telnum,n,9,compare);
        noduplicate=true;
        i=0;
        while(i<n){
            j=i;
            i++;
            while(i<n&&strcmp(telnum[i],telnum[j])==0) i++;
            if(i-j>1){
                cout<<telnum[j]<<" "<<i-j<<endl;
                noduplicate=false;
            }
        }
        if(noduplicate)
            cout<<"No duplicates"<<endl;
}