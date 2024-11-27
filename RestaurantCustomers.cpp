#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, a, b;
    cin >> n;

    vector<pair<int, int> > events;

   
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back(make_pair(a, 1)); 
        events.push_back(make_pair(b, -1));
    }

    std::sort(events.begin(), events.end());

    int corrent=0;
    int max=0;

    for(auto event: events){
        if(event.second==+1){
            corrent++;
        }else{
             corrent--;
        }
        if(corrent>max)
            max=corrent;
    }

    cout<<max<<endl;


    return 0;
}