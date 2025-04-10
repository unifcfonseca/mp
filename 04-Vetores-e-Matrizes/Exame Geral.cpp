#include <iostream>
#include <stdio.h>
#include <vector>
#include<algorithm>

 using namespace std;




 int main(){
    int nCid,nCon;
    while(cin >> nCid){
        cin >> nCon;
        vector<int>notas;
        vector<int>consultas;
        for(int i = 0;i<nCid;i++){
            int x;
            cin >> x;
            notas.push_back(x);
        }
        for(int i = 0; i<notas.size()-1;i++){
            for(int j = 0;j<notas.size()-1-i;j++){
                if(notas[j]>notas[j+1]){
                     int x = notas[j];
                     notas[j] = notas[j+1];
                     notas[j+1] = x;
                }
            }
        }

        for(int i = 0;i<nCon;i++){
            int x;
            cin >> x;
            cout << notas[nCid-x] << endl;
        }
    }
 }
 