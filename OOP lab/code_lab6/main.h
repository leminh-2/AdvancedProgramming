#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
//forward declarations
class UniSem;
class UniStd;
class CollegeStd;
class CollegeSem;
class Student;

class Student{
    //protected: subclass can access below methods and parameters, but another class cannot do that
    protected: //public functions in class UniStd can access below parameters
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
        virtual void setStd(){
            cout<<"enter the name of student: ";
            cin>>this->name; cin.ignore();
            cout<<"enter the birth of student: ";
            cin>>this->birth; cin.ignore();
            cout<<"enter the school name of student: ";
            cin>>this->school; cin.ignore();
            cout<<"enter the course name of student: ";
            cin>>this->course; cin.ignore();
        }
        virtual void getname(){
            cout<<"this is function getname from parent class Student"<<endl;
        }
        virtual void printStd(){
            cout<<"this is function printStd from parent class Student"<<endl;
        }
        virtual void DoAssignment(){
            cout<<"this is function DoAssignment from parent class Student"<<endl;
        }
        virtual void TakeTest(){
            cout<<"this is function TakeTest from parent class Student"<<endl;
        }
        virtual void TakeExam(){
            cout<<"this is function TakeExam from parent class Student"<<endl;
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
            cin>>this->SCass1; cin.ignore();
            cout<<"enter the score of assignment 2: ";
            cin>>this->SCass2; cin.ignore();
            cout<<"enter the score of assignment 3: ";
            cin>>this->SCass3;cin.ignore();
            cout<<"enter the score of test 1: ";
            cin>>this->SCtest1;cin.ignore();
            cout<<"enter the score of test 2: ";
            cin>>this->SCtest2;cin.ignore();
            cout<<"enter the score of exam: ";
            cin>>this->SCexam;cin.ignore();
        }
        void printUniSem(){
            cout<<"score of assignment 1: "<<this->SCass1<<endl;
            cout<<"score of assignment 2: "<<this->SCass2<<endl;
            cout<<"score of assignment 3: "<<this->SCass3<<endl;
            cout<<"score of test 1: "<<this->SCtest1<<endl;
            cout<<"score of test 2: "<<this->SCtest2<<endl;
            cout<<"score of exam: "<<this->SCexam<<endl;
        }
        void setRanAss(){
            const long max_rand = 100000;
            double lower_bound = 0;
            double upper_bound = 10;
            srand(time(NULL));
            SCass1 = lower_bound + (upper_bound - lower_bound) * (rand() % max_rand) / max_rand;
            SCass2 = lower_bound + (upper_bound - lower_bound) * (rand() % max_rand) / max_rand;
            SCass3 = lower_bound + (upper_bound - lower_bound) * (rand() % max_rand) / max_rand;
        }
        void setRanTest(){
            const long max_rand = 100000;
            double lower_bound = 0;
            double upper_bound = 10;
            srand(time(NULL));
            SCtest1 = lower_bound + (upper_bound - lower_bound) * (rand() % max_rand) / max_rand;
            SCtest2 = lower_bound + (upper_bound - lower_bound) * (rand() % max_rand) / max_rand;
        }
        void setRanExam(){
            const long max_rand = 100000;
            double lower_bound = 0;
            double upper_bound = 10;
            srand(time(NULL));
            SCexam = lower_bound + (upper_bound - lower_bound) * (rand() % max_rand) / max_rand;
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
            cin>>this->SCass;cin.ignore();
            cout<<"enter the score of test: ";
            cin>>this->SCtest;cin.ignore();
            cout<<"enter the score of exam: ";
            cin>>this->SCexam;cin.ignore();
        }
        void printCoSem(){
            cout<<"score of assignment: "<<this->SCass<<endl;
            cout<<"score of test: "<<this->SCtest<<endl;
            cout<<"score of exam: "<<this->SCexam<<endl;
        }
        void setRanAss(){
            const long max_rand = 100000;
            double lower_bound = 0;
            double upper_bound = 10;
            srand(time(NULL));
            SCass = lower_bound + (upper_bound - lower_bound) * (rand() % max_rand) / max_rand;
        }
        void setRanTest(){
            const long max_rand = 100000;
            double lower_bound = 0;
            double upper_bound = 10;
            srand(time(NULL));
            SCtest = lower_bound + (upper_bound - lower_bound) * (rand() % max_rand) / max_rand;
        }
        void setRanExam(){
            const long max_rand = 100000;
            double lower_bound = 0;
            double upper_bound = 10;
            srand(time(NULL));
            SCexam = lower_bound + (upper_bound - lower_bound) * (rand() % max_rand) / max_rand;
        }
        ~CollegeSem(){};
};

class UniStd : public Student{
    private:
        UniSem* sem;
    public:
        UniStd(){}
        void setStd(){
            //set general information
            cout<<"enter the name of student: ";
            cin>>this->name;cin.ignore();
            cout<<"enter the birth of student: ";
            cin>>this->birth;cin.ignore();
            cout<<"enter the school name of student: ";
            cin>>this->school;cin.ignore();
            cout<<"enter the course name of student: ";
            cin>>this->course;cin.ignore();

            //set the specific information
            this->sem = new UniSem[8];
            for(int i = 0; i < 8; i++){
                cout<<"Set semester "<<i+1<<endl;
                this->sem[i].setUniSem();
            }
        }
        void getname(){
            cout<<"UniStudent: "<<name;
        }
        void DoAssignment(){
            for(int i = 0; i < 8; i++){
                this->sem[i].setRanAss();
            }
        }
        void TakeTest(){
            for(int i = 0; i < 8; i++){
                this->sem[i].setRanTest();
            }
        }
        void TakeExam(){
            for(int i = 0; i < 8; i++){
                this->sem[i].setRanExam();
            }
        }
        void printStd(){
            cout<<"student "<<this->name<<" born in "<<this->birth<<" from school "<<this->school<<" is studying "<<this->course<<endl;
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
        void setStd(){
            //set general information
            cout<<"enter the name of student: ";
            cin>>this->name;cin.ignore();
            cout<<"enter the birth of student: ";
            cin>>this->birth;cin.ignore();
            cout<<"enter the school name of student: ";
            cin>>this->school;cin.ignore();
            cout<<"enter the course name of student: ";
            cin>>this->course;cin.ignore();

            //set the specific information
            this->sem = new CollegeSem[4];
            for(int i = 0; i < 4; i++){
                cout<<"Set semester "<<i+1<<endl;
                this->sem[i].setCoSem();
            }
        }
        void getname(){
            cout<<"CollegeStudent: "<<name;
        }
        void DoAssignment(){
            for(int i = 0; i < 4; i++){
                this->sem[i].setRanAss();
            }
        }
        void TakeTest(){
            for(int i = 0; i < 4; i++){
                this->sem[i].setRanTest();
            }
        }
        void TakeExam(){
            for(int i = 0; i < 4; i++){
                this->sem[i].setRanExam();
            }
        }
        void printStd(){
            cout<<"student "<<this->name<<" born in "<<this->birth<<" from school "<<this->school<<" is studying "<<this->course<<endl;
            for(int i = 0; i < 4; i++){
                cout<<"semester "<<i+1<<endl;
                this->sem[i].printCoSem();
            }
        }
        ~CollegeStd(){};
};




