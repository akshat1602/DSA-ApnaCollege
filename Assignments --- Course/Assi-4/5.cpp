#include <bits/stdc++.h>
using namespace std;

int main() {
	int n0 = 0, n1= 1, n2;
	int N; 
	cout<<"enter the limit : "<<endl;
	cin>>N;
	
	for(int i=1; i<=N; i++)
	{ 
	    n2 = n0 + n1;
	    n0 = n1;
	    n1 = n2;
}

cout<<n2;
return 0;
}