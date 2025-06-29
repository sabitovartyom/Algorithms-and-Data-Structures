#include <iostream>
#include <vector>
#include <stdexcept>

class Node{
public:

    Node(int a) : value(a), prev(nullptr) {}
    Node(int a, Node* ptr): value(a), prev(ptr) {}
    
    ~Node() {}

    int get_value() {return value;}
    void set_value(int a) {value = a;}

    Node* get_prev() {return prev;}
    void set_prev(Node* ptr) {prev = ptr;} 

private:
    int value;
    Node* prev;
};

class Stack{
public:

    Stack(): root(nullptr) {}
    Stack(int a) {root = new Node(a);}
    Stack(const std::vector<int> &arr) {
        root = nullptr;
        for (int i = 0; i < arr.size(); ++i) {
            push(arr[i]);
        }
    }

    ~Stack() {
        Node* current = root;
        while (current != nullptr) {
            Node* next = current->get_prev();
            delete current;
            current = next;
        }
        root = nullptr;
    }

    void push(int a) {
        Node* newNode = new Node(a, root);
        root = newNode;
    }

    int pop() {

        if (root == nullptr) {
            throw std::runtime_error("Stack is empty");
        }

        int value = root->get_value();
        Node* delPtr = root;
        root = root->get_prev();
        delete delPtr;
        return value;
    }

    int getRoot() {

        if (root == nullptr) {
            throw std::runtime_error("Stack is empty");
        }

        return root->get_value();
    } 

private:
    Node* root;
};


int main() {
    // Test case 1: Empty stack
    Stack s1;
    try {
        s1.pop();
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test case 2: Push and Pop
    Stack s2;
    s2.push(10);
    s2.push(20);
    s2.push(30);
    std::cout << "Root of s2: " << s2.getRoot() << std::endl; // Output: 30
    std::cout << "Popped: " << s2.pop() << std::endl; // Output: 30
    std::cout << "Root of s2: " << s2.getRoot() << std::endl;  // Output: 20
    std::cout << "Popped: " << s2.pop() << std::endl; // Output: 20
    std::cout << "Popped: " << s2.pop() << std::endl; // Output: 10
    try {
        s2.pop();
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    // Test case 3: Constructor with a vector
    std::vector<int> arr = {1, 2, 3, 4, 5};
    Stack s3(arr);
    std::cout << "Root of s3: " << s3.getRoot() << std::endl; // Output: 5
    std::cout << "Popped: " << s3.pop() << std::endl; // Output: 5
    std::cout << "Popped: " << s3.pop() << std::endl; // Output: 4
    std::cout << "Popped: " << s3.pop() << std::endl;
    std::cout << "Popped: " << s3.pop() << std::endl;
    std::cout << "Popped: " << s3.pop() << std::endl;

    // Test case 4: Constructor with one value

    Stack s4(42);
    std::cout << "Root of s4: " << s4.getRoot() << std::endl;
    std::cout << "Popped: " << s4.pop() << std::endl;


    return 0;
}