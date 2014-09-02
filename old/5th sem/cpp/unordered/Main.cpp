#include <iostream>
#include <unordered_map>
using namespace std;
 
int main() {
        unordered_map<int,int> m;
    m[2]=2;m[3]=3;
    cout<<m[2]<<" "<<m[3];
        return 0;
}