#include<bits/stdc++.h>
using namespace std;

int main(){

   int contributors , projects;
    cin >> contributors >> projects;
    
    // Skills of each
    map<string,map<string,int>> mp;
    for ( int i = 0 ; i < contributors ; i++ )
    {
        string name; cin >> name;
        int total_skills; cin >> total_skills;

        while ( total_skills-- )
        {
            string skill; int level;
            cin >> skill >> level;
            mp[name][skill] = level;
        }
    }
    for ( int i = 0 ; i < projects ; i++ )
    {
        string pname; cin >> pname;
        int nd,points,bd;
        cin>>nd>>points;
        int t_skills; cin >> t_skills;

        while ( t_skills-- )
        {
            string skill; int level;
            cin >> skill >> level;
            mp[pname][skill] = level;
        }
    }

    

    return 0;

}