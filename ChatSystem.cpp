#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <chrono>
#include <thread>
#include <string>
#include <limits>
using namespace std;

int main(){
    cout<<"Welcome to Hamza's Chat Server!";
    cout<<"Enter System Type : \n1. Recieving Client \n2. Output Client\nChoice : ";
    int choice;
    cin>>choice;
    if (choice==2){
    cout<<"Enter your username :";
    string filepath="/home/kali/Desktop/Problem2/chat.txt";
    string name;
    cin>>name;
    cout<<"Welcome to the chat "<<name<<"! You can start by simply typing messages and pressing enter!"<<endl;
    string message;

    int id=fork();
    while(1){
        if(id){
            wait(NULL);
            id=fork();
        }
        else{
            system("clear");
            cout<<"Type a message "<<name<<" : ";
            getline(cin, message);
            getline(cin, message);
            message=name+" : "+message;
            execlp("sh", "sh", "-c", ("echo \""+message+"\" >> "+filepath).c_str(), NULL);
            exit(1);
        }
    }
    }
    else if (choice==1){
     string filepath="/home/kali/Desktop/Problem2/chat.txt";
	cout<<"Welcome to hamza's server chat display!";

    int id=fork();
    while(1){
        if(id){
            wait(NULL);
            id=fork();
        }
        else{
            this_thread::sleep_for(chrono::milliseconds(2000));
	    system("clear");
            execlp("cat", "cat", filepath.c_str(), NULL);
            exit(1);
        }
    }
    return 0;
    }
    else cout<<"Invalid Choice!";
}
