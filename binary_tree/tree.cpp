#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int info;
    node *l, *r;
};

node *tree = NULL;

void push(int a, node **t)
{
    if ((*t) == NULL)
    {
        (*t) = new node;
        (*t)->info = a;
        (*t)->l = (*t)->r = NULL;
        return;
    }
        if (a > (*t)->info) push(a, &(*t)->r);
        else push(a, &(*t)->l);
}

void print (node *t, int u)
{
    if (t == NULL) return;
    else
    {
        print(t->l, ++u);
        for (int i=0; i<u; ++i) cout << " ";
        cout << t->info << endl;
        u--;
    }
    print(t->r, ++u);
}

int main ()
{
    int n;
    int s;
    cout << "Insert count of values: ";
    cin >> n;
    cout << "\n";
    int arr[n];
    for (int i=0; i<n; ++i)
    {
        cout << "Insert value: ";
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (arr[j]==arr[j-1]) {

            }
        }
        arr[i] = s;
    }
    /* Shell sorting */
    int d = n/2;
    while (d > 0)
    {
        for (int i = 0; i < n - d; i++)
        {
            int j = i;
            while (j >= 0 && arr[j] > arr[j + d])
            {
                int temp = arr[j];
                arr[j] = arr[j + d];
                arr[j + d] = temp;
                j--;
            }
        }
        d = d/2;
    }
    /* Deleting dublicates */
    for (int c = 0; c < n; c++)
    {
        for (int l = c + 1; l < n; l++)
        {
            if ( arr[c] == arr[l] )
            {
                for (int s = l; s < n -1; s++)
                {
                    arr[s] = arr[s + 1];
                }
                n = n - 1;
                if (arr[c] == arr[l])
                {
                 l--;
                }
            }
        }
    };
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout <<"\n" << "\nArray length: " << n << "\n";
    /* Printing tree */
    int mid = n/2;
    int arr2[n];
    arr2[0] = arr[mid];
    push (arr2[0], &tree);

    if (n % 2 == 0) {
       for (int i=1; i < n/1.95; i++) {
            arr2[i] = arr[mid-i];
            push(arr2[i], &tree);
            if (i < n/2) {
            arr2[i+1] = arr[mid+i];
            push (arr2[i+1], &tree);
            }
       }
    }
    else {
       for (int i=1; i < n/1.95; i++)
       {
            arr2[i] = arr[mid-i];
            push(arr2[i], &tree);
            arr2[i+1] = arr[mid+i];
            push (arr2[i+1], &tree);
       }
    }
    cout << "\nYour tree: \n \n";
    print(tree, 0);
    cin.ignore().get();
}
