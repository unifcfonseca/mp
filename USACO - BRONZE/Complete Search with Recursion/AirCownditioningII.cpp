#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m,custando = 0;
set<int> custo;
vector<bool> ar;
vector<pair<pair<int,int>,int>> vacas;
vector<int>stalls;
vector<tuple<pair<int,int>,int,int>> arCon;
void search() {
    vector<bool> fria (n,true);
    for(int k = 0;k<n;k++){
        /*cout << "vaca: " << k << endl;
        for(int l = vacas[k].first.first-1;l<vacas[k].first.second;l++){
            cout << stalls[l] << " ";
        }*/
        for(int l = vacas[k].first.first-1;l<vacas[k].first.second;l++){
            if(stalls[l]<vacas[k].second){
                //cout << "fria:" << vacas[k].second;
                fria[k] = false;
                break;
            }
        }
        //cout << endl;
    }
    bool frias = true;
    for(int k = 0;k<fria.size();k++){
        if(!fria[k]){
            frias = false;
            break;
        }
    }
    if(frias){
        /*for(int i = 0;i<ar.size();i++){
            cout << ar[i] << " ";
        }
        cout << endl;
        cout << custando << "!" << endl << endl;*/
        custo.insert(custando);
    } else {
        for (int i = 0; i < arCon.size(); i++) {
            if (ar[i]) continue;
            ar[i] = true;
            for(int j = get<0>(arCon[i]).first-1;j<get<0>(arCon[i]).second;j++){
                stalls[j]+=get<1>(arCon[i]);
            }
            custando+=get<2>(arCon[i]);
            
            search();

            ar[i] = false;
            for(int j = get<0>(arCon[i]).first-1;j<get<0>(arCon[i]).second;j++){
                stalls[j]-=get<1>(arCon[i]);
            }
            custando-=get<2>(arCon[i]);
        }
    }
}


int main() {
    //freopen("lineup.in", "r", stdin);
    //freopen("lineup.out", "w", stdout);
	cin >> n >> m;
	ar.resize(m,false);
    stalls.resize(100,0);
    for(int i = 0;i<n;i++){
        int idxA, idxB, nec;
        cin >> idxA >> idxB >> nec;
        vacas.push_back(make_pair(make_pair(idxA,idxB),nec));
    }
    for(int i = 0;i<m;i++){
        int idxA, idxB, esf, cus;
        cin >> idxA >> idxB >> esf >> cus;
        arCon.push_back(make_tuple(make_pair(idxA,idxB),esf,cus));
    }

    search();

    auto x = *custo.begin();
    cout<<x<<endl;
}