#include "Person.hpp"

Person::Person() {}
Person::Person(string name,string dob,string tel,string unit) {
    this->name = name;
    this->dob = dob;
    this->tel = tel;
    this->unit = unit;
}
Person::Person(const Person &temp) {
    this->name = temp.name;
    this->dob = temp.dob;
    this->tel = temp.tel;
    this->unit = temp.unit;
}
void Person::setName(string name) {
    this->name = name;
}
void Person::setDob(string dob) {
    this->dob = dob;
}
void Person::setUnit(string unit) {
    this->unit = unit;
}
void Person::setTel(string tel) {
    this->tel = tel;
}
// void Person::setWorkDay(int workDay) {}
// void Person::setSurgery(int surgery) {}
// void Person::setNightShift(int nightShift) {}
string Person::getDob() {
    return this->dob;
}
string Person::getUnit() {
    return this->unit;
}
string Person::getName() {
    return this->name;
}
string Person::getTel() {
    return this->tel;
}
int Person::getWorkDay() {return 0;}
int Person::getSurgery() {return 0;}
int Person::getNightShift() {return 0;}
long Person::salary() {return 0;}
istream& operator >> (istream& in, Person& a) {
    cout << "Nhap ten can bo: ";getline(in,a.name);
    cout << "Nhap ngay thang nam sinh can bo(theo dinh dang dd/mm/yyyy): ";in >> a.dob;
    cout << "Nhap so dien thoai can bo: ";in.ignore();in >> a.tel;
    cout << "Nhap don vi: ";in.ignore();getline(in,a.unit);
    return in;
}