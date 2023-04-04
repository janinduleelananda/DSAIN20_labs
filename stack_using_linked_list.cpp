#include<iostream>
#include <time.h>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
};
class Stack {
    private:
        Node* top;
    public:
        Stack() {
            top = nullptr; 
        }
        bool is_empty() {
            return top == nullptr;
        }
        void Push(int item) {
            Node* new_node = new Node();
            new_node->data = item; 
            new_node->next = top; 
            top = new_node;
        }
        int Pop() {
            if (is_empty()) {
                cout << "Stack Underflow" << endl; 
                return -1;
            } else {
                Node* node_to_remove = top;
                int item = node_to_remove->data;
                top = node_to_remove->next;
                delete node_to_remove;
                return item; 
            }
        }
        void Display(){
                      if (is_empty()) {
                cout << "Stack Underflow" << endl;
            } else {
                Node* item=top;
                while (item!=nullptr){
                    int val=item->data;
                    item=item->next;
                    cout<<val<<" ";
                }
                cout<<endl;
            }  
        }
};

int main() {
    cout<<"stack using linked list"<<endl;
    clock_t start, end;
     double cpu_time_used;
    start = clock();
    Stack S;
    S.Push(8);
    S.Push(10);
    S.Push(5);
    S.Push(11);
    S.Push(15);
    S.Push(23);
    S.Push(6);
    S.Push(18);
    S.Push(20);
    S.Push(17);
    S.Display();
    S.Pop();
    S.Pop();
    S.Pop();
    S.Pop();
    S.Pop();
    S.Display();
    S.Push(4);
    S.Push(30);
    S.Push(3);
    S.Push(1);
    S.Display();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<"time taken "<<cpu_time_used<<endl;
    return 0;
}