#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *tree = NULL;

void pushIntoTree(int value, Node **ptr) {
    if (*ptr == NULL) {
        (*ptr) = new Node;
        (*ptr)->data = value;
        (*ptr)->left = (*ptr)->right = NULL;
        return;
    }
        if (value > (*ptr)->data) {
            pushIntoTree(value, &(*ptr)->right);
        }
        else {
            pushIntoTree(value, &(*ptr)->left);
        }
}

void printTree(Node *ptr, int j) {
    if (ptr == NULL) {
        return;
    }
    else {
        printTree(ptr->left, ++j);
        for (int i = 0; i < j; ++i) {
            cout << " ";
        }
        cout << ptr->data << endl;
        j--;
    }
    printTree(ptr->right, ++j);
}

void sortShell(int length, int *arr) {
    int middle = length/2;
    while (middle > 0) {
        for (int i = 0; i < length - middle; i++) {
            int j = i;
            while (j >= 0 && arr[j] > arr[j + middle]) {
                int temp = arr[j];
                arr[j] = arr[j + middle];
                arr[j + middle] = temp;
                j--;
            }
        }
        middle = middle/2;
    }
}

int deleteFromArray(int length, int *arr) {
    for (int c = 0; c < length; c++) {
        for (int l = c + 1; l < length; l++) {
            if ( arr[c] == arr[l] ) {
                for (int s = l; s < length -1; s++) {
                    arr[s] = arr[s + 1];
                }
                length = length - 1;
                if (arr[c] == arr[l]) {
                    l--;
                }
            }
        }
    }
    return length;
}

void defineSubtree(int length, int *arr) {
    int middle = length/2;
    int shift[length];
    shift[0] = arr[middle];
    pushIntoTree(shift[0], &tree);
    if (length % 2 == 0) {
       for (int i = 1; i < length / 2; i++) {
            shift[i] = arr[middle - i];
            pushIntoTree(shift[i], &tree);
            if (i < length / 2) {
            shift[i + 1] = arr[middle + i];
            pushIntoTree(shift[i + 1], &tree);
            }
       }
    }
    else {
       for (int i = 1; i < length / 1.95; i++) {
            shift[i] = arr[middle - i];
            pushIntoTree(shift[i], &tree);
            shift[i + 1] = arr[middle + i];
            pushIntoTree(shift[i + 1], &tree);
       }
    }
}
int main() {
    int length;
    int value;
    cout << "Insert count of values: ";
    cin >> length;
    cout << "\n";
    int arr[length];
    for (int i = 0; i < length; i++) {
        cout << "Insert value: ";
        cin >> value;
        arr[i] = value;
    }
    sortShell(length, arr);
    length = deleteFromArray(length, arr);
    cout << "\nSorted array: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout <<"\n" << "\nArray length: " << length << "\n";
    defineSubtree(length, arr);
    cout << "\nYour tree: \n \n";
    printTree(tree, 0);
}
