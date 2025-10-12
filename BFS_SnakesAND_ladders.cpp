#include<bits/stdc++.h>
using namespace std;

int main(){

    //enters the no of ladders and snakes
    cout<<"Enters the no of ladders\n";
    int ladders;
    cin>>ladders;

    // creating a map for storing all pair of ladders  and snakes
    map<int,int> ladd;//map for ladders 
    map<int,int> snak;//map for snakes


    cout<<"Enter all the ladders\n";
    for(int i=0;i<ladders;i++){
        int u,v;
        cin>>u>>v;
        ladd[u]=v;// setting in the map
    }

    cout<<"Enter the no of snakes\n";
    int snakes;
    cin>>snakes;

    cout<<"Enter all the snakes\n";
     for(int i=0;i<snakes;i++){
        int u,v;
        cin>>u>>v;
        snak[u]=v;// setting in the map
    }

    int moves=0;
    bool found = false;
    queue<int> que;
    que.push(1);// because we are initialing at position 1 in ludo
    vector<int> vis(101,0);
    vis[1]=true;// because at starting we are standing at 1

    while(!que.empty() && !found){
        int size=que.size();

        while(size--){
            int t=que.front();
            que.pop();

            for(int dice=1;dice<=6;dice++){// exploring all the possible moves in dice 
                if(t+dice==100)
                found=true;

                if(t+dice<=100 && ladd[t+dice] && !vis[ladd[t+dice]]){// for ladders
                    vis[ladd[t+dice]]=true;
                    if(ladd[t+dice]==100){
                        found=true;
                    }
                    que.push(ladd[t+dice]);  

                }
                
                 else if(t+dice<=100 && snak[t+dice] && !vis[snak[t+dice]]){//for snakes
                    vis[snak[t+dice]]=true;
                    if(snak[t+dice]==100){
                        found=true;
                    }
                    que.push(snak[t+dice]);  

                }
                else if(t+dice<=100 && !vis[t+dice] && !ladd[t+dice] && !snak[t+dice]){//for normal boxes in ludo
                    vis[t+dice]=true;
                    que.push(t+dice);
                    found = true;// not a neccesary step

                }

            }

        } moves++;// increasing the no of moves

    }

    if(found){
        cout<<"no of ladders required to win the game is "<<moves;
    }
    else{
        cout<<-1;
    }

    return 0;
}