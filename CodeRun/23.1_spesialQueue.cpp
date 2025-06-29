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
    int size;
    
    Queue() : tail(nullptr), head(nullptr), size(0) {}

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
        size++;
    }

    void specialAddNode(int n) {
        if (size < 2) {
            addNode(n);
        } else {
            Node* cur = tail;
            for (int i = 0; i < size/2; i++){
                cur = cur->next;
            }
            Node* newNode = new Node(n);
            newNode->next = cur;
            newNode->prev = cur->prev;
            cur->prev->next = newNode;
            cur->prev = newNode;
            size++;
        }
    }

    void delNode() {
        if (!head) return;
        std::cout << head->number << '\n';
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
        size--;
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
    int N;
    std::cin >> N;
    std::cin.ignore();

    for (int i = 0; i < N; i++) {
        std::getline(std::cin, command);
        if (command == "q") break;

        if (command[0] == '+') {
            try {
                int number = std::stoi(command.substr(2));
                q.addNode(number);
            } catch (...) {
                std::cout << "Invalid input\n";
            }
        } else if (command[0] == '*') {
            try {
                int number = std::stoi(command.substr(2));
                q.specialAddNode(number);
            } catch (...) {
                std::cout << "Invalid input\n";
            }
        } else if (command == "-") {
            q.delNode();
        } else {
            std::cout << "Invalid command\n";
        }
    }

    return 0;
}
