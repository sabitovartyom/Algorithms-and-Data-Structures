#include <iostream>
#include <vector>

class Node{
public:

    Node(int v):LeftChild(nullptr), RightChild(nullptr), value(v) {}
    Node(Node* left, Node* right, int v): LeftChild(left), RightChild(right), value(v) {}

    ~Node() {
        delete LeftChild;
        delete RightChild;
    }

    void set_value(int v) {value = v;}
    int get_value() {return value;}
    void set_LeftChild(Node* left) {LeftChild = left;}
    Node* get_LeftChild() {return LeftChild;}
    void set_RightChild(Node* right) {RightChild = right;}
    Node* get_RightChild() {return RightChild;}

private:

    Node* LeftChild;
    Node* RightChild;
    int value;

};

class SearchTree{
public:

    SearchTree(std::vector<int> &arr){ BuildTree(arr); }

    ~SearchTree() { delete root; }

    int get_root() { return root->get_value(); }

    void SearchInTree(int a){Search(a, root);}

private:
    Node* root;
//  int size;

//  слева бОльшие, чем справа
    void insert(int a, Node* root){
        if (a > root->get_value()) {
            if (root->get_LeftChild() == nullptr){
                root->set_LeftChild(new Node(a));
            } else {
                insert(a, root->get_LeftChild());
            }
        } else {
            if (root->get_RightChild() == nullptr){
                root->set_RightChild(new Node(a));
            } else {
                insert(a, root->get_RightChild());
            }            
        }
    }

    void BuildTree(std::vector<int> &arr){
        root = new Node(arr[0]);
        for (size_t i = 1; i < arr.size(); ++i) {
            insert(arr[i], root);
        }
    }

    void Search(int a, Node* ptr){
        if(ptr == nullptr){std::cout << "Такого числа нема! \n"; return;}
        else if (ptr->get_value() == a){std::cout << "Объект обнаружен"; return;}
        else if (ptr->get_value() < a){Search(a, ptr-> get_LeftChild());}
        else if (ptr->get_value() > a){Search(a, ptr-> get_RightChild());}
    }


};


int main() {
    std::vector<int> data = {5, 3, 7, 2, 4, 6, 8};
    SearchTree tree(data);
//    std::cout << tree.get_root();
    tree.SearchInTree(8);
    return 0;
}