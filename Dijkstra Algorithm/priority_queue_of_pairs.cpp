#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({1, 2});
    pq.push({2, 3});
    pq.push({0, 4});
    while(!pq.empty()){
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}