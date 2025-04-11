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
    vaca.grama = 0;
    return vaca;
}

void arrumaVacasN(){
    for(int i = 0; i<vacasN.size()-1;i++){
        for(int j = 0;j<((vacasN.size())-1-i);j++){
            cout << "N " << vacasN.size() << " " << i << " " << j << endl;
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
            cout << "E " << vacasE.size() << " " << i << " " << j << endl;
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

    for(int i = 0;i<vacasN.size();i++){
        //cout << "N " << vacasN[i].coluna << endl;
    }
    for(int i = 0;i<vacasE.size();i++){
        //cout << "E " << vacasE[i].linha << endl;
    }

    for(int i = 0; i<vacasN.size();i++){
        bool inf = true;
        for(int j = 0; j<vacasE.size();j++){
            cout << vacasE[j].linha << " > " << vacasN[i].linha  << " && " << vacasE[j].coluna << " < " << vacasN[i].coluna;
            if(vacasE[j].linha>vacasN[i].linha && vacasE[j].coluna<vacasN[i].coluna){//vaca indo pro norte esta antes da linha e depois da coluna da vaca ao leste
                cout << " true" << endl;
                cout << vacasE[j].linha-vacasN[i].linha << " > " << vacasN[i].coluna-vacasE[j].coluna;
                if(vacasE[j].linha-vacasN[i].linha>vacasN[i].coluna-vacasE[j].coluna){
                    cout << " true" << endl;
                    vacasN[i].grama = vacasE[j].linha-vacasN[i].linha;
                    inf = false;
                    break;
                }else{
                    cout << " false" << endl;
                }
            }else{
                cout << " false" << endl;
            }
        }
        if(inf){
            vacasN[i].grama = -1;
        }
        cout << "N i=" <<  vacasN[i].idx << " comeu: " << vacasN[i].grama << endl;
    }

    for(int i = 0; i<vacasE.size();i++){
        bool inf = true;
        for(int j = 0; j<vacasN.size();j++){
            cout << vacasN[j].coluna << " > " << vacasE[i].coluna << " && " << vacasN[j].linha << " < " << vacasE[i].linha;
            if(vacasN[j].coluna>vacasE[i].coluna && vacasN[j].linha<vacasE[i].linha){//vaca indo pro leste esta antes da coluna e depois da linha da vaca ao norte
                cout << " true" << endl;
                cout << vacasN[j].coluna-vacasE[i].coluna << " > " << vacasE[i].linha-vacasN[j].linha;
                if(vacasN[j].coluna-vacasE[i].coluna>vacasE[i].linha-vacasN[j].linha){
                    cout << " true" << endl;
                    vacasE[i].grama = vacasN[j].coluna-vacasE[i].coluna;
                    inf = false;
                    break;
                }else{
                    cout << " false" << endl;
                }
            }else{
                cout << " false" << endl;
            }
        }
        if(inf){
            vacasE[i].grama = -1;
        }
        cout << "E i=" <<  vacasE[i].idx << " comeu: " << vacasE[i].grama << endl;
    }

    return 0;
}