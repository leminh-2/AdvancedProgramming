#include "main.h"

int main(){
    system("cls");
    int option = 0;
    string* ptr;
    int pos = -1; //default value = -1  
    int capacity = 0;
    do{
        //system("cls");
        cout<<"--------------------------------"<<endl;
        cout<<"list of functionality"<<endl;
        cout<<"1. Create new C++ array data structure to store the list of all students' names"<<endl;
        cout<<"2. allows users to add a new student to the list of all students."<<endl;
        cout<<"3. display the list of all students"<<endl;
        cout<<"4. remove a student from the list of all students"<<endl;
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
                    createList(ptr, capacity);
                }
                break;
            }
            case 2: 
            {
                string temp;
                cout<<"enter new student name:";
                cin>>temp;
                add(ptr, temp, capacity, pos);
                break;
            }
            case 3: 
            {
                printName(ptr, pos);
                break;
            }
            case 4: 
            {
                cout<<"enter student name that you want to remove:";
                string tempStr; cin>>tempStr;
                rem(ptr, tempStr, pos);
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