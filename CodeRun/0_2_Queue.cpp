#include <iostream>
#include <vector>
#include <stdexcept>

class Node{
public:
    Node(int a): value(a), prev(nullptr) {}
    Node(int a, Node* ptr): value(a), prev(ptr) {}

    ~Node() {}

    int getValue() {return value;}
    void setValue(int a) {value = a;}
    Node* getPrev() {return prev;}
    void setPrev(Node* ptr) {prev = ptr;}

private:
    int value;
    Node* prev;
};


class Queue{
public:

    Queue(): head(nullptr), tail(nullptr) {}
    Queue(int a) {
        head = new Node(a);
        tail = head;
    }
    Queue(const std::vector<int> &arr): head(nullptr), tail(nullptr) {
        for (int val : arr) {pushBack(val);}
    }

    ~Queue(){
        tail = nullptr;
        Node* current = head;
        while (current != nullptr){
            Node* next = current->getPrev();
            delete current;
            current = next;
        }
        head = nullptr;

    }

    void pushBack(int a) {

        if (isEmpty()){
            tail = new Node(a);
            head = tail;
            return;
        }

        Node* newNode = new Node(a);
        tail->setPrev(newNode);
        tail = newNode;
    }

    int getHead(){
        if (isEmpty()){
            throw std::runtime_error("Stack is empty");
        }
        return head->getValue();
    }

    int popHead(){
        if (isEmpty()){
            throw std::runtime_error("Stack is empty");            
        }
        int value = head->getValue();
        Node* delNode = head;
        head = head->getPrev();
        delete delNode;
        return value;
    }

private:
    Node* head;
    Node* tail;

    bool isEmpty(){
        return head == nullptr;
    }
};

int main() {
    // Test case 1: Empty queue
    Queue q1;
    std::cout << "Queue q1 is empty." << std::endl;
    try {
        q1.popHead();
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test case 2: Push and Pop
    Queue q2;
    q2.pushBack(10);
    q2.pushBack(20);
    q2.pushBack(30);
    std::cout << "Head of q2: " << q2.getHead() << std::endl;
    std::cout << "Popped: " << q2.popHead() << std::endl;
    std::cout << "Head of q2: " << q2.getHead() << std::endl;
    std::cout << "Popped: " << q2.popHead() << std::endl;
    std::cout << "Head of q2: " << q2.getHead() << std::endl;
    std::cout << "Popped: " << q2.popHead() << std::endl;
    try {
        q2.popHead();
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test case 3: Constructor with a vector
    std::vector<int> arr = {1, 2, 3, 4, 5};
    Queue q3(arr);
    std::cout << "Head of q3: " << q3.getHead() << std::endl;
    std::cout << "Popped: " << q3.popHead() << std::endl;
    std::cout << "Popped: " << q3.popHead() << std::endl;
    std::cout << "Popped: " << q3.popHead() << std::endl;
    std::cout << "Popped: " << q3.popHead() << std::endl;
    std::cout << "Popped: " << q3.popHead() << std::endl;

    // Test case 4: Constructor with one value
    Queue q4(42);
    std::cout << "Head of q4: " << q4.getHead() << std::endl;
    std::cout << "Popped: " << q4.popHead() << std::endl;

    return 0;
}

