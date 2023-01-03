#include<bits/stdc++.h>
using namespace std;

class BinaryHeap {
private:
    const static int MAX_SIZE = 15;
    int heap[MAX_SIZE];
    int size;

public:
    BinaryHeap() {
        size = 0;
    }

    
     int parent(int i) {
        return (i - 1) / 2;
    }

  
     int leftChild(int i) {
        return 2*i + 1;
    }

   
     int rightChild(int i) {
        return 2*i + 2;
    }


    static void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    // insert the item
    void insert(int data) {
        if (size >= MAX_SIZE) {
            cout<<"The heap is full. Cannot insert"<<endl;
            return;
        }

        // first insert the time at the last position of the array 
        // and move it up
        heap[size] = data;
        size = size + 1;


        // move up until the heap property satisfies
        int i = size - 1;
        while (i != 0 && heap[BinaryHeap::parent(i)] < heap[i]) {
            BinaryHeap::swap(&heap[BinaryHeap::parent(i)], &heap[i]);
            i = BinaryHeap::parent(i);
        }
    }

    // moves the item at position i of array a
    // into its appropriate position
    void maxHeapify(int i){
      
        int left = BinaryHeap::leftChild(i);

       
        int right = BinaryHeap::rightChild(i);

        
        int largest = i;

        
        if (left <= size && heap[left] > heap[largest]) {
            largest = left;
        }

       
        if (right <= size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            maxHeapify(largest);
        }

    }

    // returns the  maximum item of the heap
    int getMax() {
        return heap[0];
    }

    // deletes the max item and return
    int extractMax() {
        int maxItem = heap[0];

        
        heap[0] = heap[size - 1];
        size = size - 1;

       
        maxHeapify(0);
        return maxItem;
    }

   
    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout<<endl;
        }
        cout<<endl;
    }
};

int main() {
    BinaryHeap heap;
    return 0;
}
