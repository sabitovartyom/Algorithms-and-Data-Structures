#include <iostream>
#include <string>

struct Node {
    int number;
    Node* next;
    Node* prev;
    Node(int n) : number(n), next(nullptr), prev(nullptr) {}
};

struct Queue {
    Node* tail;
    Node* head;
    
    Queue() : tail(nullptr), head(nullptr) {}

    ~Queue() {
        while (tail) {
            delNode();
        }
    }

    void addNode(int n) {
        Node* newNode = new Node(n);
        if (!tail) {
            tail = newNode;
            head = tail;
        } else {
            newNode->next = tail;
            tail->prev = newNode;
            tail = newNode;
        }
    }

    void delNode() {
        if (!head) return;
        if (tail == head) {
            delete head;
            tail = nullptr;
            head = nullptr;
        } else {
            Node* temp = head;
            head = head->prev;
            head->next = nullptr;
            delete temp;
        }
    }

    void printQueue() {
        Node* temp = tail;
        while (temp) {
            std::cout << temp->number << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};


int main() {
    Queue q;
    std::string command;

    std::cout << "Enter commands (+n to add, - to remove, q to quit):\n";
    
    while (true) {
        std::cin >> command;
        
        if (command == "q") break;

        if (command[0] == '+') {
            try {
                int number = std::stoi(command.substr(1));
                q.addNode(number);
            } catch (...) {
                std::cout << "Invalid input\n";
            }
        } 
        else if (command == "-") {
            q.delNode();
        } 
        else {
            std::cout << "Invalid command\n";
        }
    q.printQueue();
    }

    return 0;
}
