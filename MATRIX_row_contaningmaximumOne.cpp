#include<bits/stdc++.h>
using namespace std;

int main(){

cout<<"Enter no of rows and column\n";
int r,c;
cin>>r>>c;

int ar[r][c];
cout<<"Enter the values in matrix\n";
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cin>>ar[i][j];
    }
}
int mx=0;int i=0;
int row=i;int cn;
for(i=0;i<r;i++){
    cn=0;
    for(int j=0;j<c;j++){
        if(ar[i][j]==1){
            cn++;
        }
    }
    if(mx < cn){
        mx=cn;
        row=i;
    }  
}

cout<<"Row number :"<<row<<" is containing maximum no of 1 which is :"<<mx<<endl;

    return 0;
}