#include<bits/stdc++.h>
using namespace std;

void max_heapify(int a[], int i, int n){

    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return;
}

void build_maxheap(int a[], int n){

    for(int i = n/2; i >= 1; i--){
        max_heapify(a, i, n);
    }
}

void heapsort(int a[], int n){

    for (int i = n; i>1; i--){
        swap(a[i],a[1]);
        max_heapify(a, 1, i - 1);
    }
}

void HeapSort(int a[],int n){

    for(int i=n; i>0; i--)swap(a[i],a[i-1]);

    build_maxheap(a,n);
    heapsort(a, n);

    for(int i=1; i<=n; i++)swap(a[i],a[i-1]);
}


int main(){


int a[100];
int n;
cout << "How many element you want to sort?" << endl;
cin >> n;
cout << "Enter the elements: " << endl;
for(int i=0; i<n; i++)cin >> a[i];

HeapSort(a,n);

for(int i=0; i<n; i++){
 cout << a[i];
 if(i != n-1)cout << " ";
 else cout << endl;
}
}
