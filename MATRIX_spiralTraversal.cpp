#include<bits/stdc++.h>
using namespace std;

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

int left=0;int right=m-1;
int top=0;int bottom=n-1;

while(top<=bottom || left<=right){// running the loop till top<=bottom indicating there is a column to print and left<=right indicating there 
// is a row to print
    //top row
    for(int i=left;i<=right;i++){
        cout<<mat[top][i];
    }
    top++;
    //right column
    for(int i=top;i<=bottom;i++){
        cout<<mat[i][right];

    }
    right--;
    //bottom row
    if(top<=bottom){//this condition checks there is single row we can manage the case
        for(int i=right;i>=left;i--){
        cout<<mat[bottom][i];
        }
        bottom--;
    }
    // left column
    if(left<=right){// this condition checks there is single row we can manage the case
        for(int i=bottom;i>=top;i--){
        cout<<mat[i][top];
        }
        left++;
    }

}
    return 0;
}