#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subarray(int ar[],int n,vector<vector<int>>& result){
 for(int i=0;i<n;i++){
    vector<int> v;
    for(int j=i;j<n;j++){
        v.push_back(ar[j]);
        result.push_back(v);
    }
    // result.push_back(v);
 }
 return result;
}


int main(){

int n;
cin>>n;

int ar[n];
for(int i=0;i<n;i++){
    cin>>ar[i];
}

vector<vector<int>> result,ans;
ans=subarray(ar,n,result);
cout<<"All subarray are :\n";
 for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

return 0;
}