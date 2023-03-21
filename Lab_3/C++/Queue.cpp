#include<iostream>

using namespace std;


struct Node {
    int data;
    Node* next;
};

class Queue {
    private:
        Node* front{nullptr};
        Node* rear{nullptr};
        int size{0};
    public:
        Queue() = default;
        
        void enqueue(int data) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = NULL;

            if (front == NULL) {
                front = rear = newNode;
            }
            else {
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }

        void dequeue() {
            if (front == NULL) {
                cout << "Queue is empty" << endl;
                return;
            }
            else if (front == rear) {
                front = rear = NULL;
            }
            else {
                Node* temporary = front;
                front = front->next;
                delete temporary;
            }
            size--;
        }

        int top() {
            if (front == NULL) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            else {
                return front->data;
            }
        }

        bool isEmpty() {
            return (front == NULL);
        }

        int getSize() {
            return size;
        }
};

int main() {
    Queue q;

    cout << "Size of the Queue: " << q.getSize() << endl;
    cout << "Top element of the Queue: " << q.top() << endl;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << "Size of the Queue: " << q.getSize() << endl;
    cout << "Top element of the Queue: " << q.top() << endl;

    q.dequeue();
    q.dequeue();
    
    cout << "Size of the Queue: " << q.getSize() << endl;
    cout << "Top element of the Queue: " << q.top() << endl;
    
    q.dequeue();
    q.dequeue();
    
    cout << "Size of the Queue: " << q.getSize() << endl;
    cout << "Top element of the Queue: " << q.top() << endl;
    
    return 0;
}