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
