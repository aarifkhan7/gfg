#include<bits/stdc++.h>
using namespace std;

class q{
    vector<int> data;
    int sdash = 0;
    public:
        void enq(int d){
            data.push_back(d);
            sdash++;
        }
        int front(){
            return *(data.end() - 1);
        }
        int deq(){
            int tmp = *(data.end()-1);
            data.erase(data.begin());
            sdash--;
            return tmp;
        }
        void print(){
            for(int x : data)
                cout << x << ' ';
            cout << endl;
        }
        int size(){
            return sdash;
        }
};

class s{
    q data;
    public:
        void push(int d){
            data.enq(d);
            int qsize = data.size();
            for(int i = 0; i < qsize - 1; i++){
                int tmp = data.deq();
                data.enq(tmp);
            }
        }
        void pop(){
            data.deq();
        }
        int top(){
            return data.front();
        }
        int size(){
            return data.size();
        }
};

int main()
{
    s s1;
    s1.push(10);
    cout << s1.top() << '\n';
    s1.push(20);
    cout << s1.top() << '\n';
    s1.push(30);
    cout << s1.top() << '\n';
    s1.pop();
    cout << s1.top() << '\n';
    return 0;
}