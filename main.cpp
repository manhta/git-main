#include <iostream>
#include <fstream>
#include "Person.cpp"
#include "Doctor.cpp"
#include "Nurse.cpp"

using namespace std;

vector<Person*> listPerson;
fstream DataFile;

void displayMenu() {
    cout << "==================================================================== \n";
    cout << " \t\t\t  QUẢN LÍ BỆNH VIỆN \t \n";
    cout << "==================================================================== \n";
    cout << " 1.Thêm một cán bộ\n";
    cout << " 2.Chỉnh sửa thông tin cán bộ\n";
    cout << " 3.Xoá một cán bộ \n";
    cout << " 4.Tìm kiếm cán bộ  \n";
    cout << " 5.Danh sách cán bộ có lương hàng tháng lớn hơn X(nghìn vnd) \n";
    cout << " 6.Danh sách và thông tin cán bộ của bệnh viện trong tháng \n";
    cout << " 7.In danh sách cán bộ\n";
    cout << " 8.Sao lưu dữ liệu \n";
    cout << " 0.Thoát!";
}

void addPerson() { // Hàm thêm cán bộ
    Person temp;
    cin >> temp;
    if (temp.getUnit()=="Bác sĩ") {
        int tempDayDr,tempSur;
        cout << "Nhập số ngày làm việc: ";
        cin >> tempDayDr;
        cout << "Nhập số ca phẫu thuật thực hiện: ";
        cin >> tempSur; cin.ignore();
        Person *p = new Doctor(temp.getName(),temp.getDob(),temp.getTel(),temp.getUnit(),tempDayDr,tempSur);
        listPerson.push_back(p);
    } else if (temp.getUnit()=="Y tá") {
        int tempDayNs,tempShift;
        cout << "Nhập số ngày làm việc: ";
        cin >> tempDayNs;
        cout << "Nhập số ca trực đêm: ";
        cin >> tempShift; cin.ignore();
        Person *p = new Nurse(temp.getName(),temp.getDob(),temp.getTel(),temp.getUnit(),tempDayNs,tempShift);
        listPerson.push_back(p);
    } else {
        Person *p = new Person(temp);
        listPerson.push_back(p);
    }
}

void findPerson() {
    vector<Person*> result;
    string inputName;
    cout << "Nhập tên(kí tự có trong tên) cán bộ: ";
    getline(cin,inputName);
    for (int i=0;i<listPerson.size();i++) {
        string tempInputName,tempPersonName;
        for (int j=0;j<inputName.size();j++) {
            tempInputName += toupper(inputName[j]);
        }
        for (int j=0;j<listPerson[i]->getName().size();j++) {
            tempPersonName += toupper((listPerson[i]->getName())[j]);
        }
        if (tempPersonName.find(tempInputName,0) != string::npos) {
            result.push_back(listPerson[i]);
        }
    }
    for (int i=0;i<result.size();i++) {
        result[i]->display();
    }
}
void deletePerson() {
}
void FindPersonHaveSalaryHigherThanX() {
    long long X;
    cout << "Nhập số tiền bạn muốn so sánh(vnđ): ";cin >> X;
    vector<Person*> result;
    for (int i=0;i<listPerson.size();i++) {
        if (listPerson[i]->salary()>X) {
            result.push_back(listPerson[i]);
        }
    }
    if (result.size()==0) {

        cout << "Không có ai có tiền lương lớn hơn: " << X << "(vnđ)"<<endl;
    } else {
        for (int i=0;i<result.size();i++) {
            result[i]->display();
        }
    }
}

void BackUpData() {
    DataFile.open("data.txt",ios::app);
    for (int i=0;i<listPerson.size();i++) {
        if (listPerson[i]->getUnit()=="Bác sĩ") {
            DataFile << listPerson[i]->getName() << ";" << listPerson[i]->getDob() << ";" << listPerson[i]->getTel() << ";" << listPerson[i]->getUnit() << ";" << listPerson[i]->getWorkDay() << ";" << listPerson[i]->getSurgery() << ";" << listPerson[i]->salary() << endl;
        } else if (listPerson[i]->getUnit()=="Y tá") {
            DataFile << listPerson[i]->getName() << ";" << listPerson[i]->getDob() << ";" << listPerson[i]->getTel() << ";" << listPerson[i]->getUnit() << ";" << listPerson[i]->getWorkDay() << ";" << listPerson[i]->getNightShift() << ";" << listPerson[i]->salary() << endl;
        } else {
            DataFile << listPerson[i]->getName() << ";" << listPerson[i]->getDob() << ";" << listPerson[i]->getTel() << ";" << listPerson[i]->getUnit() << endl;
        }
    }
    DataFile.close();
}  

void printlistPerson() {
    if (listPerson.size()==0) {
        cout << "Danh sách cán bộ rỗng\n";
    } else {
        cout <<"DANH SÁCH CÁN BỘ\n";
        for (int i=0;i<listPerson.size();i++) {
            cout <<"STT: " << i+1 << endl;
            listPerson[i]->display();
        }
    }
}

int main() {
    addPerson();
    findPerson();
}