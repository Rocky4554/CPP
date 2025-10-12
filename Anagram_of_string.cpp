#include<bits/stdc++.h>
using namespace std;
// sliding window apprroach

 vector<int> result(string str,string p,vector<int>& ans){
    unordered_map<char,int> mp;
    int i=0,j=0;
    int l=p.size();
    int n = str.size();
    for(int i=0;i<l;i++){
        mp[p[i]]++;   
    }

    int k=mp.size();

    while(j<n){
        mp[str[j]]--;

        if(mp[str[j]]==0){
            k--;
        }

        if(j-i+1 < l){
            j++;
        }
        else if(j-i+1 == l){// condition to check window size with formula (j-i+1);
            if(k==0){
                ans.push_back(i);
            }
            mp[str[i]]++;
            if(mp[str[i]]==1){
                k++;
            }
            i++;
            j++;
        }
    }

    return ans;


}

int main(){
    cout<<"Enter the string \n";
    string str;
    getline(cin,str);

    cout<<"Enter the Anagram \n";
    string p;
    getline(cin,p);

    vector<int> ans;

    vector<int> fr = result(str,p,ans);

    for(int i=0;i<fr.size();i++)
    cout<<fr[i]<<" ";


    return 0;
}