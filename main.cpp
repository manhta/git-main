#include <iostream>
#include <iomanip>
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

void DisplayMenu() {
    cout << "====================================================================\n";
    cout << "=                      QUAN LY BENH VIEN                           =\n";
    cout << "==================================================================== \n";
    cout << "=              1.In thong tin can bo                               =\n";                              
    cout << "=              2.Them can bo                                       =\n";
    cout << "=              3.Chinh sua thong tin can bo                        =\n";
    cout << "=              4.Xoa thong tin can bo                              =\n";
    cout << "=              5.Tim kiem can bo                                   =\n";
    cout << "=              6.Danh sach can bo co luong lon hon X(vnd)          =\n";
    cout << "=              7.Sao luu du lieu                                   =\n";
    cout << "=              0.Thoat!                                            =\n";
    cout << "====================================================================";
    cout << endl;
}

string getLastName(string namePerson) {
    string lastName,token;
    stringstream ss(namePerson);
    while (ss >> token) {
        lastName = token;
    }
    return lastName;
}

void sortListPerson() {
    for (int i=0;i<ListPerson.size()-1;i++) {
        for (int j=i+1;j<ListPerson.size();j++) {
            if (getLastName(ListPerson[i]->getName())>getLastName(ListPerson[j]->getName())) {
                Person *tempPerson = ListPerson[i];
                ListPerson[i] = ListPerson[j];
                ListPerson[j] = tempPerson;
            }
        }
    }
}

void ReadDataFromFile() {
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
            if (tempStore[3] == "Bac si") {
                string tempName = tempStore[0];
                string tempDob = tempStore[1];
                string tempTel = tempStore[2];
                string tempUnit = tempStore[3];
                int tempWorkDay = stoi(tempStore[4]);
                int tempSurgery = stoi(tempStore[5]);
                Person *tempPerson = new Doctor(tempName,tempDob,tempTel,tempUnit,tempWorkDay,tempSurgery);
                ListPerson.push_back(tempPerson);
            } else if (tempStore[3] == "Y ta") {
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
        cout << "Loi khong mo duoc file";
        DataFile.close();
    }
    DataFile.close();
    sortListPerson();
}

void printTableHeading() {
    for (int i=1;i<=4;i++)  cout <<"-"; cout << "+";
    for (int i=1;i<=21;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=12;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=15;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=8;i++)  cout <<"-"; cout << "+";
    for (int i=1;i<=18;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=18;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=16;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=16;i++) cout <<"-"; cout << "+";
    cout << endl;
    cout << left << setw(4) << "STT" << setw(2) << "|";
    cout << left << setw(20) << "Ho va ten" << setw(2) << "|";
    cout << left << setw(10) << "Ngay sinh" << right << setw(2) << "|";
    cout << left << setw(1) << " " << setw(13) << "So dien thoai" << right << setw(2) << "|";
    cout << left << setw(8) << " Don vi" << setw(2) << "|";
    cout << left << setw(17) << "So ngay lam viec" << setw(2) << "|";
    cout << left << setw(17) << "So ca phau thuat" << setw(2) << "|";
    cout << left << setw(15) << "So ca truc dem" << setw(2) << "|";
    cout << left << setw(14) << "Tien luong(vnd)" << setw(2) << "|";
    cout << endl; 
    for (int i=1;i<=4;i++)  cout <<"-"; cout << "+";
    for (int i=1;i<=21;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=12;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=15;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=8;i++)  cout <<"-"; cout << "+";
    for (int i=1;i<=18;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=18;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=16;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=16;i++) cout <<"-"; cout << "+";
    cout << endl;
}

