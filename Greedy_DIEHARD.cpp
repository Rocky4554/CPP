#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define rep(i,a,b) for(int i=0;i<n;i++)
#define vec vector<int>


int main(){

    cout<<"Enter the starting health and armour health \n";
    ll h,a;
    cin>>h>>a;

    ll time=0;

    while(1){

        if(time%2==0){// means we are on air
            h +=3;
            a +=2;
        }
        else{
            if(a>10){// means water
                h -= 5;
                a -= 10;
            }
            else{// means fire
                h -=20;
                a +=5;
            }
        }
        if(a>0 && h>0 )// both health and armour are greater than 0 so it means we can surviue we are increasing the time here.
        time++;
        

        else 
        break;
        
    }
    cout<<"Total time of survival \n";
    cout<< time<<endl;

return 0;
}