#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *l, *r;
};

Node *tree = NULL;

void push(int a, Node **t) {
    if ((*t) == NULL) {
        (*t) = new Node;
        (*t)->info = a;
        (*t)->l = (*t)->r = NULL;
        return;
    }
        if (a > (*t)->info) {
            push(a, &(*t)->r);
        }
        else {
            push(a, &(*t)->l);
        }
}

void print(Node *t, int u) {
    if (t == NULL) {
        return;
    }
    else {
        print(t->l, ++u);
        for (int i = 0; i < u; ++i) cout << " ";
        cout << t->info << endl;
        u--;
    }
    print(t->r, ++u);
}

void shell(int n, int *arr) {
    int d = n/2;
    while (d > 0) {
        for (int i = 0; i < n - d; i++) {
            int j = i;
            while (j >= 0 && arr[j] > arr[j + d]) {
                int temp = arr[j];
                arr[j] = arr[j + d];
                arr[j + d] = temp;
                j--;
            }
        }
        d = d/2;
    }
}

int deleted(int n, int *arr) {
    for (int c = 0; c < n; c++) {
        for (int l = c + 1; l < n; l++) {
            if ( arr[c] == arr[l] ) {
                for (int s = l; s < n -1; s++) {
                    arr[s] = arr[s + 1];
                }
                n = n - 1;
                if (arr[c] == arr[l]) {
                    l--;
                }
            }
        }
    }
    return n;
}

void divide(int n, int *arr) {
    int mid = n/2;
    int arr2[n];
    arr2[0] = arr[mid];
    push (arr2[0], &tree);
    if (n % 2 == 0) {
       for (int i = 1; i < n / 1.95; i++) {
            arr2[i] = arr[mid - i];
            push(arr2[i], &tree);
            if (i < n/2) {
            arr2[i + 1] = arr[mid + i];
            push (arr2[i + 1], &tree);
            }
       }
    }
    else {
       for (int i = 1; i < n / 1.95; i++) {
            arr2[i] = arr[mid - i];
            push(arr2[i], &tree);
            arr2[i + 1] = arr[mid + i];
            push (arr2[i + 1], &tree);
       }
    }
}
int main() {
    int n;
    int s;
    cout << "Insert count of values: ";
    cin >> n;
    cout << "\n";
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Insert value: ";
        cin >> s;
        arr[i] = s;
    }
    shell(n, arr);
    n = deleted(n, arr);
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout <<"\n" << "\nArray length: " << n << "\n";
    divide(n, arr);
    cout << "\nYour tree: \n \n";
    print(tree, 0);
}
