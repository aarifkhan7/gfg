#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    public:
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

class MyStack{
    private:
    Node * head;
    int size = 0;
    public:
    MyStack(){
        head = nullptr;
    }
    void push(int d){
        Node * tmp = new Node(d, head);
        head = tmp;
        size++;
    }
    void pop(){
        Node * tmp = head;
        head = head->next;
        delete(tmp);
        size--;
    }
    int top(){
        return head->data;
    }
    int stacksize(){
        return size;
    }
    void reverse(){
        Node * prev = nullptr;
        Node * curr = head;
        Node * next = curr->next;
        while(curr != nullptr){
            curr->next = prev;
            prev = curr;
            curr = curr->next;
            if(next != nullptr){
                next = next->next;
            }
        }
        head = prev;
    }
    MyStack(vector<int> v){
        for(int x : v){
            push(x);
        }
    }
    void print(){
        while(head != nullptr){
            cout << head->data << ' ';
            head = head->next;
        } cout << '\n';
    }
};

int main()
{
    MyStack ms({10,20,30,40,50});
    ms.reverse();
    ms.print();
    return 0;
}