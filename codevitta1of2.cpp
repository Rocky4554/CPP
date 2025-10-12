#include<bits/stdc++.h>
using namespace std;

int times(int n)
{

    bool ar[n + 1];
    memset(ar, true, sizeof(ar));
 
    for (int k = 2; k * k <= n; k++)
    {
    
        if (ar[k] == true)
        {
        
            for (int i = k * k; i <= n; i += k)
                ar[i] = false;
        }
    }
 
    int count=0;
    for (int j= 2; j <= n; j++)
        if (ar[j]) count++;
            return count;
}


int find(int n,int ans){


int remain=times(n);
n=n-remain;
// cout<<n<<endl;
 ans++;

if(n==1){
    return ans+1;
}else{
    // cout<<n<<endl;
    return find(n,ans);

}

}

int main(){

    int n;
    cout<<"Enter the no of emails\n";

    cin>>n;
    int ans=0;

    cout<<find(n,ans)<<endl;

    return 0;
}