#include<iostream>
#include<vector>
using namespace std;

int weired_array(int n, int arr[])
{
    if(n<2)
    {
        return 0;
    }

    vector<int> aar;
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i]==arr[j])
            cnt++;
            else{
                aar.push_back(cnt);
                cnt=0;
                break;
            }
        }

    }

    int maxm = 0;
    for(int x:aar)
    {
        if(x>maxm)
        {
            maxm = x;
        }
    }
    
    return maxm;
}


int main()
{

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];

    cout<<weired_array(n,arr)<<endl;

    // vector<int>arr1 = {3,3,1,3,3};
    // cout<<weired_array(arr1)<<endl;

    // vector<int>arr2 = {5};
    // cout<<weired_array(arr2)<<endl;

    

    return 0;
}