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
        int month;
    public:
        Person();
        Person(string name,string dob,string tel,string unit,int month);
        Person(const Person &person);
        void setName(string name);
        void setDob(string dob);
        void setUnit(string unit);
        void setTel(string tel);
        void setMonth(int month);
        virtual void setWorkDay(int workDay);
        virtual void setSurgery(int surgery);
        virtual void setNightShift(int nightShift);
        string getDob();
        string getUnit();
        string getName();
        string getTel();
        int getMonth();
        virtual int getWorkDay();
        virtual int getSurgery();
        virtual int getNightShift();
        virtual long salary();
        friend istream& operator >> (istream& in, Person& person);
        virtual ~Person() {};
};