#include <iostream>
#include <stdio.h>
#include <vector>
#include<algorithm>

 using namespace std;




 int main(){
    int n;
    while(cin >> n){
        int carM, carL;
        cin >> carM >> carL;

        vector<vector<int>>cartasM;
        vector<vector<int>>cartasL;
        vector<int>carta;
        int x;
        for(int i = 0;i<carM;i++){
            carta.clear();
            for(int i = 0;i<n;i++){
                cin >> x;
                carta.push_back(x);
            }
            cartasM.push_back(carta);
        }
        for(int i = 0;i<carL;i++){
            carta.clear();
            for(int i = 0;i<n;i++){
                cin >> x;
                carta.push_back(x);
            }
            cartasL.push_back(carta);
        }
        int decM, decL, decA;
        cin >> decM >> decL >> decA;
        if(cartasM[decM-1][decA-1]>cartasL[decL-1][decA-1]){
            cout << "Marcos" << endl;
        }else if(cartasM[decM-1][decA-1]!=cartasL[decL-1][decA-1]){
            cout << "Leonardo" << endl;
        }else{
            cout << "Empate" << endl;
        }
    }
 }