void printListPerson(vector<Person*> arrayPerson) {
    cout << "Danh sach can bo" << endl;
    printTableHeading();
    for (int i=0;i<arrayPerson.size();i++) {
        cout << left << setw(4) << i+1 << setw(2) << "|";
        cout << left << setw(20) << arrayPerson[i]->getName() << setw(2) << "|";
        cout << left << setw(10) << arrayPerson[i]->getDob() << right << setw(2) << "|";
        cout << left << setw(1) << " " << setw(13) << arrayPerson[i]->getTel() << right << setw(2) << "|";
        cout << " ";
        if (arrayPerson[i]->getUnit()== "Bac si") {
            cout << left << setw(7) << arrayPerson[i]->getUnit() << setw(2) << "|";
            cout << left << setw(8) << " " << setw(9) << arrayPerson[i]->getWorkDay() << setw(2) << "|";
            cout << left << setw(8) << " " << setw(9) << arrayPerson[i]->getSurgery() << setw(2) << "|";
            cout << left << setw(7) << " " << setw(8) << "X" << setw(2) << "|";
        } else if (arrayPerson[i]->getUnit() == "Y ta") {
            cout << left << setw(7) << arrayPerson[i]->getUnit() << setw(2) << "|";
            cout << left << setw(8) << " " << setw(9) << arrayPerson[i]->getWorkDay() << setw(2) << "|";
            cout << left << setw(8) << " " << setw(9) << "X" << setw(2) << "|";
            cout << left << setw(7) << " " << setw(8) << arrayPerson[i]->getNightShift() << setw(2) << "|";
        }
        cout << left << setw(8) << arrayPerson[i]->salary() << setw(7) << " " << setw(2) << "|";
        cout << endl;
    }
    for (int i=1;i<=4;i++)  cout <<"-"; cout << "+";
    for (int i=1;i<=21;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=12;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=15;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=8;i++)  cout <<"-"; cout << "+";
    for (int i=1;i<=18;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=18;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=16;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=16;i++) cout <<"-"; cout << "+";
    cout << endl;
}

void addPerson() { // Hàm thêm cán bộ
    Person tempPerson;
    cin >> tempPerson;
    if (tempPerson.getUnit()=="Bac si") {
        int tempWorkDayDr,tempSurgery;
        cout << "Nhap so ngay lam viec: ";
        cin >> tempWorkDayDr;
        cout << "Nhap so ca phau thuat thuc hien: ";
        cin >> tempSurgery; cin.ignore();
        Person *p = new Doctor(tempPerson.getName(),tempPerson.getDob(),tempPerson.getTel(),tempPerson.getUnit(),tempWorkDayDr,tempSurgery);
        ListPerson.push_back(p);
    } else if (tempPerson.getUnit()=="Y ta") {
        int tempWorkDayNs,tempNightShift;
        cout << "Nhap so ngay lam viec: ";
        cin >> tempWorkDayNs;
        cout << "Nhap so ca truc dem: ";
        cin >> tempNightShift; cin.ignore();
        Person *p = new Nurse(tempPerson.getName(),tempPerson.getDob(),tempPerson.getTel(),tempPerson.getUnit(),tempWorkDayNs,tempNightShift);
        ListPerson.push_back(p);
    }
    system("clear");
    cout << "Da them can bo vao danh sach!\n";
}

void modifyPersonInformation() {
    printListPerson(ListPerson);
    cout << "Chon STT can bo muon sua thong tin: ";
    int number_1; cin >> number_1;
    system("clear");
    cout << "(1)Sua ho ten\n";
    cout << "(2)Sua ngay thang nam sinh\n";
    cout << "(3)Sua so dien thoai\n";
    cout << "(4)Sua so ngay lam viec\n";
    cout << "(5)Sua so ca phau thuat/so ca truc dem\n";
    cout << "Chon thong tin muon chinh sua: ";
    int number_2; cin >> number_2;
    switch (number_2) {
        case 1: {
            system("clear");
            printListPerson(ListPerson);
            cout << "Nhap ten moi: ";
            string newName; cin.ignore(); getline(cin,newName);
            ListPerson[number_1-1]->setName(newName);
            break;
        }
        case 2: {
            system("clear");
            printListPerson(ListPerson);
            cout << "Nhap ngay thang nam sinh moi: ";
            string newDob; cin.ignore(); getline(cin,newDob);
            ListPerson[number_1-1]->setDob(newDob);
            break;
        }
        case 3: {
            system("clear");
            printListPerson(ListPerson);
            cout << "Nhap so dien thoai moi: ";
            string newTel; cin.ignore(); getline(cin,newTel);
            ListPerson[number_1]->setTel(newTel);
            break;
        }
        case 4: {
            system("clear");
            printListPerson(ListPerson);
            cout << "Nhap so ngay lam viec moi: ";
            int newWorkDay; cin >> newWorkDay;
            ListPerson[number_1-1]->setWorkDay(newWorkDay);
            break;
        }
        case 5: {
            system("clear");
            printListPerson(ListPerson);
            cout << "Nhap so ca phau thuat/so ca truc dem moi: ";
            if (ListPerson[number_1-1]->getUnit() == "Bac si") {
                int newSurgery; cin >> newSurgery;
                ListPerson[number_1-1]->setSurgery(newSurgery);
            } else if (ListPerson[number_1-1]->getUnit() == "Y ta") {
                int newNightShift; cin >> newNightShift;
                ListPerson[number_1-1]->setNightShift(newNightShift);
            }
            break;
        }
    }
    system("clear");
    cout << "Thong tin da duoc chinh sua!" << endl;
}

