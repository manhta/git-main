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
long Person::salary() {return 0;}
void Person::display() {
    cout << "Tên: " << name << endl;
    cout << "Ngày sinh: " << dob << endl;
    cout << "Số điện thoại: " << tel << endl;
    cout << "Đơn vị: " << unit << endl;
}
istream& operator >> (istream& in, Person& a) {
    cout << "Nhập tên của cán bộ: ";getline(in,a.name);
    cout << "Nhập ngày tháng năm sinh của cán bộ(theo định dạng dd/mm/yyyy): ";in >> a.dob;
    cout << "Nhập số điện thoại của cán bộ: ";in.ignore();in >> a.tel;
    cout << "Nhập đơn vị: ";in.ignore();getline(in,a.unit);
    return in;
}