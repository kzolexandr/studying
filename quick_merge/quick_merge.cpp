#include <iostream>
using namespace std;

void mergeSort(int *arr, int first, int last) {
    int *temp = new int[last];
    int middle = (first + last) / 2;
    int start = first;
    int final = middle + 1;
    for (int j = first; j <= last; j++) {
        if ((start <= middle) && ((final > last) || (arr[start] < arr[final]))) {
            temp[j] = arr[start];
            start++;
        }
        else {
            temp[j] = arr[final];
            final++;
        }
    }
    for (int j = first; j <= last; j++) {
        arr[j] = temp[j];
    }
}

void sortSubarray(int *arr, int first, int last) {
    if (first < last) {
        sortSubarray(arr, first, (first + last) / 2);
        sortSubarray(arr, (first + last) / 2 + 1, last);
        mergeSort(arr, first, last);
    }
}

void quickSort(int *temp, int first, int last) {
    int f = first;
    int l = last;
    int middle = temp[(f + l) / 2];
    do {
    while (temp[f] < middle) {
        f++;
    }
    while (temp[l] > middle) {
        l--;
    }
    if (f <= l) {
        int c = temp[f];
        temp[f] = temp[l];
        temp[l] = c;
        f++;
        l--;
    }
    } while (f < l);
    if (first < l) {
        quickSort(temp, first, l);
    }
    if (f < last) {
        quickSort(temp, f, last);
    }
}

int main() {
    int variant;
    int length;
    cout << "Array length > ";
    cin >> length;
    int *arr = new int[length];
    for (int i = 1; i <= length; i++) {
        cout << i << " > ";
        cin >> arr[i];
    }
    int first = 1;
    int last = length;
    cout << "Which algorithm you would like to use?" << endl;
    cout << "\n1. Merge sort\n"
         << "2. Quick sort\n" << endl;
    cout << ">>> ";
    cin >> variant;
    switch (variant) {
        case 1:
            sortSubarray(arr, 1, length);
            cout << "Sorted array: ";
            for (int i = 1; i <= length; i++) {
            cout << arr[i] << " ";
            }
            break;
        case 2:
            quickSort(arr, first, last);
            cout << "Sorted array: ";
            for (int i = 1; i <= length; i++) {
            cout << arr[i] << " ";
            }
            break;
        default:
            cout << "You pick the wrong item!";
            break;
    }
}
