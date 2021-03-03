#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

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

void menu()
{
    system("cls");
    cout << "Choose variant\n" << endl;
    cout << "1. Insert length\n"
         << "2. Insert values\n"
         << "3. Show stack\n"
         << "4. Reverse stack\n"
         << "5. Exit\n" << endl;
    cout << ">>> ";
}

int get_variant () {

    int variant;
    cin >> variant;
    return variant;

}

int main()
{
    int length;
    int variant;
    int *arr = new int [length];
    do {
            menu();
            variant = get_variant();

    switch (variant) {

        case 1:
            cout << "Insert your length..." << endl;
            cin >> length;
            break;
        case 2:
            cout << "Insert your values..." << endl;
            for (int i = 0; i < length; i++) {
            int v;
            cin >> v;
            Element *ptr = new Element;
            ptr->Data = v;
            arr[i] = ptr->Data;
            }
            break;
        case 3:
            cout << "Showing stack..." << endl;
            for (int j = 0; j < length; j++) {
            cout << arr[j] <<' ';
            }
            cout << endl;
            break;
        case 4:
            cout << "Reversing stack..." << endl;
            reversed(arr, length);
            for (int j = 0; j < length; j++) {
            cout << arr[j] <<' ';
            }
            break;
        case 5:
            cout << "Exiting..." << endl;
            exit(EXIT_SUCCESS);
            break;
        default:
            cerr << "You pick the wrong item, fool!" << endl;
            exit(EXIT_FAILURE);
    }

    if (variant != 6)
        system ("pause");
      }  while (variant != 6);

    return 0;
}
