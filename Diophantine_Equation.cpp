#include<bits/stdc++.h>
using namespace std;


    int ext_gcd(int a, int b, int &x, int &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }

        // recursively finding the solution
        int d = ext_gcd(b, a % b,x,y);  
        int x1=x,y1=y;// storing value of x and y returned from the function ext_gcd in (x1 and y1);
        x = y1;
        y = x1 - (a / b) * y1;

        return d;

    }
    void diophantine(int a,int b,int c){

        if(a==0 && b==0){
            if(c==0){
                cout<<"Infinite Solution exits\n";
            }
            else{
                cout<<"No solution exits\n";
            }
        }

        int x,y;

        int gcd = ext_gcd(a,b,x,y);
        if(c%gcd!=0){
            cout<<"Solution does not exits\n";
        }
        else{

            cout<<"x:"<< x*(c/gcd)<<"y:"<<y*(c/gcd)<<endl; 

        }

    }

int main(){

    int a,b,c;
    cin>>a>>b>>c;

    diophantine(a,b,c);

    return 0;
 }
    

