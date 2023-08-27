#include "main.h"
int N = 11; //get the random score from 0 to 10
int main(){
    system("cls");
    int option = 0;
    int capacity;
    Student** stdList = nullptr;
    int pos = -1;
    do{
        //system("cls");
        cout<<"--------------------------------"<<endl;
        cout<<"list of functionality"<<endl;
        cout<<"1. declare new list of student"<<endl;
        cout<<"2. create new student"<<endl;
        cout<<"3. call function DoAssignment"<<endl;
        cout<<"4. call function TakeTest"<<endl;
        cout<<"5. call function TakeExam"<<endl;
        cout<<"6. get info of specific student"<<endl;
        cout<<"0. End"<<endl;
        cout<<"Choose options: ";
        cin>>option; cin.ignore();

        switch(option){
            case 1: 
            {
                delete[] stdList;
                cout<<"enter the capacity of list: ";
                    cin>>capacity; cin.ignore();
                    if(capacity <= 0) throw out_of_range("input of size is invalid -> failed.");
                    else stdList = new Student*[capacity];
                    for(int i=0; i<capacity; i++){
                        stdList[i] = nullptr;
                    }
                
                break;
            }
            case 2:
            {
                //special case:
                if(pos == capacity -1 && pos != -1){ cout<<"list of student is full"<<endl; break; }
                
                //normal case:
                pos++;
                int opt;
                cout<<"1. create uni student"<<endl;
                cout<<"2. create college student"<<endl;
                cout<<"Enter the option: ";
                cin>>opt; cin.ignore();
                if(opt == 1)    stdList[pos] = new UniStd;
                else if(opt == 2) stdList[pos] = new CollegeStd;
                else throw out_of_range("invalid option");
                stdList[pos]->setStd();

                break;
            }
            case 3:
            {
                cout<<"list of students: "<<endl;
                for(int i = 0; i <= pos; i++){
                    cout<<i<<". ";
                    stdList[i]->getname();
                    cout<<endl;
                }
                cout<<"enter the number to choose student for getting info:";
                int optTMP; cin>>optTMP; cin.ignore();
                if(optTMP > pos || optTMP < 0) throw out_of_range("input of size is invalid -> failed.");
                else stdList[optTMP]->DoAssignment();
                break;
            }
            case 4:
            {
                cout<<"list of students: "<<endl;
                for(int i = 0; i <= pos; i++){
                    cout<<i<<". ";
                    stdList[i]->getname();
                    cout<<endl;
                }
                cout<<"enter the number to choose student for getting info:";
                int optTMP; cin>>optTMP; cin.ignore();
                if(optTMP > pos || optTMP < 0) throw out_of_range("input of size is invalid -> failed.");
                else stdList[optTMP]->TakeTest();
                break;
            }
            case 5:
            {
                cout<<"list of students: "<<endl;
                for(int i = 0; i <= pos; i++){
                    cout<<i<<". ";
                    stdList[i]->getname();
                    cout<<endl;
                }
                cout<<"enter the number to choose student for getting info:";
                int optTMP; cin>>optTMP; cin.ignore();
                if(optTMP > pos || optTMP < 0) throw out_of_range("input of size is invalid -> failed.");
                else stdList[optTMP]->TakeExam();
                break;
            }
            case 6:
            {
                cout<<"list of students: "<<endl;
                for(int i = 0; i <= pos; i++){
                    cout<<i<<". ";
                    stdList[i]->getname();
                    cout<<endl;
                }
                cout<<"enter the number to choose student for getting info:";
                int optTMP; cin>>optTMP; cin.ignore();
                if(optTMP > pos || optTMP < 0) throw out_of_range("input of size is invalid -> failed.");
                else stdList[optTMP]->printStd();
                break;
            }
            case 0: 
            {
                for(int i = 0; i <= capacity; i++){
                    delete stdList[i];
                    stdList[i] = nullptr;
                }
                delete[] stdList;
                stdList = nullptr;
                break;
            }
        }


    }while(option != 0);


    return 0;
}