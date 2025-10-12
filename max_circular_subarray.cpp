#include<bits/stdc++.h>
using namespace std;
int kadan(int ar[],int n){
   int Omax=0;int Cmax=0;
    for(int i=0; i<n; i++){
        Cmax = Cmax + ar[i];
        if(Omax<Cmax){
            Omax=Cmax;

        }
        if(Cmax<0){
            Cmax=0;
        }
    }
    return Omax;
}

int maxcircular(int ar[],int n){

int max_kadan =kadan(ar,n);

int sum=0;
for(int i=0; i<n; i++){
    sum += ar[i];
    ar[i] = -ar[i];
}
int maxsum= sum+ kadan(ar,n);
return (maxsum>max_kadan)?maxsum:max_kadan;
}


int main()
{
    int ar[]={4,-4,6,-6,10,-11,12};
    int n = sizeof(ar)/sizeof(ar[0]);
    cout<<"sum"<<endl;
    cout<<maxcircular(ar,n);
    return 0;
}
