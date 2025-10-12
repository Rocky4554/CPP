#include<bits/stdc++.h>
using namespace std;

//chain hashing.
class Hash{

    int bucket;//no of elements in hashtable;
    list<int> *listt;//pointer to array cointaing bucket;

    public:

    Has(int v);// constructor of class Hash.

    void insertItem(int x);//  to insert a element in hashtable.
    void deleteItem(int key);// to delete a key from hashtable. 
    int hashFunc(int x){
        //hashfunction to map a key into hashtable.
        return (x % bucket);
    }
    void displayHash();
};

Hash::Has(int b)
{// constructor of class Hash.
    this->bucket=b;
    llist = new list<int>[bucket]; 
}

void Hash::insertItem(int x)
{
    int index = hasFunc(x);
    listt[index].push_back(x);
}

void Hash::delete(int x)
{
    int index=hasFunc(x);

    list<int>::iterator i;
    for(int i=listt[index].begin();i!=listt[index].end();i++){
        if(*i == key)
        break;
    }
    if(i!=table[index].end()){
    table[index].erase(i);
    }
} 

void display()
{
    for(int i=0;i<bucket;i++){
        cout<<i;
        for(auto x:listt[i]){
            cout<<"-->"<<x<<endl;
        }

    }
}

int main(){

    int ar[]={5,6,3,4,8};
    int n=sizeof(ar)/sizeof(ar[0]);

    Hash h(7);//Hash--class,h--object of class.passing 7 in constructor.

    for(int i=0;i<n;i++){
    h.insertItem(ar[i]);}

    h.deleteItem(12);

    h.displayHash();

    return 0;
}



