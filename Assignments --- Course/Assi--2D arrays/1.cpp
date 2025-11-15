#include <iostream>
using namespace std;

int count7(int(*arr)[3], int n, int m){
    int cnt7 = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == 7){
                cnt7++;
            }
        }
        
    }
    return cnt7;
}

int main() {
    int arr[3][3] = {
        {4,7,7},
        {5,8,9},
        {7,7,7}
    };

    cout<<"Occurence of 7 : "<<count7(arr, 3, 3)<<endl;
    return 0;
}