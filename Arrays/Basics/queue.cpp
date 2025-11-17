#include<bits/stdc++.h>
using namespace std;

void show(queue<int> q1){
queue<int> g=q1;
while(!g.empty()){
cout<<g.front()<<" ";
g.pop();
}
}

int main(){

queue<int> q1;
q1.push(1);
q1.push(4);
q1.push(5);
q1.push(7);
q1.push(2);

show(q1);
cout<<"after pop: \n";
q1.pop();
show(q1);
cout<<q1.back();

    return 0;
}