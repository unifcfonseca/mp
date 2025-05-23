#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int idx(vector<int>aula, int vlr){
    for(int i = 0;i<aula.size();i++){
        if(aula[i]==vlr){
            return i;
        }
    }
    return -1;
}

int main() {
    //freopen("circlecross.in", "r", stdin);

    vector<char>letras;
    set<char>letrasVistas;
    int cruzamento=0;
    string x;
    cin >> x;
    for(int i = 0;i<x.size();i++){
        cout << "Verificando " << x[i];
        if(letrasVistas.find(x[i]) != letrasVistas.end()){
            cout << " existente no set!" << endl;
            for(int j = letras.size()-1; j>=0;j--){
                cout << "no vetor verificando: " << letras[j];
                if(letras[j]!=x[i]){
                    cout << " diferente" << endl;
                    cruzamento++;
                }else{
                    cout << " igual" << endl;
                    letras.erase (letras.begin()+j);
                    break;
                }
            }
        }else{
            cout << " nao existente no set!" << endl;
            letras.push_back(x[i]);
            letrasVistas.insert(x[i]);
        }
    }
    //freopen("circlecross.out", "w", stdout);
    cout << cruzamento << endl;

return 0;
}