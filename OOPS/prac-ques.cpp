#include <iostream>
#include <string>
using namespace std;

class User{
    string password;
    int id;

public:
    string username;

    User(int id){
        this->id = id;
    }
 
    //Setter
    void setPassword(string password){
        this->password = password;
    }

    //Getter
    string getPassword(){
        return password;
    }
};

int main() {
    User u1(123);
    u1.username = "Akshat";
    u1.setPassword("abc@123");

    cout<<"Username is : "<<u1.username<<endl; //direct access as public
    cout<<"Password is : "<<u1.getPassword()<<endl; //by getter and setter as its private
    
    return 0;
}