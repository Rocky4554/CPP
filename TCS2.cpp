#include<bits/stdc++.h>
using namespace std;

int main(){

    cout<<"Enter the no of players and total time \n";
    int n,m;
    cin>>n>>m;
    cout<<"Enter the three distances \n";
    int d1,d2,d3;
    int ar1[m],ar2[m],ar3[m];
    int ans[3];
    memset(ans,0,sizeof(ans));
    int s1=0,s2=0,s3=0;

    for(int i=1;i<=m;i++){
        cin>>ar1[i];
    }

    for(int i=1;i<=m;i++){
        cin>>ar2[i];
    }

    for(int i=1;i<=m;i++){
        cin>>ar3[i];
    }

    for(int i=1;i<=m;i++){
        int maxx=0;
        s1=s1+ar1[i]*d1;
        s2=s2+ar2[i]*d2;
        s3=s3+ar3[i]*d3;

        if(i%2==0){
             maxx=max(s1,max(s2,s3));
        }

        if(maxx==s1){
            ans[1] +=1;
        }
        else if(maxx==s2){
            ans[2] +=1;
        }
        else{
            ans[3] +=1;
        }
        maxx=0;
    }
     for(int i=1;i<=3;i++){
         cout<<ans[i]<<endl;
     }

    return 0;
}