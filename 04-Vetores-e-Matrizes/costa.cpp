#include <iostream>
#include <stdio.h>
#include <vector>
#include<algorithm>

 using namespace std;

 int main(){
    int linhas,colunas;
    cin >> linhas >> colunas;

    char mapa[linhas+2][colunas+2];
    for(int i = 0;i<linhas+2;i++){
        for(int j = 0;j<colunas+2;j++){
            if(i==0 || j==0 || i == linhas+1 || j == colunas+1){
                mapa[i][j] = '.';
            }else{
                char x;
                cin >> x;
                mapa[i][j] = x;
            }
        }
    }
    int total = 0;
    for(int i = 0;i<linhas+2;i++){
        for(int j = 0;j<colunas+2;j++){
            if(mapa[i][j] == '#' && (mapa[i+1][j] == '.' || mapa[i][j+1] == '.'  || mapa[i-1][j] == '.'  || mapa[i][j-1] == '.')){
                total++;
            }
        }

    } 
    cout << total << endl;
 }