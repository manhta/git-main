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
        Person();
        Person(string name,string dob,string tel,string unit);
        Person(const Person &temp);
        string getDob();
        string getUnit();
        string getName();
        string getTel();
        virtual int getWorkDay();
        virtual int getSurgery();
        virtual int getNightShift();
        virtual long salary();
        virtual void display();
        friend istream& operator >> (istream& in, Person& a);
        virtual ~Person() {};
};