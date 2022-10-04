#include<bits/stdc++.h>
using namespace std;

#define max_size 100

class Node{
    public:
    int data;
    Node * prev = nullptr;
    Node * next = nullptr;
    Node(){

    }
    Node(int d){
        data = d;
    }
};

class s{
    Node * head = nullptr;
    int size = 0;
    Node * mid = nullptr;
    public:
        s(){

        }
        s(int d){
            Node * tmp = new Node(d);
            head = tmp;
            mid = tmp;
        }
        void push(int d){
            Node * tmp = new Node(d);
            Node * curr = head;
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = tmp;
            tmp->prev = curr;
            size++;
            if(size % 2 == 0){
                mid = mid->next;
            }
        }
        void pop(){
            Node * curr = head;
            while(curr->next->next != nullptr){
                curr = curr->next;
            }
            delete(curr->next);
            curr->next = nullptr;
            size--;
            if(size % 2 == 0){
                mid = mid->prev;
            }
        }
        int getmid(){
            return mid->data;
        }
        void print(){
            Node * tmp = head;
            while(tmp != nullptr){
                cout << tmp->data << ' ';
                tmp = tmp->next;
            }
            cout << endl;
        }
};

int main()
{
    s s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.print();
    return 0;
}