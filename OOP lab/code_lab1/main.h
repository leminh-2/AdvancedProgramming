#include <iostream>
#include <cstdlib>

using namespace std;
void createList(string*& ptr,int size){
    ptr = new string[size];
}
void add(string*& ptr,string temp,int capacity,int& pos){
    if(pos+1 >= capacity){
        cout<<"array is full!, can't add new student"<<endl;
    }
    else{
        ptr[pos+1] = temp;
        pos++;
        cout<<"adding is successful"<<endl;
    }
}
void printName(string* ptr,int pos){
    if(pos == -1){
        cout<<"array is empty"<<endl;
        return;
    } 
    //else: print
    for(int i=0 ; i < pos+1 ; i++){
        cout<<"student's name"<<i+1<<" :"<<ptr[i]<<endl;
    }
}
void rem(string*& ptr,string tempStr,int& pos){
    if(pos == -1){
        cout<<"array is empty, removing is failed"<<endl; 
        return;
    }
    //else: find the name
    int walk = -1;
    for(int i=0 ; i < pos+1 ; i++){
        if(ptr[i]==tempStr){
            walk = i;
            break;
        }
    }
    if(walk == -1){
        cout<<"student's name is included in the array"<<endl;
        return;
    }
    //else: remove the name
    for(; walk < pos+1 ; walk++){
        if(walk == pos) {
            ptr[walk] = "";
            pos--;
        }
        else{ ptr[walk] = ptr[walk+1];}
    }
    cout<<"student's name is founded, removing is successful"<<endl;
}
