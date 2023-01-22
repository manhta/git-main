#include "Person.hpp"

using namespace std;

const int salaryNurse = 200000; // tien luong 1 ngay cua y ta
const int salaryNightShift = 500000; // tien luong 1 dem truc
class Nurse : public Person {
    private:
        int workDay; // so ngay lam viec cua y ta
        int nightShift; // so ngay truc dem 
    public:
        Nurse() {}
        Nurse(string name,string dob, string tel, string unit, int month, int workDay, int nightShift) : Person(name,dob,tel,unit,month) {
            this->workDay = workDay;
            this->nightShift = nightShift;
        }
        void setWorkDay(int workday) {
            this->workDay = workday;
        }
        void setNightShift(int nightShift) {
            this->nightShift = nightShift;
        }
        int getWorkDay() {
            return this->workDay;
        }
        int getNightShift() {
            return this->nightShift;
        }
        long salary() {
            return workDay*salaryNurse+nightShift*salaryNightShift;
        }
        ~Nurse() {};
};
