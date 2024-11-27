#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 7; 

int main(){
    int n,pay,c;
    cin >> n >> pay;
    vector<int> coin(n);

    for(int i=0;i<n;i++){
        cin>>c;
        coin[i]=c;
    }

    vector<int> dp(pay+1, INF);

    dp[0]=0;

    for(int i=0;i<=pay;i++){
        for(int coins:coin){
            if(i-coins>=0)
                dp[i]=min(dp[i],dp[i-coins]+1);
        }
    }

    if(dp[pay]==INF){
        cout<<"-1"<<endl;
    }else{
        cout<<dp[pay]<<endl;
    }


    return 0;
}