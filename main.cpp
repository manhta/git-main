#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "Person.cpp"
#include "Doctor.cpp"
#include "Nurse.cpp"

using namespace std;

vector<Person*> ListPerson;
fstream DataFile;

void displayMenu() {
    cout << "==================================================================== \n";
    cout << " \t\t\t  QUẢN LÍ BỆNH VIỆN \t \n";
    cout << "==================================================================== \n";
    cout << " 1.In thông tin cán bộ\n"; // xong
    cout << " 2.Thêm cán bộ\n"; // xong
    cout << " 3.Chỉnh sửa thông tin cán bộ \n";
    cout << " 4.Xoá thông tin cán bộ  \n";
    cout << " 5.Tìm kiếm cán bộ \n"; // xong
    cout << " 6.Danh sách cán bộ có lương hàng tháng lớn hơn X(vnd)  \n"; // xong
    cout << " 7.Sao lưu dữ liệu \n"; // xong
    cout << " 0.Thoát!";
}

void readDataFromFile() {
    DataFile.open("data.txt",ios::in);
    vector<string> tempStore;
    if (DataFile.is_open()) {
        while (!DataFile.eof()) {
            string tempString;
            getline(DataFile,tempString);
            stringstream ss(tempString);
            while (getline(ss,tempString,';')) {
                tempStore.push_back(tempString);
            }
            if (tempStore[3] == "Bác sĩ") {
                string tempName = tempStore[0];
                string tempDob = tempStore[1];
                string tempTel = tempStore[2];
                string tempUnit = tempStore[3];
                int tempWorkDay = stoi(tempStore[4]);
                int tempSurgery = stoi(tempStore[5]);
                Person *tempPerson = new Doctor(tempName,tempDob,tempTel,tempUnit,tempWorkDay,tempSurgery);
                ListPerson.push_back(tempPerson);
            } else if (tempStore[3] == "Y tá") {
                string tempName = tempStore[0];
                string tempDob = tempStore[1];
                string tempTel = tempStore[2];
                string tempUnit = tempStore[3];
                int tempWorkDay = stoi(tempStore[4]);
                int tempNightShift = stoi(tempStore[5]);
                Person *tempPerson = new Nurse(tempName,tempDob,tempTel,tempUnit,tempWorkDay,tempNightShift);
                ListPerson.push_back(tempPerson);
            }
            tempStore.erase(tempStore.begin(),tempStore.begin()+tempStore.size());
        }
    } else {
        cout << "Lỗi không mở được file";
        DataFile.close();
    }
    DataFile.close();
}

void printListPerson() {
    if (ListPerson.size()==0) {
        cout << "Danh sách cán bộ rỗng\n";
    } else {
        cout <<"DANH SÁCH CÁN BỘ\n";
        for (int i=0;i<ListPerson.size();i++) {
            cout <<"STT: " << i+1 << endl;
            ListPerson[i]->display();
        }
    }
}

void addPerson() { // Hàm thêm cán bộ
    Person tempPerson;
    cin >> tempPerson;
    if (tempPerson.getUnit()=="Bác sĩ") {
        int tempWorkDayDr,tempSur;
        cout << "Nhập số ngày làm việc: ";
        cin >> tempWorkDayDr;
        cout << "Nhập số ca phẫu thuật thực hiện: ";
        cin >> tempSur; cin.ignore();
        Person *p = new Doctor(tempPerson.getName(),tempPerson.getDob(),tempPerson.getTel(),tempPerson.getUnit(),tempWorkDayDr,tempSur);
        ListPerson.push_back(p);
    } else if (tempPerson.getUnit()=="Y tá") {
        int tempWorkDayNs,tempNightShift;
        cout << "Nhập số ngày làm việc: ";
        cin >> tempWorkDayNs;
        cout << "Nhập số ca trực đêm: ";
        cin >> tempNightShift; cin.ignore();
        Person *p = new Nurse(tempPerson.getName(),tempPerson.getDob(),tempPerson.getTel(),tempPerson.getUnit(),tempWorkDayNs,tempNightShift);
        ListPerson.push_back(p);
    }
    cout << "Đã thêm cán bộ vào danh sách\n";
}

