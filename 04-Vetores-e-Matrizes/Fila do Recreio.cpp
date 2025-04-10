#include <iostream>
#include <stdio.h>
#include <vector>
#include<algorithm>

 using namespace std;

 int main(){
    int n;
    cin >> n;
    while(n--){
        int tamFila;
        cin >> tamFila;
        vector<int>fila;
        vector<int>filaEsp;
        int total = tamFila;
        for(int i = 0;i<tamFila;i++){
            int x;
            cin >> x;
            fila.push_back(x);
            filaEsp.push_back(x);
        }
        reverse(fila.begin(),fila.end());
        for(int i = 0; i<tamFila-1;i++){
            for(int j = 0;j<tamFila-1-i;j++){
                if(fila[j]>fila[j+1]){
                     int x = fila[j];
                     fila[j] = fila[j+1];
                     fila[j+1] = x;
                }
            }
        }
        reverse(fila.begin(),fila.end());
        for(int i = 0;i<fila.size();i++){
            if(fila[i]!=filaEsp[i]){
                total--;
            }
        }
        cout << total << endl;
    }
 }