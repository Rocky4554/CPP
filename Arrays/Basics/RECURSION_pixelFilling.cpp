#include<bits/stdc++.h>
using namespace std;

void fill(int m[][6], int i,int j,int tofill,int prev){


    if(i<0 || i>=3 || j<0|| j>=6){
    return;
    }
    if(m[i][j]==tofill){//if equal to new color to be filled,
    return;
    }
    if(m[i][j]!=prev){
        return;
    }
m[i][j]=tofill;
fill(m,i+1,j,tofill,prev);
fill(m,i,j+1,tofill,prev);
fill(m,i-1,j,tofill,prev);
fill(m,i,j-1,tofill,prev);
}

// void print(int m[3][6]){
// for(int i=0;i<3;i++){
//     for(int j=0;j<6;j++){
//         cout<<m[i][j]<<" ";
//     }
//         cout<< endl;
    
// }
// }

int  main(){
    int m[3][6]={{1,1,1,1,1,1},{2,2,2,2,1,2},{1,1,1,2,1,2}};
    fill( m,0,0,0,1);
    // print(m);
    for(int i=0;i<3;i++){
    for(int j=0;j<6;j++){
        cout<<m[i][j]<<" ";
    }
        cout<< endl;
    
}
    


}