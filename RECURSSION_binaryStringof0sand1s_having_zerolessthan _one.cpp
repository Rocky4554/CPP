#include<bits/stdc++.h>
using namespace std;
void find(string str,int n,int zeros,int ones){
if(ones < zeros){
return;
}

if(n==0)
{
    cout<<str<<endl;
    return;
}

find(str+"1",n-1,zeros,ones + 1);
find(str+"0",n-1,zeros+1,ones);
}
int main(){
    int n=4;
    string str;
    find(str,n,0,0);

    return 0;
}