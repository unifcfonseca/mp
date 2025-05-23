#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
    //freopen("guess.in", "r", stdin);
    //freopen("guess.out", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>log;
        int maior = -1;
        for(int i = 0; i<n;i++){
            int x;
            cin >> x;
            maior = max(maior,x);
            log.push_back(x);

        }
        int mud = 0;
        while(true){
            bool oper = false;
            int mudX = mud;
            vector<int>newLog;
            for(int i = 0;i<log.size();i++){
                if(i==log.size()-1){
                    if(log[i]<maior){
                        newLog[newLog.size()-1] = newLog[newLog.size()-1] +  log[i];
                        mud++;
                    }else{
                        newLog.push_back(log[i]);
                    }
                }
                if(log[i]<maior && i<log.size()-1){
                    newLog.push_back(log[i]+log[i+1]);
                    maior = max(maior,log[i]+log[i+1]);
                    mud++;
                    i++;
                }else if(i<log.size()-1){
                    newLog.push_back(log[i]);
                }
            }
            if(mudX==mud){
                break;
            }
            log.clear();
            log = newLog;
        }
        cout << mud << endl;
    }

    return 0;
}