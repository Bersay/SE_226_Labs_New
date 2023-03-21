#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class Stack{
    private:
        Node *head;
        int _size;
        int max_size;

    public:
        Stack(int n){
            head = nullptr;
            _size = 0;
            max_size = n;
        }

        void push(int x){
            if(_size + 1 > max_size){
                cout << "Stack overflow" << endl;
            } else{
                Node *temp = new Node();
                (*temp).data = x;
                (*temp).next = head;
                head = temp;
                _size++;
            }
        }

        int top(){
            return head->data;
        }

        int pop(){
            int topData = top();
            head = head->next;
            _size--;
            return topData;
        }

        bool isEmpty(){
            if(_size==0){
                return true;
            }
            return false;
        }

        int size(){
            return _size;
        }

        void print(){
            for(Node *n=head; n!=nullptr; n=n->next){
                cout << n->data << endl;
            }
        }
};

int main() {
    Stack *stack = new Stack(1);
    (*stack).push(1);
    cout << (*stack).size() << endl;
    (*stack).push(2);
    cout << (*stack).size() << endl;

    (*stack).print();
    cout << (*stack).size() << endl;
    cout << (*stack).isEmpty() << endl;
    (*stack).pop();
    (*stack).print();


    return 0;
}