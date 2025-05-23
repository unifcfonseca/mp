#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("guess.in", "r", stdin);
    
    vector<vector<string>>animais;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        string lixo;
        int atr;
        vector<string>anix;
        cin >> lixo >> atr;
        for(int ii = 0;ii<atr;ii++){
            string x;
            cin >> x;
            anix.push_back(x);
        }
        animais.push_back(anix);
    }

    for(int i = 0;i<animais.size();i++){
        sort(animais[i].begin(), animais[i].end());
    }

    int maior = 0;
    for(int i = 0;i<animais.size()-1;i++){
        for(int j = i+1;j<animais.size();j++){
            int temp = 0;
            for(int k = 0;k<animais[i].size();k++){
                for(int l = 0;l<animais[j].size();l++){
                    if(animais[i][k]==animais[j][l]){
                        temp++;
                    }
                }
            }
            maior = max(temp,maior);
        }
    }
    freopen("guess.out", "w", stdout);
    cout << maior+1 << endl;
    

    return 0;
}