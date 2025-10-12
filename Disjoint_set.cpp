#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int ranking[100000];

void makeset(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        ranking[i]=0;
    }
}

int findparent(int node){
    if(node=parent[node]){
        return node;
    }
    return parent[node] = findparent(parent[node]);
}

void makeunion(int u,int v){

    u=findparent(u);
    v=findparent(v);

    if(ranking[u]<ranking[v]){// if rank of v is greater than .
         parent[u]=v;// u will get attached to v(v will baecome the ultimate parent).
    }
    else if(ranking[v]<ranking[u]){
         parent[v]=u;// else if v will get attached to u and u will become ultimate parent.
    }
    else{// else if both are equal the either of them can be parent of any one of them.
        parent[u]=v;// here we are supposing v has got connected to u(u has become ultimate parent).
        ranking[v]++;// as v has got attached to u so rank of v increses.
    }

}


int main()
{

    makeset();
    int n;
    while(n--){
        int u ,v;
        makeunion(u,v);
    }
    if(findparent(2)!=findparent(3)){
        cout<<"They belong to differnt component\n";

    } 
    else{
        cout<<"They belong to same component\n";
    }   

 return 0;
}