#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct vacas{
    int coluna,linha,grama,idx;
} ;

vector<vacas>vacasN;
vector<vacas>vacasE;

vacas GuardaVacas(int coluna, int linha, int idx){
    vacas vaca;
    vaca.coluna = coluna;
    vaca.linha = linha;
    vaca.idx = idx;
    vaca.grama = -1;
    return vaca;
}

void arrumaVacasN(){
    for(int i = 0; i<vacasN.size()-1;i++){
        for(int j = 0;j<((vacasN.size())-1-i);j++){
            if(vacasN[j].coluna>vacasN[j+1].coluna){
                 vacas x = vacasN[j];
                 vacasN[j] = vacasN[j+1];
                 vacasN[j+1] = x;
            }
        }
    }
}

void arrumaVacasE(){
    for(int i = 0; i<vacasE.size()-1;i++){
        for(int j = 0;j<((vacasE.size())-1-i);j++){
            if(vacasE[j].linha>vacasE[j+1].linha){
                 vacas x = vacasE[j];
                 vacasE[j] = vacasE[j+1];
                 vacasE[j+1] = x;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0;i<n;i++){
        int column, row, zero=0;
        char dir;
        cin >> dir >> column >> row;
        vacas vaca = GuardaVacas(column, row, i);
        if(dir == 'N'){
            vacasN.push_back(vaca);
        }else{
            vacasE.push_back(vaca);
        }
    }

    arrumaVacasN();
    arrumaVacasE();


    for(vacas &vacaN : vacasN){
        for(vacas &vacaE : vacasE){
            if(vacaE.linha>vacaN.linha && vacaE.coluna<vacaN.coluna){//vaca indo pro norte esta antes da linha e depois da coluna da vaca ao leste
                int difLinha = vacaE.linha-vacaN.linha;
                int difColuna = vacaN.coluna-vacaE.coluna;

                if(difLinha<difColuna && vacaE.grama == -1){
                    vacaE.grama = difColuna;   
                }
                if(difLinha>difColuna && vacaE.grama == -1){
                    vacaN.grama = difLinha;
                    break;
                }
            }
        }
    }

    for(int i = 0;i<vacasN.size()+vacasN.size();i++){
        for(vacas &vacaE : vacasE){
            if(vacaE.idx == i){
                if(vacaE.grama != -1){
                    cout << vacaE.grama << endl;
                }else{
                    cout << "Infinity" << endl;
                }
                break;
            }
        }
        for(vacas &vacaN : vacasN){
            if(vacaN.idx == i){
                if(vacaN.grama != -1){
                    cout << vacaN.grama << endl;
                }else{
                    cout << "Infinity" << endl;
                }
                break;
            }
        }
        
    }


    return 0;
}