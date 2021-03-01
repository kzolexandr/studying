#include<iostream>
using namespace std;

struct Element {

int Data;
Element *next;

};

void reversed(int *arr, int length) {

int *_arr = new int[length];

    for (int k = 0; k < length; k++) _arr[k] = arr[k];

    for (int m = 0; m < length; m++) {
        arr[m] = _arr[(length - 1) - m];
    }

}

void push (int v,int t, int *arr) {


    Element *ptr = new Element;
    ptr->Data = v;
    arr[t] = ptr->Data;


}
int main() {

    int length;

    cout << "Insert length:" << endl;
    cin >> length;

    int *arr = new int [length];
/*
    cout << "Insert values:" << endl;
for (int i = 0; i < length; i++) {
    int v;
    cin >> v;

    Element *ptr = new Element;
    ptr->Data = v;
    arr[i] = ptr->Data;
}
*/

    push(5, 0, arr);
    push(6, 1, arr);
    push(7, 2, arr);

    cout << "Your stack:" << endl;
for (int j = 0; j < length; j++) {

    cout << arr[j] <<' ';
}
    cout << endl;
reversed(arr, length);
    cout << "Reversed stack:" << endl;
for (int j = 0; j < length; j++) {

    cout << arr[j] <<' ';
}

}
