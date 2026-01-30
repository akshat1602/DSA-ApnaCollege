#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

void printArray(vector <int> height){
    for (int i = 0; i < height.size(); i++)
    {
        cout<<height[i]<<" ";
    }
    cout<<endl;
}

void maxAreaHistogram(vector <int> height){ //O(n)
    int n = height.size();
    vector <int> nsl(n); //nextsmaller left
    vector <int> nsr(n); //nextsmaller right
    stack <int> s; 

    //nextsmaller Left
    nsl[0] = -1; //cause 1st position element ka koi smaller left nhi hota
    s.push(0);

    for (int i = 1; i < height.size(); i++)
    {
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]){
            s.pop();
        }

        if(s.empty()){
            nsl[i] = -1;
        }
        else{
            nsl[i] = s.top();
        }
        s.push(i); //current ka index push karna hai
    }
    printArray(nsl);

    while(!s.empty()){ //emptying stack for finding nextsmaller right
        s.pop();
    }
    
    //nextsmaller Right
    s.push(n-1); //pushing the index in stack yabhi n-1 karrhe
    nsr[n-1] = n;

    for (int i = n-2; i >= 0; i--)
    {
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]){
            s.pop();
        }

       if(s.empty()){
            nsr[i] = n;
        }
        else{
            nsr[i] = s.top();
        }
        s.push(i);
    }
    printArray(nsr);
    
    //For Area
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int ht = height[i];
        int width = nsr[i] - nsl[i] - 1; // **width = r-l-1;
        int area = ht * width;

        maxArea = max(area, maxArea);
    }

    cout<<"Max area of histogram : "<<maxArea<<endl;
}


int main() {
    vector <int> height = {2, 1, 5, 6, 2, 3};
    maxAreaHistogram(height);
    return 0;
}