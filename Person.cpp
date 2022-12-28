#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Person {
    private:
        string name; 
        string dob; // date of birth
        string tel; // phone number
        string unit; // work unit
    public:
        Person() {}
        Person(string name,string dob,string tel,string unit) {
            this->name = name;
            this->dob = dob;
            this->tel = tel;
            this->unit = unit;
        }
        virtual long salary() {return 0;}

        void setPerson(Person a) {
            this->name = a.getName();
            this->dob = a.getDob();
            this->tel = a.getTel();
            this->unit = a.getUnit();
        }
        string getDob() {
            return this->dob;
        }
        string getUnit() {
            return this->unit;
        }
        string getName() {
            return this->name;
        }
        string getTel() {
            return this->tel;
        }
        virtual void display() {
            cout << "Tên: " << name << endl;
            cout << "Ngày sinh: " << dob << endl;
            cout << "Số điện thoại: " << tel << endl;
            cout << "Đơn vị: " << unit << endl;
        }
        friend istream& operator >> (istream& in, Person& a) {
            cout << "Nhập tên của cán bộ: ";getline(in,a.name);
            cout << "Nhập ngày tháng năm sinh của cán bộ(theo định dạng dd/mm/yyyy): ";in >> a.dob;
            cout << "Nhập số điện thoại của cán bộ: ";in.ignore();in >> a.tel;
            cout << "Nhập đơn vị: ";in.ignore();getline(in,a.unit);
            return in;
        }
};