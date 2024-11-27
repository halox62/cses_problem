#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solve(int n){
    int step=0;

    while(n>0){
        int maxDigit=0;
        int temp=n;
        while(temp>0){
            maxDigit=max(maxDigit,temp % 10);
            temp /= 10;
        }
        n-=maxDigit;
        step++;
    }

    return step;
}

int main(){
    int n;
    cin >> n;

    cout << solve(n) << endl;


    return 0;
}