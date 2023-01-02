#include "Person.hpp"

using namespace std;

const int salaryNs = 200000; // tien luong 1 ngay cua y ta
const int salaryShift = 500000; // tien luong 1 dem truc
class Nurse : public Person {
    private:
        int workDayNs; // so ngay lam viec cua y ta
        int nightShift; // so ngay truc dem 
    public:
        Nurse() {}
        Nurse(string name,string dob, string tel, string unit, int workDayNs, int nightShift) : Person(name,dob,tel,unit) {
            this->workDayNs = workDayNs;
            this->nightShift = nightShift;
        }
        int getWorkDay() {
            return this->workDayNs;
        }
        int getNightShift() {
            return this->nightShift;
        }
        long salary() {
            return workDayNs*salaryNs+nightShift*salaryShift;
        }
        void display() {
            Person::display();
            cout << "Số ngày làm việc: " << workDayNs << endl;
            cout << "Số đêm trực: " << nightShift << endl;
            cout << "Tiền lương: " << salary() << endl;
        }
        ~Nurse() {};
};
