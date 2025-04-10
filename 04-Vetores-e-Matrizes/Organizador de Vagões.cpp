#include <iostream>
#include <stdio.h>
#include <vector>
#include<algorithm>

 using namespace std;




 int main(){
    int n;
    cin >> n;
    while(n--){
        int tamTrem;
        cin >> tamTrem;
        vector<int>trem;
        int total = 0;
        for(int i = 0;i<tamTrem;i++){
            int x;
            cin >> x;
            trem.push_back(x);
        }
        for(int i = 0; i<tamTrem-1;i++){
            for(int j = 0;j<tamTrem-1-i;j++){
                if(trem[j]>trem[j+1]){
                     int x = trem[j];
                     trem[j] = trem[j+1];
                     trem[j+1] = x;
                     total++;
                }
            }
        }
        cout << "Optimal train swapping takes " << total << " swaps." << endl;
    }
 }