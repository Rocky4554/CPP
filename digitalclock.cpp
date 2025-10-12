#include<bits/stdc++.h>
#include<stdlib.h>//lib for cls
#include<unistd.h>//lib for sleep and unsleep function .
using namespace std;

int main(){
cout<<"Enter the time in HH:MM:SS\n";
    int h,m,s;
    cin>>h >>m >>s;

    while(true){// runnning a infinite loop.
         system("cls");//clearing  the scren like clrscr() in c.
        cout<<"\t^^^^^^^\n";
        cout<<"\t|\n";
        cout<<"\t|";
         cout<<h<<":"<<m<<":"<<s<<endl;// displaying the time
         cout<<"\t-------\n";
         s++;
         if(s==60){
             m++;
             s=0;
         
         if(m==60){
             h++;
             m=0;
         
         if(h==24){
             h=0;
         }
         }
         }
         sleep(1);
    }

    return 0; 
}