#include <iostream>
using namespace std;
int main() {
    
    cout<<sizeof(int)<<endl;
    cout<<sizeof(long int)<<endl;

    int count = 0;
    do{
        cout<<"avc"<<endl;
        count++;
    }while(count<10);

    int  x=3, y=5, z=10;
    cout<<++z + y - y + z + x++<<endl;

    for (int i = 1; i <=5 ; i++)
    {
        for (int j = 5; j >= i; j--)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
    

    
    return 0;
}