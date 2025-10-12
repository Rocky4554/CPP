#include <bits/stdc++.h>
using namespace std;
int main()
{


    char a[10000001];
    cin>>a;

    int no_of_operations = 0;

    for(int i=0; i<strlen(a)/2; i++){
      no_of_operations += abs( a[strlen(a)-i-1] - a[i] );
    }

    cout<<no_of_operations<<endl;


}