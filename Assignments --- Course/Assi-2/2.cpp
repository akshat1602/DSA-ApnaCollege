#include<iostream>
using namespace std;

int main(){
    float pencil;
    float pen;
    float eraser;

    cout << "Enter the price of pencil: ";
    cin >> pencil;
    cout << "Enter the price of pen: ";
    cin >> pen;
    cout << "Enter the price of eraser: ";
    cin >> eraser;

    float total_items = pencil + pen + eraser;
    cout << "Total price of items without gst: " << total_items << endl;

    float gst = total_items * 0.18;
    cout << "Total price of items with gst: " << total_items + gst << endl;

    return 0;
}