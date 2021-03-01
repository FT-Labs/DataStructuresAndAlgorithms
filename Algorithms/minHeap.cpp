/*
Author: Arda
Company: PhysTech
Date: 9/26/20
*/
#include  <iostream>
#include <climits>
using namespace std;

//Prototype function to swap two integers
void swap(int *x,int *y);

class MinHeap{
    int *harr; //Pointer to array of elements in heap
    int capacity; //Max size of heap
    int heapSize; //Current number of elements of heap
public:
    MinHeap(int capacity);

    //To heapify a a subtree with root
    void MinHeapify(int i );

    //To get the parent node index at index i
    int parent(int i) {return (i-1)/2;}

    //To get left node at index i
    int left(int i) {return (2*i)+1;}

    //To get right node at index i
    int right(int i) {return (2*i+2);}

    //To extract the root which is the minimum element
    int extractMin();
    //Decreases key value of key at index i to new values
    void decreaseKey(int i,int newVal);

    //Returns the minimum key from heap
    int getMin() {return harr[0];}
    //Deletes a key stored at index i
    void deleteKey(int i);

    //Inserts a new key
    void insertKey(int n);

};

MinHeap::MinHeap(int cap)
{
    heapSize = 0;
    capacity = cap;
    harr = new int[cap];
}


void MinHeap::insertKey(int n) {
    if (heapSize == capacity) {
        cout << "Max heap size reached:Overflow\n";
        return;
    }

    ++heapSize;
    int i = heapSize - 1;
    harr[i] = n;

    //Fix min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}


//Decreases value of key at index 'i' to new value. Assumed that new value is < harr[i]

void MinHeap::decreaseKey(int i, int newVal)
{
    harr[i] = newVal;
    while (i!=0 && harr[parent(i)]>harr[i])
    {
        swap(&harr[i],&harr[parent(i)]);
        i = parent(i);
    }
}


//Method to remove min element
int MinHeap::extractMin()
{
    if(heapSize<=0)
        return INT_MAX;
    if(heapSize == 1)
    {
        --heapSize;
        return harr[0];
    }

    //Stoe minimum value than remove it from the heap
    int root = harr[0];
    harr[0] = harr[heapSize-1];
    --heapSize;
    MinHeapify(0);

    return root;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l<heapSize && harr[l]<harr[i])
        smallest = l;
    if(r<heapSize && harr[r]<harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i],&harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}





int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}

