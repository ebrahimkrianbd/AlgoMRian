#include<bits/stdc++.h>
#define Infinity 99999999
using namespace std;


void Floyed_Warshall(int arr[100][100]){
    for(int k=0; k<10; k++)
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                arr[i][j] = min(arr[i][j] , arr[i][k] + arr[k][j]);

}

int main(){
    int arr[100][100];
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++){
            arr[i][j]=Infinity;
            if(i==j)arr[i][j]=0;
        }

    int v, e;
    cout << "How many vertex?" << endl;
    cin >> v;
    cout << "How many edge?" << endl;
    cin >> e;
    cout << "Enter the values:" << endl;
    for(int i=0; i<e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b]=c;
    }

    Floyed_Warshall(arr);

    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            cout << i << " " << j << " " << arr[i][j] << endl;

return 0;
}
