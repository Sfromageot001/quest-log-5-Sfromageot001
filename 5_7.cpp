#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            std::swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    static std::vector<int> sortHeap(MaxHeap& maxHeap) {
        std::vector<int> sortedArray;

        while (!maxHeap.heap.empty()) {
            sortedArray.push_back(maxHeap.heap[0]); // Add root (max) value to sorted array
            maxHeap.heap[0] = maxHeap.heap.back(); // Replace root with last element
            maxHeap.heap.pop_back(); // Remove last element
            maxHeap.heapify(0); // Reheapify to maintain MaxHeap property
        }

        return sortedArray;
    }
};

int main() {
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);

    std::vector<int> sortedArray = MaxHeap::sortHeap(maxHeap);

    std::cout << "Sorted Array from MaxHeap: ";
    for (int val : sortedArray) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
