#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

vector<vector<char>> billboard;
vector<pair<tuple(char,int,int),tuple(char,int,int)> posters;
vector<bool> quadro;


void search() {
    if (ordem.size()-1 == posters.size()) {
        bool obdc = true;
        ordem.push_back(" ");
        for(int i = 1;i< ordem.size()-1;i++){
            for(pair<string,string> dupla : regras){
                if(ordem[i] == dupla.first && (ordem[i-1]!=dupla.second && ordem[i+1]!=dupla.second)){
                    obdc = false;
                    break;
                }
            }
            if(!obdc){
                break;
            }
        }
        if(obdc){
            permutation.insert(ordem);
        }
        ordem.pop_back();
    } else {
        for (int i = 0; i < posters.size(); i++) {
            if (quadro[i]) continue;
            quadro[i] = true;
            ordem.push_back(vacas[i]);
            search();
            quadro[i] = false;
            ordem.pop_back();
        }
    }
}


int main() {
    //freopen("lineup.in", "r", stdin);
    //freopen("lineup.out", "w", stdout);

    int aX,   aY,   bX,   bY,   cX,   cY;
	cin >> aX >> aY >> bX >> bY >> cX >> cY;

    int aA = aX*aY;
    int bA = bX*bY;
    int cA = cX*cY;

    int area = aA+bA+cA;
    int maiorLado = max(max(max(aX,aY),bX),max(max(cX,cY),bY));

    if((area * 1.0)/(maiorLado * 1.0) == maiorLado){

        vector<char>x('*',maiorLado)
        billboard.resize(x,maiorLado);
        quadro.resize(3,false);

        posters.push_back(make_pair(make_tuple('A',aX,aY),make_tuple('A',aY,aX)));
        posters.push_back(make_pair(make_tuple('B',bX,bY),make_tuple('B',bY,bX)));
        posters.push_back(make_pair(make_tuple('C',cX,cY),make_tuple('C',cY,cX)));
        search();

    }else{
        cout << "-1" << endl;
    }

	

    

    //search();

    //auto x = *permutation.begin();
    //for(int i = 1;i<x.size()-1;i++)cout<<x[i]<<endl;
}