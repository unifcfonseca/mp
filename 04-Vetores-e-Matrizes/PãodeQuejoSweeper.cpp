#include <iostream>
#include <stdio.h>
#include <vector>
#include<algorithm>

 using namespace std;

 int main(){
    int linhas,colunas;
    while(cin >> linhas){
            cin >> colunas;
        
            int mapa[linhas+2][colunas+2];
            int mapa2[linhas][colunas];

            for(int i = 0;i<linhas+2;i++){
                for(int j = 0;j<colunas+2;j++){
                    if(i==0 || j==0 || i == linhas+1 || j == colunas+1){
                        mapa[i][j] = 0;
                    }else{
                        int x;
                        cin >> x;
                        mapa[i][j] = x;
                    }
                }
            }
            int total = 0;
            for(int i = 0;i<linhas;i++){
                for(int j = 0;j<colunas;j++){
                    if(mapa[i+1][j+1] == 1){
                        mapa2[i][j] = 9;
                    }else{
                        mapa2[i][j] = 0;
                        if(mapa[i+2][j+1] == 1){
                            mapa2[i][j]++;
                        }if(mapa[i+1][j+2] == 1){
                            mapa2[i][j]++;
                        }if(mapa[i][j+1] == 1){
                            mapa2[i][j]++;
                        }if(mapa[i+1][j] == 1){
                            mapa2[i][j]++;
                        }
                    }
                }
            } 
            for(int i = 0;i<linhas;i++){
                for(int j = 0;j<colunas;j++){
                    cout << mapa2[i][j];
                }
                cout << endl;
            }
    }
 }