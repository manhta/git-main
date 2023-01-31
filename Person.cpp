// Tạ Đức Mạnh 20213995
#include "Person.hpp"

Person::Person() {}
Person::Person(string name,string dob,string tel,string unit,int month) {
    this->name = name;
    this->dob = dob;
    this->tel = tel;
    this->unit = unit;
    this->month = month;
}
Person::Person(const Person &person) {
    this->name = person.name;
    this->dob = person.dob;
    this->tel = person.tel;
    this->unit = person.unit;
    this->month = person.month;
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
void Person::setMonth(int month) {
    this->month = month;
}
void Person::setWorkDay(int workDay) {}
void Person::setSurgery(int surgery) {}
void Person::setNightShift(int nightShift) {}
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
int Person::getMonth() {
    return this->month;
}
int Person::getWorkDay() {return 0;}
int Person::getSurgery() {return 0;}
int Person::getNightShift() {return 0;}
long Person::salary() {return 0;}
istream& operator >> (istream& in, Person& person) {
    cout << "Nhap ten can bo: ";getline(in,person.name);
    cout << "Nhap ngay thang nam sinh can bo(theo dinh dang dd/mm/yyyy): ";in >> person.dob;
    cout << "Nhap so dien thoai can bo: ";in.ignore();in >> person.tel;
    cout << "Nhap don vi: ";in.ignore();getline(in,person.unit);
    cout << "Thang can bo duoc them vao: "; cin >> person.month;
    return in;
}