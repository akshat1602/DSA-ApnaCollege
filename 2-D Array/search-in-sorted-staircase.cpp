//TC : O(n+m)
//if n>>>m --> TC : O(n) --> more rows(bhot zyada)
//if m>>>n --> TC : O(m) --> more cols(bhot zyada)

#include <iostream>
using namespace std;

bool search(int mat[][4], int n, int m, int key){ // Start cell: top right.
    int i = 0, j = m-1;

    while(i < n && j >= 0){
        if(mat[i][j] == key){
            cout<<"Found at cell : "<<"("<<i<<","<<j<<")"<<endl;
            return true;
        }
        else if(mat[i][j] < key){
            //down
            i++;
        }
        else{
            //left
            j--;
        }
    }
    cout<<"Key not found!"<<endl;
    return false;
}

bool search1(int mat[][4], int n, int m, int key){ //Changed the starting cell to bottom left.
    int i = n-1, j = 0;

    while(i >= 0 && j < m){
        if(mat[i][j] == key){
            cout<<"Found at cell : "<<"("<<i<<","<<j<<")"<<endl;
            return true;
        }
        else if(mat[i][j] < key){
            //right
            j++;
        }
        else{
            //top
            i--;
        }
    }
    cout<<"Key not found!"<<endl;
    return false;
}

int main()
{
    int arr[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}};

    int key;
    cout<<"enter the key : "<<endl;
    cin>>key;

    search(arr, 4, 4, key);
    search1(arr, 4, 4, key);
    return 0;
}