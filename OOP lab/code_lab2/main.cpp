#include "main.h"

int main(){
    system("cls");
    int option = 0;
    string* ptr;
    double* score;
    int pos = -1; //default value = -1  
    int capacity = 0;
    do{
        //system("cls");
        cout<<"--------------------------------"<<endl;
        cout<<"list of functionality"<<endl;
        cout<<"1. Create pointers to store two lists of all students' names and students' scores"<<endl;
        cout<<"2. add a new student and the corresponding score"<<endl;
        cout<<"3. display the list of all students and their scores"<<endl;
        cout<<"4. display the best student(s)'s name(s) and their score(s)"<<endl;
        cout<<"0. End"<<endl;
        cout<<"Choose options: ";
        cin>>option;

        switch(option){
            case 1: 
            {
                //case: existed array of students
                if(capacity > 0) {
                    cout<<"existed memory, do you want to remove it and create new one?"<<endl;
                    cout<<"please enter Y / other keys:";
                    string decide; cin>>decide;
                    if(decide == "Y"){
                        delete[] ptr; //deallocate memory
                        delete[] score; //deallocate memory
                        //set default values
                        capacity = 0;
                        pos = -1;
                    }
                    else break;
                }

                cout<<"enter the number of students:";
                cin>>capacity;
                
                if(capacity <= 0){ throw out_of_range("input of size is invalid -> failed.");}
                else { 
                    create(ptr,score,capacity);
                }
                break;
            }
            case 2: 
            {
                string temp;
                cout<<"enter new student name:";
                cin>>temp;
                double sc;
                cout<<"enter the corresponding score:";
                cin>>sc; cout<<'\n';
                add(ptr,score,temp,sc,capacity, pos);
                break;
            }
            case 3: 
            {
                printNameScore(ptr,score,pos);
                break;
            }
            case 4: 
            {
                nameOfBestScore(ptr,score,pos);
                
                break;
            }
            case 0: 
            {
                delete[] ptr;
                ptr=NULL;
                break;
            }
        }


    }while(option != 0);


    return 0;
}