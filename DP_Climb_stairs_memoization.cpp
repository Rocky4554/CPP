#include<bits/stdc++.h>
using namespace std;

int climb(int n,int qb[]){
        if(n==0){
        return 1;
        }
        
        else if(n<0)
        {
            return 0;
        }
        
        if(qb[n]!=-1)
        {
            
            return qb[n];
        }
        
        int r1=climb(n-1,qb);
        int r2=climb(n-2,qb);
        
        int fr=r1+r2;
        qb[n]=fr;
        return fr;
        
    }  
    
    
    int climbStairs(int n) {
        int qb[n+1];
        // for(int i=0;i<n;i++){
        //     qb[i]=-1;
        // }
        memset(qb,-1,sizeof(qb));
        
        return climb(n,qb);
    
     
    }

int main(){
    
int n;
cout<<"Enter the no of stairs\n";
cin>>n;
//he is alllowed to take only 1 or 2 steps at a time.

cout<<climbStairs(n);
    return 0;
}