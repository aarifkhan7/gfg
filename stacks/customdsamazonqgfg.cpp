#include<bits/stdc++.h>
using namespace std;

#define max_size 100

class CDS{
    private:
    stack<int> ms;
    stack<int> as;
    public:
    void add_element(int d){
        ms.push(d);
        if(d < as.top()){
            as.push(d);
        }else{
            as.push(as.top());
        }
    }
    void remove_last_element(){
        ms.pop();
        as.pop();
    }
    int get_last_element(){
        return ms.top();
    }
    int get_min(){
        return as.top();
    }
};

int main()
{
    
    return 0;
}