#include <vector>
#include <iostream>

class MaxHeap{
public:

    MaxHeap(const std::vector<int>& arr) : heapArr(arr), heapSize(arr.size()) {
        for (int i = heapSize / 2 - 1; i >= 0; --i) {
            SiftDown(i);
        }
    };

    void Insert(int a){
        heapSize++;
        heapArr.push_back(a);
        SiftUp(heapSize - 1);
    }

    int getMax(){return heapArr[0];}
    
    void extractMax(){
        std::swap(heapArr[0], heapArr[heapSize - 1]);
        heapArr.pop_back();
        heapSize--;
        SiftDown(0);
    }

private:    
    std::vector<int> heapArr;
    int heapSize;

    void SiftUp(int ind){

        if (ind == 0) {return;}

        int parent = (ind - 1) / 2;

        if (heapArr[ind] <= heapArr[parent]){
            return;
        } else {
            std::swap(heapArr[ind], heapArr[parent]);
            SiftUp(parent);
        }
    }

    void SiftDown(int ind){

        int leftChild = 2 * ind + 1;
        int rightChild = 2 * ind + 2;
        int largest = ind;

        if (leftChild < heapSize && heapArr[leftChild] > heapArr[largest]) {
            largest = leftChild;
        }
        if (rightChild < heapSize && heapArr[rightChild] > heapArr[largest]) {
            largest = rightChild;
        }

        if (largest != ind) {
            std::swap(heapArr[ind], heapArr[largest]);
            SiftDown(largest);
        }
    }    
};


int main(){

    std::vector<int> arr = {1, 2, 4, 0, 12, -3};
    MaxHeap heap(arr);
    for (int i = 0; i < arr.size(); ++i){
        std::cout << heap.getMax() << "\n";
        heap.extractMax();
    }
    return 0;
}