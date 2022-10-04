#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(){
        next = nullptr;
    }
    Node(int d){
        data = d;
        next = nullptr;
    }
    Node(int d, Node * n){
        data = d;
        next = n;
    }
};

class Stack{
    public:
    Node * head;
    Node * firstelem;
    void push(int x){
        Node * tmp = new Node(x, head);
        if(head == nullptr){
            firstelem = tmp;
        }
        head = tmp;
    }
    void pop(){
        head = head->next;
        if(head == nullptr)
            firstelem = nullptr;
    }
    Stack(){
        head = nullptr;
        firstelem = nullptr;
    }
    Stack(vector<int> data){
        head = nullptr;
        firstelem = nullptr;
        for(int x : data){
            this->push(x);
        }
    }
};

Stack * merge(Stack * s1, Stack * s2){
    s2->firstelem->next = s1->head;
    return s2;
}

int main()
{
    Stack s1({10,20,30,40,50});
    Stack s2({60,70,80,90,100});
    Node * head = merge(&s1, &s2)->head;
    
    while(head != nullptr){
        cout << head->data << ' ';
        head = head->next;
    } cout << endl;
}