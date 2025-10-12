#include<bits/stdc++.h>
using namespace std;


void solution(int n)
{

    bool ar[n + 1];
    memset(ar, true, sizeof(ar));
 
    for (int k = 2; k * k <= n; k++)
    {
    
        if (ar[k] == true)
        {
        
            for (int i = k * k; i <= n; i += k)// muliple of k;
                ar[i] = false;
        }  
    }
 
    int count=0;
    for (int j= 2; j <= n; j++)
        if (ar[j]==true){
            count++;
             cout<<j<<" ";

        }
            cout << endl<<count;
           
        
        
}
 

int main()
{
    int n;
    cin>>n;
    solution(n);

    return 0;
}