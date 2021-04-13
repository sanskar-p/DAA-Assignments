#include <bits/stdc++.h>
using namespace std;

long long numOfCombos(int n){
    long long DP[n+1] = {0};  //to store no. of combos with n people

    for(int i=0; i<=n; i++){
        if(i<=1) DP[i]=1;      //if 0 or 1, store 1

        else DP[i] = DP[i-1] + (i-1)*DP[i-2];  //DP[i-1] is when i chooses to stay alone whereas the other part is when i chooses to pair up
    }

    if(n==0) return 0;
    return DP[n];
}

int main(){
    int x=10;      //num of random inputs
    while(x--){   
        int randInput = (rand()%30)+1;
        cout<<randInput<<": "<<numOfCombos(randInput)<<"\n";
    }

}

//example for 5
// 0: 1
// 1: 1
// 2: 1+1*1 = 2
// 3: 2+2*1 = 4
// 4: 4+3*2 = 10
// 5: 10+4*4 = 26 (f(4)+4f(3))
