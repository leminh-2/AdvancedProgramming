#include <iostream>
#include <cstdlib>
using namespace std;

class StudentClass{
    private:
        string name;
        double score;
    public:
        StudentClass(string name="", double score=0){
            this->name = name;
            this->score = score;
        }
        void setName(string name){ this->name = name; }
        void setScore(double score) { this->score = score; }
        double getScore() { return this->score; }
        string getName() { return this->name; }
        void printStd(){
            cout<<"student "<<this->name<<" score "<<this->score<<endl;
        }
        ~StudentClass(){}
        void nameOfBestScore(int size){
            double bestScore = 0;
            StudentClass* tmp = this;
            for(int i=0; i<size; i++){
                if(tmp[i].getScore() > bestScore) bestScore = tmp[i].getScore();
            }
            cout<<"Best Score: "<<bestScore<<" from student(s):"<<endl;
            tmp = this;
            for(int i=0; i<size; i++){
                if(bestScore == tmp[i].getScore()) cout<<tmp[i].getName()<<endl;
            }
        }
        int find(string name, int size){
            StudentClass* tmp = this;
            int find = -1;
            for(int i=0; i<size; i++){
                if(tmp[i].getName() == name) find = i;
            }
            return find;
        }
};
class University : public StudentClass{
    private:
        string UniName;
        StudentClass* std;
        int pos;
        int capacity;
    public: 
    University(string name="",StudentClass* std=nullptr, int pos=-1, int capacity=0){
        this->UniName = name;
        this->std = std;
        this->pos = pos;
        this->capacity = capacity;
    }
    void setUniName(string name){
        this->UniName = name;
    }
    void setCapacity(int cap){
        this->capacity = cap;
        if(std == nullptr) std = new StudentClass[cap];
    }
    string getUniName(){
        return UniName;
    }
    ~University(){}
    /*static: repair the error
    a nonstatic member reference must be relative to a specific object
    */
    static int chooseUni(University* u, int pos){
        if(pos == -1){
            cout<<"list of University is empty"<<endl;
            return -1;
        }
        cout<<"list of universities: "<<endl;
        for(int i=0; i<=pos; i++){
            cout<<i<<". "<<u[i].getUniName()<<endl;
        }
        int opt;
        cout<<"press number to choose specific university: ";
        cin>>opt;
        if(opt < 0 || opt > pos){
            cout<<"invalid option";
            return -1;
        }
        return opt;
    }
    void task1(){
        if(std == nullptr){
            cout<<"The list hasn't been initialized, enter the number of students: ";
            cin>>capacity;
            
            if(capacity <= 0){ throw out_of_range("input of size is invalid -> failed.");}
            else { 
                std = new StudentClass[capacity];
            }
        }
        if(pos == capacity -1){ cout<<"list is full"<<endl; return;}
        //else
        cout<<"enter the name of student: ";
        string tmpStr; cin>>tmpStr;
        cout<<"enter the score of student: ";
        double tmpNum; cin>>tmpNum;
        
        std[++pos].setName(tmpStr);
        std[pos].setScore(tmpNum);
    }
    void task2(){
        if(pos == -1) cout<<"list is empty"<<endl;
        for(int i=0; i<=pos; i++){
            std[i].printStd();
        }
    }
    void task3(){
        if(pos == -1) {cout<<"list is empty"<<endl; return;}
        std[0].nameOfBestScore(pos+1);
    }
    void task4(){
        if(pos == -1) {cout<<"list is empty"<<endl; return;}
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
    }

};


