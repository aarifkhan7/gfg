#include<bits/stdc++.h>
using namespace std;

class s{
    private:
    vector<int> data;
    public:
    void push(int d){
        data.push_back(d);
    }
    int pop(){
        int tmp = *(data.end() - 1);
        data.erase(data.end() - 1);
        return tmp;
    }
    bool isEmpty(){
        return (data.size() == 0);
    }
    int getMin(){
        
    }
}

int main()
{
    
    return 0;
}