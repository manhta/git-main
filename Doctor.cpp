// Tạ Đức Mạnh 20213995
#include "Person.hpp"

using namespace std;

const int salaryDoctor = 500000; // tien luong 1 ngay cua bac si
const int salarySurgery = 2000000; // tien luong 1 ca phau thua

class Doctor : public Person {
    private: 
        int workDay; // so ngay lam viec
        int surgery; // so ca phau thuat
    public:
        Doctor() {}
        Doctor(string name,string dob,string tel,string unit, int month, int workDay, int surgery) : Person(name,dob,tel,unit,month) {
            this->workDay = workDay;
            this->surgery = surgery;
        }
        void setWorkDay(int workDay) {
            this->workDay = workDay;
        }
        void setSurgery(int surgery) {
            this->surgery = surgery;
        }
        long salary() {
            return workDay*salaryDoctor+surgery*salarySurgery;
        }
        int getWorkDay() {
            return this->workDay;
        }
        int getSurgery() {
            return this->surgery;
        }
        ~Doctor() {};
};