#include <iostream>
#include <cstdlib>
using namespace std;
//forward declarations
class UniSem;
class UniStd;
class CollegeStd;
class CollegeSem;
class Student;

class Student{
    private:
        string name;
        string birth;
        string school;
        string course;

    public:
        Student(string name="", string birth="", string school="", string course=""){
            this->name = name;
            this->birth = birth;
            this->school = school;
            this->course = course;
        }
        void SetS(){
            cout<<"enter the name of student: ";
            cin>>this->name;
            cout<<"enter the birth of student: ";
            cin>>this->birth;
            cout<<"enter the school of student: ";
            cin>>this->school;
            cout<<"enter the course of student: ";
            cin>>this->course;
        }
        string getname(){
            return this->name;
        }
        void printStd(){
            cout<<"student "<<this->name<<" born in "<<this->birth<<" from school "<<this->school<<" is studying "<<this->course<<endl;
        }
        ~Student(){}
};
class UniSem{
    private:
        double SCass1;
        double SCass2;
        double SCass3;
        double SCtest1;
        double SCtest2;
        double SCexam;
    public:
        UniSem(){}
        void setUniSem(){
            cout<<"enter the score of assignment 1: ";
            cin>>this->SCass1;
            cout<<"enter the score of assignment 2: ";
            cin>>this->SCass2;
            cout<<"enter the score of assignment 3: ";
            cin>>this->SCass3;
            cout<<"enter the score of test 1: ";
            cin>>this->SCtest1;
            cout<<"enter the score of test 2: ";
            cin>>this->SCtest2;
            cout<<"enter the score of exam: ";
            cin>>this->SCexam;
        }
        void printUniSem(){
            cout<<"score of assignment 1: "<<this->SCass1<<endl;
            cout<<"score of assignment 2: "<<this->SCass2<<endl;
            cout<<"score of assignment 3: "<<this->SCass3<<endl;
            cout<<"score of test 1: "<<this->SCtest1<<endl;
            cout<<"score of test 2: "<<this->SCtest2<<endl;
            cout<<"score of exam: "<<this->SCexam<<endl;
        }
        ~UniSem(){}
};
class CollegeSem{
    private:
        double SCass;
        double SCtest;
        double SCexam;
    public:
        CollegeSem(){}
        void setCoSem(){
            cout<<"enter the score of assignment: ";
            cin>>this->SCass;
            cout<<"enter the score of test: ";
            cin>>this->SCtest;
            cout<<"enter the score of exam: ";
            cin>>this->SCexam;
        }
        void printCoSem(){
            cout<<"score of assignment: "<<this->SCass<<endl;
            cout<<"score of test: "<<this->SCtest<<endl;
            cout<<"score of exam: "<<this->SCexam<<endl;
        }
        ~CollegeSem(){};
};

class UniStd : public Student{
    private:
        UniSem* sem;
    public:
        UniStd(){}
        void setUniStd(){
            this->SetS();
            this->sem = new UniSem[8];
            for(int i = 0; i < 8; i++){
                cout<<"Set semester "<<i+1<<endl;
                this->sem[i].setUniSem();
            }
        }
        void printUniStd(){
            this->printStd();
            for(int i = 0; i < 8; i++){
                cout<<"semester "<<i+1<<endl;
                this->sem[i].printUniSem();
            }
        }
        ~UniStd(){};
};

class CollegeStd: public Student{
    private:
        CollegeSem* sem;
    public: 
        CollegeStd(){}
        void setCoStd(){
            this->SetS();
            this->sem = new CollegeSem[4];
            for(int i = 0; i < 4; i++){
                cout<<"Set semester "<<i+1<<endl;
                this->sem[i].setCoSem();
            }
        }
        void printCoStd(){
            this->printStd();
            for(int i = 0; i < 4; i++){
                cout<<"semester "<<i+1<<endl;
                this->sem[i].printCoSem();
            }
        }
        ~CollegeStd(){};
};




