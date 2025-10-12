#include <iostream>
using namespace std;

void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "#" << " ";
        }
        cout << endl;
    }
}

void print2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void print4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void print5(int n) {
    for (int i = 1; i <= 2 * n - 1; i++) {
        int stars = (i <= n) ? (2 * i - 1) : (2 * (2 * n - i) - 1);
        int spaces = (i <= n) ? (n - i) : (i - n);

        // Print spaces
        for (int j = 1; j <= spaces; j++) {
            cout << " ";
        }

        // Print stars
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }

        cout << endl;
    }
}

void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
    
        // number
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        // space 
        for (int j=1;j<2*n-2*i;j++){
            cout << " ";
        }
     // number
        for (int j = i; j >=1; j--)
        {
            cout << j;
            
        }

        cout << endl;
        
    }
}

void print7(int n)
{
    for (int i = 0; i < n; i++)
    {
    
        // space
        for (int j = 0; j <= n-i-1; j++)
        {
            cout << " ";
        }

        // character
        char ch ='A';
        int breakpoint = (2*i-1)/2;
        for (int j=1;j<=2*i-1;j++){
            cout << ch;
            if(j<=breakpoint){
                ch++;
            }
            else{
                ch--;
            }

        }
     // space
        for (int j = 0; j<n-i-1; j++)
        {
            cout << " ";
            
        }

        cout << endl;
        
    }
}

void print8(int n){

    char ch='E';
 for (int i=0;i<n;i++){
     char p=ch;
    for(int j=0;j<=i;j++){
       
        cout << p++;
    }
    ch--;
    cout<<endl;
 }
}

void print9(int n)
{
    int s1=8; int s2=2;
    for (int i = 1; i <=2*n-1; i++)
    {
        
        // part 2
    if (i>n){

        //star
        for (int j=1; j<=i-s2;j++){
            cout << '*';
        }
        //space
        for(int j=1;j<=s2;j++){
            cout << " ";
        }

         for (int j=1; j<=i-s2;j++){
            cout << '*';
        }
        s2 =s2+2;
    } else {
          // number
        for (int j = 1; j <= i; j++)
        {
            cout << '*';
        }

        // space 
        for (int j=1;j<=s1;j++){
            cout << " ";
            
        }
     // number
        for (int j = 1; j <=i; j++)
        {
            cout << '*';
            
        }
        s1 = s1-2;
    }
 
       cout << endl;   
        
    }
}

void print10(int n){
    int k=4;
    for (int p=n;p>=0;p=p-2){
    for(int i=0;i<p;i++){
     for (int j=0;j<n;j++){
        cout << k;
     }
    k--;
     cout << endl;
    }
    }
}


int main()
{
    int n;
    cin >> n;
    print10(n);
}