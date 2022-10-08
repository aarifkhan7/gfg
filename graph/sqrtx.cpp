#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x = 0) return 0;
    for(int i = 0; i <= x; i++){
        cout << i * i << '\t' << x << '\n';
        if(i * i > x){
            return i - 1;
        }
    }
    return 0;
}

int main(){
    mySqrt(4);
}