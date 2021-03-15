#include <iostream>
using namespace std;

struct Element {
    int data;
    Element *next;
};

void printStack(Element *top) {
	Element *element = top;
	while (element) {
		printf_s("%i ", element->data);
		element = element->next;
	}
}

void pushElement(Element **top, int value) {
	Element *element;
	element = new Element;
	element->data = value;
	if (top == NULL) {
		*top = element;
	}
	else {
		element->next = *top;
		*top = element;
	}
}

void reverseStack(Element*top, int length) {
    int i;
    int *arr = new int[length];
    int *temp = new int[length];
    Element *element = top;
        while (element) {
            temp[i] = element->data;
            element = element->next;
            i++;
        }
    for (int m = 0; m < length; m++) {
       arr[m] = temp[(length - 1) - m];
       cout << arr[m] << " ";
    }
}

void menuPrint() {
    system("cls");
    cout << "Choose variant\n" << endl;
    cout << "1. Insert length\n"
         << "2. Insert values\n"
         << "3. Show stack\n"
         << "4. Reverse stack\n"
         << "5. Exit\n" << endl;
    cout << ">>> ";
}

int main() {
    Element *top = NULL;
    int length;
    int variant;
    do {
        menuPrint();
        cin >> variant;
        switch (variant) {
            case 1:
                cout << "Insert length..." << endl;
                cin >> length;
                break;
            case 2:
                cout << "Insert your values..." << endl;
                for (int i = 0; i < length; i++) {
                    int value;
                    cin >> value;
                    pushElement(&top, value);
                }
                break;
            case 3:
                cout << "Showing stack..." << endl;
                printStack(top);
                break;
            case 4:
                cout << "Reversing stack..." << endl;
                reverseStack(top, length);
                break;
            case 5:
                cout << "Exiting..." << endl;
                exit(EXIT_SUCCESS);
                break;
            default:
                cerr << "You pick the wrong item, fool!" << endl;
                exit(EXIT_FAILURE);
        }
        if (variant <= 5) {
            system ("pause");
        }
    } while (variant <= 5);
    return 0;
}
