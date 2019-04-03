#include <iostream>
using namespace std;

class Heap {
	private:
		int capacity;
		int size;
		int *arr;
	public:
		Heap(int cap);
		void heapify(int i); //heapify at the root index
		int extractMin(); //extract the root
		void decreaseKey(int i, int v); //decrease value of i element
		int getMin(); //return the root
		void deleteKey(int i); //delete key at i
		void insertKey(int v); //insert key value
		int parent(int i) {
			return (i - 1) / 2;
		}
		int lchild(int i) {
			return 2 * i + 1;
		}
		int rchild(int i) {
			return 2 * i + 2;
		}
};

//swap utility
void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

Heap::Heap(int cap) {
	capacity = cap;
	arr = new int[cap];
	size = 0;
}

void Heap::insertKey(int k) {
	if (size == capacity) {
		cout << endl << "ERROR: HEAP IS FULL" << endl;
		return;
	}
	//insert new key at the end
	int i = size;
	arr[i] = k;
	size++;
	//fix the heap property if it is violated
	while (i != 0 && arr[parent(i)] > arr[i]) {
		swap(arr[i], arr[parent(i)]);
		i = parent(i);
	}
}

int Heap::getMin() {
	return arr[0];
}

void Heap::decreaseKey(int i, int v) {
	arr[i] = v;
	while (i != 0 && arr[parent(i)] > arr[i]) {
		swap(arr[i], arr[parent(i)]);
		i = parent(i);
	}
}

//heapify with the root at given index, this method assumes that the subtrees are already heapified
void Heap::heapify(int i) {
	int l = lchild(i);
	int r = rchild(i);
	int smallest = i;

}
