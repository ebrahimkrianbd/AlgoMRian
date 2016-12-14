#include<bits/stdc++.h>
using namespace std;
#define MAXN 100

void CountingSort(int *arr, int n){

    int Max = *max_element(arr, arr+n)+5;
    cout << Max << endl;
    int helper[Max] = {0};
    for(int i=0; i<n; i++){
        helper[arr[i]]++;
    }
    int idx = 0;
    for(int i=0; i<Max; i++){
        while(helper[i]--){
            arr[idx++] = i;
        }
    }

}

int main(){

    int n, arr[MAXN];
    cin >> n;
    cout << "enter inputs: " << endl;
    for(int i=0; i<n; i++) cin >> arr[i];

    CountingSort(arr, n);

    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
return 0;
}
