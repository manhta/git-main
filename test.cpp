#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Person {
    private:
        string name;
        string dob;
        string tel;
        string unit;
        int day;
        int S;
    public:
        Person() {}
        void setName(string name) {
            this->name = name;
        } 
        void setDob(string dob) {
            this->dob = dob;
        }
        void setTel(string tel) {
            this->tel = tel;
        }
        void setUnit(string unit) {
            this->unit = unit;
        }
        void setDay(int day) {
            this->day = day;
        }
        void setS(int S) {
            this->S = S;
        }
        void setInfor(vector<string> input) {
            setName(input[0]);
            setDob(input[1]);
            setTel(input[2]);
            setUnit(input[3]);
            setDay(stoi(input[4]));
            setS(stoi(input[5]));
        }
        void display() {
            cout <<"Name: " << name << endl;
            cout << "Dob: " << dob <<endl;
            cout << "Tel: " << tel << endl;
            cout << "Day " << day << endl;
            cout << "S: " << S << endl;
        }
};
int main() {
    fstream MyFile;
    MyFile.open("data.txt",ios::in);
    string str;
    Person p;
    vector<string> splitInfor;

    while (!MyFile.eof()) {
        getline(MyFile,str);
        stringstream ss(str);
        
    }
    MyFile.close();
}