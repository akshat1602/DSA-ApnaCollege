#include <iostream>
#include <string>
using namespace std;

int linearsearch(int a[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if(a[i]==key)
        {
            return i;
        }
    }
    return -1;
    
}
int main()
{
int a[] = {3,6,7,1,9};
int size = 5;
int key;
cout<<"enter element to  be searched : "<<endl;
cin>>key;

cout<<linearsearch(a,size,key)<<endl;
return 0;
}