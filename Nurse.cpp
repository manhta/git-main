#include "Person.hpp"

using namespace std;

const int salaryNs = 200000; // tien luong 1 ngay cua y ta
const int salaryShift = 500000; // tien luong 1 dem truc
class Nurse : public Person {
    private:
        int dayNs; // so ngay lam viec cua y ta
        int shift; // so ngay truc dem 
    public:
        Nurse() {}
        Nurse(string name,string dob, string tel, string unit, int dayNs, int shift) : Person(name,dob,tel,unit) {
            this->dayNs = dayNs;
            this->shift = shift;
        }
        long salary() {
            return dayNs*salaryNs+shift*salaryShift;
        }
        void display() {
            Person::display();
            cout << "Số ngày làm việc: " << dayNs << endl;
            cout << "Số đêm trực: " << shift << endl;
            cout << "Tiền lương: " << salary() << endl;
        }
        ~Nurse() {};
};
