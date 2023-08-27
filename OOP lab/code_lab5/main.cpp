#include "main.h"

int main(){
    system("cls");
    int option = 0;
    int capacityUni;
    int capacityCol;
    CollegeStd* colist = nullptr;
    UniStd* unilist = nullptr;
    int posCol = -1;
    int posUni = -1;
    do{
        //system("cls");
        cout<<"--------------------------------"<<endl;
        cout<<"list of functionality"<<endl;
        cout<<"1. declare new list of Uni student"<<endl;
        cout<<"2. create new Uni student"<<endl;
        cout<<"3. set info of specific Uni student"<<endl;
        cout<<"4. get info of specific uni student"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"5. declare new list of College student"<<endl;
        cout<<"6. create new College student"<<endl;
        cout<<"7. set info of specific College student"<<endl;
        cout<<"8. get info of specific College student"<<endl;
        cout<<"0. End"<<endl;
        cout<<"Choose options: ";
        cin>>option;

        switch(option){
            case 1: 
            {
                delete[] unilist;
                cout<<"enter the capacity of Unistudent list: ";
                    cin>>capacityUni;
                    if(capacityUni <= 0) throw out_of_range("input of size is invalid -> failed.");
                    else unilist = new UniStd[capacityUni];
                
                break;
            }
            case 2:
            {
                //special case:
                if(posUni == capacityUni -1 && posUni != -1){ cout<<"list of uni student is full"<<endl; break; }
                
                //normal case:
                posUni++;
                unilist[posUni].setUniStd();
                break;
            }
            case 3:
            {
                cout<<"list of Uni student: "<<endl;
                for(int i = 0; i <= posUni; i++){
                    cout<<i<<". "<<unilist[i].getname()<<endl;
                }
                cout<<"enter the number to choose student for setting info:";
                int opttemp; cin>>opttemp;
                if(opttemp > posUni || opttemp < 0) throw out_of_range("input of size is invalid -> failed.");
                else unilist[opttemp].setUniStd();
                break;
            }
            case 4:
            {
                cout<<"list of Uni student: "<<endl;
                for(int i = 0; i <= posUni; i++){
                    cout<<i<<". "<<unilist[i].getname()<<endl;
                }
                cout<<"enter the number to choose student for getting info:";
                int opttemp; cin>>opttemp;
                if(opttemp > posUni || opttemp < 0) throw out_of_range("input of size is invalid -> failed.");
                else unilist[opttemp].printUniStd();
                break;
            }
            case 5: 
            {
                delete[] colist;
                cout<<"enter the capacity of College student list: ";
                    cin>>capacityCol;
                    if(capacityCol <= 0) throw out_of_range("input of size is invalid -> failed.");
                    else colist = new CollegeStd[capacityCol];
                
                break;
            }
            case 6:
            {
                //special case:
                if(posCol == capacityCol -1 && posCol != -1){ cout<<"list of College student is full"<<endl; break; }
                
                //normal case:
                posCol++;
                colist[posCol].setCoStd();
                break;
            }
            case 7:
            {
                cout<<"list of College student: "<<endl;
                for(int i = 0; i <= posCol; i++){
                    cout<<i<<". "<<colist[i].getname()<<endl;
                }
                cout<<"enter the number to choose student for setting info:";
                int opttemp; cin>>opttemp;
                if(opttemp > posCol || opttemp < 0) throw out_of_range("input of size is invalid -> failed.");
                else colist[opttemp].setCoStd();
                break;
            }
            case 8:
            {
                cout<<"list of College student: "<<endl;
                for(int i = 0; i <= posCol; i++){
                    cout<<i<<". "<<colist[i].getname()<<endl;
                }
                cout<<"enter the number to choose student for getting info:";
                int opttemp; cin>>opttemp;
                if(opttemp > posCol || opttemp < 0) throw out_of_range("input of size is invalid -> failed.");
                else colist[opttemp].printCoStd();
                break;
            }
            case 0: 
            {
                delete[] colist;
                delete[] unilist;
                colist = nullptr;
                unilist = nullptr;
                break;
            }
        }


    }while(option != 0);


    return 0;
}