#include<bits/stdc++.h>
using namespace std;
#define MAXN 100


void Merge(int *arr, int start, int mid, int End){
    int n1 = mid-start+1, n2 = End-mid;
    int L[n1], R[n2], index=start, l=0, r=0;

    for(int i=0; i<n1; i++) L[i] = arr[start+i];
    for(int i=0; i<n2; i++) R[i] = arr[mid+1+i];

    while(l<n1 && r<n2){
        if(L[l]<=R[r])arr[index++]=L[l++];
        else arr[index++]=R[r++];
    }
    while(l<n1)arr[index++]=L[l++];
    while(r<n2)arr[index++]=R[r++];
}

void Merge_Sort(int *arr, int start, int End){
    if(start==End) return;
    int mid = (start+End)/2;
    Merge_Sort(arr, start, mid);
    Merge_Sort(arr, mid+1, End);
    Merge(arr, start, mid, End);
}

int main(){

    int n, arr[MAXN];
    cin >> n;
    cout << "enter inputs: " << endl;
    for(int i=0; i<n; i++) cin >> arr[i];

    Merge_Sort(arr, 0, n-1);

    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
return 0;
}