void deletePerson() {
    printListPerson(ListPerson);
    cout << "Chon STT can bo muon xoa: ";
    int number_1; cin >> number_1;
    if (number_1==ListPerson.size()) {
        ListPerson.pop_back();
    } else {
        ListPerson.erase(ListPerson.begin()+number_1-1,ListPerson.begin()+number_1);
    }
    system("clear");
    cout << "Can bo da duoc xoa!" << endl;
}

void findPersonByName() {
    vector<Person*> result;
    string inputName;
    cout << "Nhap ten(ki tu co trong ten) can bo: ";
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
    system("clear");
    printListPerson(result);
}

void findPersonHaveSalaryHigherThanX() {
    long long X;
    cout << "Nhap so tien muon so sanh(vnd): ";cin >> X;
    vector<Person*> result;
    for (int i=0;i<ListPerson.size();i++) {
        if (ListPerson[i]->salary()>X) {
            result.push_back(ListPerson[i]);
        }
    }
    if (result.size()==0) {
        cout << "Khong co ai co tien luon lon hon: " << X << "(vnd)"<<endl;
    } else {
        printListPerson(result);
    }
}

void BackUpData() {
    sortListPerson();
    DataFile.open("data.txt",ios::out);
    for (int i=0;i<ListPerson.size();i++) {
        if (i == ListPerson.size()-1){
            if (ListPerson[i]->getUnit()=="Bac si") {
                DataFile << ListPerson[i]->getName() << ";" << ListPerson[i]->getDob() << ";" << ListPerson[i]->getTel() << ";" << ListPerson[i]->getUnit() << ";" << ListPerson[i]->getWorkDay() << ";" << ListPerson[i]->getSurgery() << ";" << ListPerson[i]->salary();
            } else if (ListPerson[i]->getUnit()=="Y ta") {
                DataFile << ListPerson[i]->getName() << ";" << ListPerson[i]->getDob() << ";" << ListPerson[i]->getTel() << ";" << ListPerson[i]->getUnit() << ";" << ListPerson[i]->getWorkDay() << ";" << ListPerson[i]->getNightShift() << ";" << ListPerson[i]->salary();
            }
        } else {
            if (ListPerson[i]->getUnit()=="Bac si") {
                DataFile << ListPerson[i]->getName() << ";" << ListPerson[i]->getDob() << ";" << ListPerson[i]->getTel() << ";" << ListPerson[i]->getUnit() << ";" << ListPerson[i]->getWorkDay() << ";" << ListPerson[i]->getSurgery() << ";" << ListPerson[i]->salary() << endl;
            } else if (ListPerson[i]->getUnit()=="Y ta") {
                DataFile << ListPerson[i]->getName() << ";" << ListPerson[i]->getDob() << ";" << ListPerson[i]->getTel() << ";" << ListPerson[i]->getUnit() << ";" << ListPerson[i]->getWorkDay() << ";" << ListPerson[i]->getNightShift() << ";" << ListPerson[i]->salary() << endl;
            }
        }
    }
    cout << "Sao luu du lieu thanh cong!" << endl;
    DataFile.close();
}  

int main() {
    ReadDataFromFile();
    DisplayMenu();
    cout << "Nhap lenh: "; int choice; cin >> choice;
    while (choice != 0) {
        system("clear");
        switch (choice) {
            case 1: {
                printListPerson(ListPerson);
                cin.ignore();
                cout << "Nhap phim bat ky de thoat: ";
                cin.get();
                break;
            }
            case 2: {
                cin.ignore();
                addPerson();
                sortListPerson();
                cout << "Nhap phim bat ky de thoat: ";
                cin.get();
                break;
            }
            case 3: {
                modifyPersonInformation();
                cin.ignore();
                cout << "Nhap phim bat ky de thoat: ";
                cin.get();
                break;
            }
            case 4: {
                deletePerson();
                cin.ignore();
                cout << "Nhap phim bat ky de thoat: ";
                cin.get();
                break;
            }
            case 5: {
                cin.ignore();
                findPersonByName();
                cout << "Nhap phim bat ky de thoat: ";
                cin.get();
                break;
            }
            case 6: {
                findPersonHaveSalaryHigherThanX();
                cin.ignore();
                cout << "Nhap phim bat ky de thoat: ";
                cin.get();
                break;
            }
            case 7: {
                BackUpData();
                cin.ignore();
                cout << "Nhap phim bat ky de thoat";
                cin.get();
                break;
            }
        }
        system("clear");
        DisplayMenu();
        cout << "Nhap lenh: "; cin >> choice;
    }
    system("clear");
    cout << "Ket thuc chuong trinh!";
}