void modifyPersonInformation() {
    printListPerson();
    cout << "Chọn STT cán bộ muốn sửa thông tin: ";
    int number_1; cin >> number_1;
    cout << "(1)Sửa họ tên\n";
    cout << "(2)Sửa ngày tháng năm sinh\n";
    cout << "(3)Sửa số điên thoại\n";
    cout << "(4)Sửa số ngày làm việc\n";
    cout << "(5)Sửa số ca phẫu thuât/số ngày trực đêm\n";
    cout << "Chọn thông tin muốn chỉnh sửa: ";
    int number_2; cin >> number_2;
    switch (number_2) {
        case 1: {
            cout << "Nhập tên mới: ";
            string newName; cin.ignore(); getline(cin,newName);
            ListPerson[number_1-1]->setName(newName);
            break;
        }
        case 2: {
            cout << "Nhập ngày tháng năm sinh mới: ";
            string newDob; cin.ignore(); getline(cin,newDob);
            ListPerson[number_1-1]->setDob(newDob);
            break;
        }
        case 3: {
            cout << "Nhập số điện thoại mới: ";
            string newTel; cin.ignore(); getline(cin,newTel);
            ListPerson[number_1]->setTel(newTel);
            break;
        }
        case 4: {
            cout << "Nhập số ngày làm việc mới: ";
            int newWorkDay; cin >> newWorkDay;
            ListPerson[number_1-1]->setWorkDay(newWorkDay);
            break;
        }
        case 5: {
            cout << "Nhập số ca phẫu thuật/số ca trực đêm mới: ";
            if (ListPerson[number_1-1]->getUnit() == "Bác sĩ") {
                int newSurgery; cin >> newSurgery;
                ListPerson[number_1-1]->setSurgery(newSurgery);
            } else if (ListPerson[number_1-1]->getUnit() == "Y tá") {
                int newNightShift; cin >> newNightShift;
                ListPerson[number_1-1]->setNightShift(newNightShift);
            }
            break;
        }
    }
}

void deletePerson() {
    printListPerson();
    cout << "Chọn STT cán bộ muốn xoá: ";
    int number_1; cin >> number_1;
    if (number_1==ListPerson.size()) {
        ListPerson.pop_back();
    } else {
        ListPerson.erase(ListPerson.begin()+number_1-1,ListPerson.begin()+number_1);
    }
}

void findPersonByName() {
    vector<Person*> result;
    string inputName;
    cout << "Nhập tên(kí tự có trong tên) cán bộ: ";
    getline(cin,inputName);
    for (int i=0;i<ListPerson.size();i++) {
        string tempInputName,tempPersonName;
        for (int j=0;j<inputName.size();j++) {
            tempInputName += toupper(inputName[j]);
        }
        for (int j=0;j<ListPerson[i]->getName().size();j++) {
            tempPersonName += toupper((ListPerson[i]->getName())[j]);
        }
        if (tempPersonName.find(tempInputName,0) != string::npos) {
            result.push_back(ListPerson[i]);
        }
    }
    for (int i=0;i<result.size();i++) {
        result[i]->display();
    }
}

void findPersonByDob() {
    cout << "Nhập ngày sinh: ";
    string tempDob; cin >> tempDob;
    vector<Person*> result;
    for (int i=0;i<ListPerson.size();i++) {
        if (ListPerson[i]->getDob().find(tempDob) != string::npos) {
            result.push_back(ListPerson[i]);
        }
    } 
    if (result.size()==0) {
        cout << "Không có cán bộ nào thoả mãn.";
    } else {
        for (int i=0;i<result.size();i++) {
            result[i]->display();
        }
    }
}

void findPersonHaveSalaryHigherThanX() {
    long long X;
    cout << "Nhập số tiền bạn muốn so sánh(vnđ): ";cin >> X;
    vector<Person*> result;
    for (int i=0;i<ListPerson.size();i++) {
        if (ListPerson[i]->salary()>X) {
            result.push_back(ListPerson[i]);
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
    for (int i=0;i<ListPerson.size();i++) {
        if (ListPerson[i]->getUnit()=="Bác sĩ") {
            DataFile << ListPerson[i]->getName() << ";" << ListPerson[i]->getDob() << ";" << ListPerson[i]->getTel() << ";" << ListPerson[i]->getUnit() << ";" << ListPerson[i]->getWorkDay() << ";" << ListPerson[i]->getSurgery() << ";" << ListPerson[i]->salary() << endl;
        } else if (ListPerson[i]->getUnit()=="Y tá") {
            DataFile << ListPerson[i]->getName() << ";" << ListPerson[i]->getDob() << ";" << ListPerson[i]->getTel() << ";" << ListPerson[i]->getUnit() << ";" << ListPerson[i]->getWorkDay() << ";" << ListPerson[i]->getNightShift() << ";" << ListPerson[i]->salary() << endl;
        } else {
            DataFile << ListPerson[i]->getName() << ";" << ListPerson[i]->getDob() << ";" << ListPerson[i]->getTel() << ";" << ListPerson[i]->getUnit() << endl;
        }
    }
    cout << "Sao lưu dữ liệu thành công!";
    DataFile.close();
}  

int main() {
    readDataFromFile();
    deletePerson();
    printListPerson();
}