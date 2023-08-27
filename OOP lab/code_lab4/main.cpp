#include "main.h"

int main(){
    system("cls");
    int option = 0;
    University* u = nullptr;
    int capacity = 0;
    int pos = -1;
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
                //case 1
                if(u == nullptr){
                    cout<<"The list of University hasn't been initialized, enter the capacity: ";
                    cin>>capacity;
                    if(capacity <= 0) throw out_of_range("input of size is invalid -> failed.");
                    else u = new University[capacity];
                }
                
                //case 2
                if(pos == capacity -1 && pos != -1){ cout<<"list of university is full"<<endl; break; }
                
                //case 3
                cout<<"If you want to create new university, press y. Otherwise, press n: ";
                string optUni; cin >> optUni;
                if(optUni == "y"){
                    string Uniname; int capUni;
                    cout<<"enter the name of the new university: ";
                    cin >> Uniname;
                    cout<<"enter the capacity of students: ";
                    cin >> capUni;
                    pos++;
                    u[pos].setUniName(Uniname);
                    u[pos].setCapacity(capUni);
                    u[pos].task1();
                }
                else if(optUni == "n"){
                    int opt = University::chooseUni(u,pos);
                    if(opt == -1) break;
                    u[opt].task1();
                }
                else throw out_of_range("invalid input");
                break;
            }
            case 2: 
            {
                int opt = University::chooseUni(u,pos);
                if(opt == -1) break;
                u[opt].task2();
                
                break;
            }
            case 3: 
            {
                int opt = University::chooseUni(u,pos);
                if(opt == -1) break;
                u[opt].task3();
                break;
            }
            case 4: 
            {
                int opt = University::chooseUni(u,pos);
                if(opt == -1) break;
                u[opt].task4();
                break;
            }
            case 0: 
            {
                delete[] u;
                u = nullptr;
                break;
            }
        }


    }while(option != 0);


    return 0;
}