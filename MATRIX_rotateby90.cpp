#include<bits/stdc++.h>    
using namespace std;
// function to swap elements
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


int main(){
cout<<"Enter rows and col \n";
int n,m;
cin>>n>>m;
vector<vector<int>> mat;

cout<<"Enter values\n";
// taking  user input in a  2D vector
for(int i=0;i<n;i++){
    vector<int> v1;
    for(int j=0;j<m;j++){
        int val;
        cin>>val;
        v1.push_back(val);
    }
    mat.push_back(v1);
}

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){  
        cout<<mat[i][j];
    }
    cout<<endl;
}    

// transposing the matrix
for(int i=0;i<n-1;i++){

    for(int j=i+1;j<m;j++){
        swap(&mat[i][j],&mat[j][i]);
    }
}
// reversing the transposed matrix
for(int i=0;i<n;i++){
    int s=0;int e=m-1;
    while(s<e){
        swap(&mat[i][s],&mat[i][e]);
        s++;
        e--;
    }
}
// finally printing the 90 degree reversed array
cout<<" rotated array \n";
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){  
        cout<<mat[i][j];
    }
    cout<<endl;
} 
    return 0;
}
