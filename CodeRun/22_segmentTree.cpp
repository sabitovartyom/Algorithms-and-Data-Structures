#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

struct Node {
    int minimum;
    int left, right;
    Node* leftChild;
    Node* rightChild;
    Node(int l, int r) : left(l), right(r), leftChild(nullptr), rightChild(nullptr), minimum(INT_MAX) {}
};

struct Tree {
    Node* root;
    int N;

    Tree(const std::vector<int>& arr) {
        N = arr.size();
        root = buildTree(0, N - 1, arr);
    }

    Node* buildTree(int l, int r, const std::vector<int>& arr) {
        Node* node = new Node(l, r);
        if (l == r) {
            node->minimum = arr[l];
        } else {
            int m = (l + r) / 2;
            node->leftChild = buildTree(l, m, arr);
            node->rightChild = buildTree(m + 1, r, arr);
            node->minimum = std::min(node->leftChild->minimum, node->rightChild->minimum);
        }
        return node;
    }

    int getMin(Node* node, int L, int R) {
        if (!node) return INT_MAX;
        if (L <= node->left && node->right <= R) return node->minimum;
        int res1 = getMin(node->leftChild, L, R);
        int res2 = getMin(node->rightChild, L, R);
        return std::min(res1, res2);
    }

    int getMinInRange(int L, int R) {
        return getMin(root, L, R);
    }
};

int main() {
    int N, k;
    std::cin >> N >> k;
    
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    Tree tree(arr);

    for (int i = 0; i <= N - k; i++) {
        std::cout << tree.getMinInRange(i, i + k - 1) << std::endl;
    }

    return 0;
}
