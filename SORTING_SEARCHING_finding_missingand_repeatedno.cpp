#include<bits/stdc++.h>
using namespace std;

int main(){
    int ar[]={1,2,3,5,1};
    int n =5;

    unordered_map<int,bool> map;

    for(int i:ar){
             if(map.find(i)!=map.end()){// means we have find the no in map
                cout<<"repeating no: "<<i<<endl;
             }
             else{
                 map[i]=true;
             }

         }
         for(int i=1;i<=n;i++){
             if(map.find(i)==map.end()){// means we have not found the no in map
                 cout<<" missing no: "<<i<<endl;
             }
         }
  
    return 0;
}