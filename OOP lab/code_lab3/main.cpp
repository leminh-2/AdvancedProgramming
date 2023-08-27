#include "main.h"

int main(){
    system("cls");
    int option = 0;
    StudentClass* std = nullptr;
    int pos = -1; //default value = -1  
    int capacity = 0;
    do{
        //system("cls");
        cout<<"--------------------------------"<<endl;
        cout<<"list of functionality"<<endl;
        cout<<"1. create and add a new student object to the list of students"<<endl;
        cout<<"2. display the list of all students and the scores"<<endl;
        cout<<"3. display the best student(s)'s name(s) and their score(s)"<<endl;
        cout<<"4. remove a student from the list based on the name input"<<endl;
        cout<<"0. End"<<endl;
        cout<<"Choose options: ";
        cin>>option;

        switch(option){
            case 1: 
            {
                if(std == nullptr){
                    cout<<"The list hasn't been initialized, enter the number of students: ";
                    cin>>capacity;
                    
                    if(capacity <= 0){ throw out_of_range("input of size is invalid -> failed.");}
                    else { 
                        std = new StudentClass[capacity];
                    }
                }
                if(pos == capacity -1){ cout<<"list is full"<<endl; break;}
                //else
                cout<<"enter the name of student: ";
                string tmpStr; cin>>tmpStr;
                cout<<"enter the score of student: ";
                double tmpNum; cin>>tmpNum;
                
                std[++pos].setName(tmpStr);
                std[pos].setScore(tmpNum);
                
                break;
            }
            case 2: 
            {
                if(pos == -1) cout<<"list is empty"<<endl;
                for(int i=0; i<=pos; i++){
                    std[i].printStd();
                }
                break;
            }
            case 3: 
            {
                if(pos == -1) {cout<<"list is empty"<<endl; break;}
                std[0].nameOfBestScore(pos+1);
                break;
            }
            case 4: 
            {
                if(pos == -1) {cout<<"list is empty"<<endl; break;}
                cout<<"enter the removed name: ";
                string name; cin>>name;
                int find = std[0].find(name,pos+1);
                if(find == -1){
                cout<<"Could not find   "<<name<<endl;
                }
                else{
                    if(find == pos){
                        if(find == 0){
                            delete[] std;
                            std = nullptr;
                            pos = -1;
                        }
                        else{
                            std[find].setName("");
                            std[find].setScore(0);
                            pos--;
                        }
                    }
                    else{
                        for(int i = find; i < pos; i++){
                            std[find].setName(std[find+1].getName());
                            std[find].setScore(std[find+1].getScore());
                        }
                        pos--;
                    }
                }
                break;
            }
            case 0: 
            {
                delete[] std;
                std = nullptr;
                break;
            }
        }


    }while(option != 0);


    return 0;
}