#include "Person.cpp"

using namespace std;

const int salaryDr = 500000; // tien luong 1 ngay cua bac si
const int salarySurgery = 2000000; // tien luong 1 ca phau thua
 
class Doctor : public Person {
    private:
        int dayDr; // so ngay lam viec
        int surgery; // so ca phau thuat
    public:
        Doctor() {}
        Doctor(string name,string dob,string tel,string unit, int dayDr, int surgery) : Person(name,dob,tel,unit) {
            this->dayDr = dayDr;
            this->surgery = surgery;
        }
        Doctor(Person a,int dayDr, int surgery) {
            Person::setPerson(a);
            this->dayDr = dayDr;
            this->surgery = surgery;
        }
        long salary() {
            return dayDr*salaryDr+surgery*salarySurgery;
        }
        void display() {
            Person::display();
            cout << "Số ngày làm việc: " << dayDr << endl;
            cout << "Số ca phẫu thuật thực hiện: " << surgery<< endl;
            cout << "Tiền lương: " << salary() << endl;
        }
};