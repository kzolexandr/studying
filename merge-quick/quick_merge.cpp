#include <iostream>
using namespace std;

void merge(int *arr, int fr, int ls) {
    int mid, st, fin, j;
    int *temp = new int[ls];
    mid = (fr + ls) / 2;
    st = fr;
    fin = mid + 1;
    for (j = fr; j <= ls; j++)
    if ((st <= mid) && ((fin > ls) || (arr[st] < arr[fin]))) {
        temp[j] = arr[st];
        st++;
        }
    else {
        temp[j] = arr[fin];
        fin++;
    }
    for (j = fr; j <= ls; j++)
    arr[j] = temp[j];
};

void sort(int *arr, int fr, int ls) {
    if (fr < ls) {
        sort(arr, fr, (fr + ls) / 2);
        sort(arr, (fr + ls) / 2 + 1, ls);
        merge(arr, fr, ls);
    }
}

void quick (int *temp, int fr, int ls) {
    int mid, c;
    int f=fr, l=ls;
    mid=temp[(f+l) / 2];
    do {
    while (temp[f]<mid) f++;
    while (temp[l]>mid) l--;
    if (f<=l) {
    c=temp[f];
    temp[f]=temp[l];
    temp[l]=c;
    f++;
    l--;
    }
    } while (f<l);
    if (fr<l) quick(temp, fr, l);
    if (f<ls) quick(temp, f, ls);
    }

int main () {
    int var;
    cout << "Which algorithm you would like to use? \n";
    cout << "push 1 to merge \n";
    cout << "push 2 to quick \n";
    cin >> var;
    if (var == 1) {
    int i, n;
    cout << "Array length > ";
    cin >> n;
    int *arr = new int[n];
    for (i = 1; i <= n; i++) {
    cout << i << " element > ";
    cin >> arr[i];
    }
    sort(arr, 1, n);
    cout << "Sorted array: ";
    for (i = 1; i <= n; i++)
    cout << arr[i] << " ";
    }
    else if (var == 2) {
    int i, n;
    cout << "Array length > ";
    cin >> n;
    int *arr = new int[n];
    for (i = 0; i < n; i++) {
    cout << i << " element > ";
    cin >> arr[i];
    }
    int fr = 0;
    int ls = n-1;
    quick (arr, fr, ls);
    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
    cout << arr[i] << " ";
    }
    else {
    cout << "You pick the wrong item!";
    }
}
