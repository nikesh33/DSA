#include <iostream>
using namespace std;

class Heap
{
public:
    int *arr;
    int capacity;
    int size;

    // Ctor
    Heap(int capacity)
    {
        this->arr = new int[capacity]; //capacity will 20
        this->capacity = capacity;
        // size = current number of element in heap
        this->size = 0;
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap OverFlow" << endl;
            return;
        }
        // size increase kar jayega
        size++;
        int index = size;
        arr[index] = val;

        // Heapify
        // take the val to its correct position
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    ~Heap() // Destructor to free memory
    {
        delete[] arr;
    }
};

int main()
{
    Heap h(20);
    // Insertion
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);

    cout << "Printing the content of heap: " << endl;
    h.printHeap();
    return 0;
}