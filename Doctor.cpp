#include "Person.hpp"

using namespace std;

const int salaryDr = 500000; // tien luong 1 ngay cua bac si
const int salarySurgery = 2000000; // tien luong 1 ca phau thua
 
class Doctor : public Person {
    private:
        int workDayDr; // so ngay lam viec
        int surgery; // so ca phau thuat
    public:
        Doctor() {}
        Doctor(string name,string dob,string tel,string unit, int workDayDr, int surgery) : Person(name,dob,tel,unit) {
            this->workDayDr = workDayDr;
            this->surgery = surgery;
        }
        long salary() {
            return workDayDr*salaryDr+surgery*salarySurgery;
        }
        int workDay() {
            return this->workDayDr;
        }
        int getSurgery() {
            return this->surgery;
        }
        void display() {
            Person::display();
            cout << "Số ngày làm việc: " << workDayDr << endl;
            cout << "Số ca phẫu thuật thực hiện: " << surgery<< endl;
            cout << "Tiền lương: " << salary() << endl;
        }
        ~Doctor() {};
};