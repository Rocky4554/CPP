#include<bits/stdc++.h>
using namespace std;

struct node{

    int s;
    int d;
    int wt;

    node(int first,int ,int second,int weight){
        s=first;
        d=second;
        wt=weight;

    }
};

bool campare(node a,node b){// we are comapring here two node;
    return (a.wt< b.wt)
        
}

int findparent(int s,vector<int> &parent){
    if(s==parent[s]) return s;
        return findparent(parent[s],parent);// we are not using path  compression method here.

}

void makeunion(int s.int d,vector<int> &parent,vector<int> &rank){
    s=findparent(s,parent);//here we are calling findparent function to find the parent of s
    d=findparent(d,parent);//similar for d

    if(rank[s]<rank[d]){
        parent[s]=d;

    }
    else if(rank[d]<rank[s]){
        parent[d]=s;
    }else{
        parent[s]=d;
        rank[d]++;
    }
}

int main(){

    cout<<"Enter the no of vertices and edges\n";
    int v,e;
    cin>>v>>e;

    vector<node> graph;
    cout<<"Enter the "<< e<<" edges\n";
    for(int i=0;i<e;i++){
    int s,d,wt;
    cin >> s >> d >> wt;

    graph.push_back(node(s,d,wt));
    }

    sort(graph.begin(),graph.end(),camapre);//sorting of vector/if array then sort(ar,ar+n) where ar = array and n=size of array
    vector<int> parent(v);
    for(int i=0;i<v;i++)
        parent[i]=i;
        //rank[i]=0;
        vector<int> rank(v,0);
    

    int cost=0;
   
    vector<pair<int,int>> mst;

    for(auto it:graph){
        if(findparent(it.d,parent)!=findparent(it.s,parent)){
            cost += it.wt;
            mst.push_back(make_pair(it.s,it.d));
            makeunion(it.s,it.d,parent,rank);
        }
    }

    cout<< cost<<endl;

    for(auto it : mst){
        cout<<it.first<<"-->"<<it.second<<endl;

    }

    return 0;
}