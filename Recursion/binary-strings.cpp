#include <iostream>
#include <cstring>
using namespace std;

void binString(int n, int lastPlace, string ans){
    if(n == 0){
        cout<<ans<<endl;
        return;
    }

    if(lastPlace != 1){
        binString(n-1, 0, ans+'0');
        binString(n-1, 1, ans+'1');
    }
    else{
        binString(n-1, 0, ans+'0');
    }
}

void binString2(int n, string ans){
    if(n == 0){
        cout<<ans<<endl;
        return;
    }

    if(ans[ans.size()-1] != '1'){ //yahan == 0 nahi karna, as empty string mein it wont run and wrong answer will come.
        binString2(n-1, ans+'0');
        binString2(n-1, ans+'1');
    }
    else{
        binString2(n-1, ans+'0');
    }
}

int main() {
    string ans = "";
    int n;
    cout<<"enter number :"<<endl;
    cin>>n;
    binString(n, 0, ans);
    cout<<"---------------------\n";
    binString2(n, ans);
    
    return 0;
}