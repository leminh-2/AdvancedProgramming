#include <iostream>
#include <cstdlib>

using namespace std;
void create(string*& ptr,double*& score,int size){
    ptr = new string[size];
    score = new double[size];
}
void add(string*& ptr,double *& score,string temp,double sc,int capacity,int& pos){
    if(pos+1 >= capacity){
        cout<<"array is full!, can't add new student"<<endl;
    }
    else{
        ptr[pos+1] = temp;
        score[pos+1] = sc;
        pos++;
        cout<<"adding is successful"<<endl;
    }
}
void printNameScore(string* ptr,double* score,int pos){
    if(pos == -1){
        cout<<"array is empty"<<endl;
        return;
    } 
    //else: print
    for(int i=0 ; i < pos+1 ; i++){
        cout<<"student"<<i+1<<" "<<ptr[i];
        cout<<" with score: "<<score[i]<<endl;
    }
}
void nameOfBestScore(string* ptr,double* score,int pos){
    double bestScore = 0;
    for(int i=0 ; i < pos+1; i++){
        if(score[i] > bestScore) bestScore = score[i];
    }
    cout<<"best score: "<<bestScore<<"\tfrom student(s):"<<endl;
    for(int i=0 ; i < pos+1 ; i++){
        if(bestScore == score[i]) cout<<ptr[i]<<endl;
    }
}
