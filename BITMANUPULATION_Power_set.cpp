#include<bits/stdc++.h>
using namespace std;

void getPowerSet(string str) {
        // string str1=" ";
		int n = str.size();
		int total = 1<<n;
		for (int i = 0; i < total; i++) {
			
			for (int j = 0; j < n; j++) {
				//Printing all elements for which there is a bit one in i
				if((i & (1<<j)) != 0){
                    // str1 = str1 + str[j];
                    // cout<<str1;
					cout<<str[j];
				}
			}
            cout<<endl;
		}
		
	}
int main(){
    

string str;
getline(cin,str);

getPowerSet(str);

    return 0;
}