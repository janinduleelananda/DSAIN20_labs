#include <iostream>
#define SIZE 1000
#include <time.h>
using namespace std;

class Stack {
    private:
        int top;             //top of stack
        int arr[SIZE]; //array which is storing stack

    public:
        Stack() {
            top = -1;
        }

        bool isEmpty() {
            return top == -1;
        }

        bool isFull() {
            return top == SIZE - 1; 
        }

        void Push(int val) {
            if (isFull()) {
                cout << "Stack Overflow" << endl;
            } else {
                top+=1;
                arr[top] = val; 
            }
        }

        int Pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return -1;
            } else {
                int val = arr[top];
                top-=1;
                return val;
            }
        }

    void Display(){
        for (int i=top;i>=0;i--)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
        cout<<"stack using array"<<endl;
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
