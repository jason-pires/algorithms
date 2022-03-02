#include <vector>

using std::vector;

void swap(vector<int> arr, int positionA, int positionB) {
    int temp = arr[positionA];
    arr[positionA] = arr[positionB];
    arr[positionB] = temp;
}

int partition(vector<int> arr, int start, int end) {
    int i = start;
    for (int j = start; j < end; j++) {
        if (arr[j] <= arr[end]) {
            swap(arr,i, j);
            i++;
        }
    }
    swap(arr, i, end);
    return i;
}

void quickSort(vector<int> arr, int start, int end){
    if(start > end) {
        return;
    }

    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot -1);
    quickSort(arr, pivot +1, end);
}

int main(int argc, char* argv[]) {
    vector<int> elements = {50, 42, 8, 23, 74, 91, 13, 26, 66, 3};
    quickSort(elements, 0, elements.size()-1);
}