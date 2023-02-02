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
    cout << "====================================================================\n";
    cout << "=              1.In thong tin can bo                               =\n";                              
    cout << "=              2.Them can bo                                       =\n";
    cout << "=              3.Chinh sua thong tin can bo                        =\n";
    cout << "=              4.Xoa thong tin can bo                              =\n";
    cout << "=              5.Tim kiem can bo                                   =\n";
    cout << "=              6.Danh sach bac si                                  =\n";
    cout << "=              7.Danh sach y ta                                    =\n";
    cout << "=              8.Danh sach can bo co tien luong lon hon X(vnd)     =\n";
    cout << "=              9.Thong ke theo thang                               =\n";
    cout << "=              10.Sao luu du lieu                                  =\n";
    cout << "=              0.Thoat!                                            =\n";
    cout << "====================================================================";
    cout << endl;
}

/**
 * Nhận vào một string là tên đầy đủ của cán bộ, trả về tên riêng của cán bộ
 * 
 *  @arg: namePerson-họ và tên đầy đủ của cán bộ
 * 
 *  @return: tên của cán bộ.
 */
string getFirstName(string namePerson) { // Tạ Đức Mạnh 20213995
    string firstName,token;
    stringstream ss(namePerson);
    while (ss >> token) {
        firstName = token;
    }
    return firstName;
}

void sortListPerson() { // Tạ Đức Mạnh 20213995
    for (int i=0;i<ListPerson.size()-1;i++) {
        for (int j=i+1;j<ListPerson.size();j++) {
            if (getFirstName(ListPerson[i]->getName())>getFirstName(ListPerson[j]->getName())) {
                Person *tempPerson = ListPerson[i];
                ListPerson[i] = ListPerson[j];
                ListPerson[j] = tempPerson;
            }
        }
    }
}

/**
 * Hàm đọc dữ liệu từ một file và lưu trữ ở vector có kiểu dữ liệu là con trỏ kiểu Person.
 */
void ReadDataFromFile() { // Tạ Đức Mạnh 20213995
/**
 * Các bước thực hiện của hàm:
 *      Bước 1: Phân tách các thông tin của một dòng, mỗi thông tin của cán bộ được lưu vào từng 
 *              phần tử của một vector tạm dùng để chứa thông tin của cán bộ
 *      Bước 2: Lưu thông tin cán bộ vào một biến con trỏ kiểu Person, trỏ vào đối tượng lớp Doctor
 *              nếu cán bộ là bác sĩ, trỏ vào đối tượng lớp Nurse nếu cán bộ là y tá
 *      Bước 3: Dùng hàm push_back() để thêm thông tin cán bộ vào vector ListPerson
 *      Bước 4: Lặp lại từ bước 1 cho đến khi đọc hết tất cả các dòng trong file
 */
    DataFile.open("data.txt",ios::in);
    vector<string> tempStore;
    if (DataFile.is_open()) {
        while (!DataFile.eof()) {
            string tempString;
            getline(DataFile,tempString);
            stringstream ss(tempString);

            // Phân tách thông tin một dòng mỗi thông tin cách nhau bởi dấu ';'
            while (getline(ss,tempString,';')) {
                tempStore.push_back(tempString);
            }
            if (tempStore[3] == "Bac si") {
                string tempName = tempStore[0];
                string tempDob = tempStore[1];
                string tempTel = tempStore[2];
                string tempUnit = tempStore[3];
                int tempMonth = stoi(tempStore[4]);
                int tempWorkDay = stoi(tempStore[5]);
                int tempSurgery = stoi(tempStore[6]);
                Person *tempPerson = new Doctor(tempName,tempDob,tempTel,tempUnit,tempMonth,tempWorkDay,tempSurgery);
                ListPerson.push_back(tempPerson);
            } else if (tempStore[3] == "Y ta") {
                string tempName = tempStore[0];
                string tempDob = tempStore[1];
                string tempTel = tempStore[2];
                string tempUnit = tempStore[3];
                int tempMonth = stoi(tempStore[4]);
                int tempWorkDay = stoi(tempStore[5]);
                int tempNightShift = stoi(tempStore[6]);
                Person *tempPerson = new Nurse(tempName,tempDob,tempTel,tempUnit,tempMonth,tempWorkDay,tempNightShift);
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

/**
 * Hàm dùng để in tiêu đề các cột của bảng.
 */
void printTableHeading() { // Nguyễn Xuân Khánh 20213970
    for (int i=1;i<=4;i++)  cout <<"-"; cout << "+";
    for (int i=1;i<=24;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=12;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=15;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=8;i++)  cout <<"-"; cout << "+";
    for (int i=1;i<=12;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=18;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=18;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=16;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=16;i++) cout <<"-"; cout << "+";
    cout << endl;
    cout << left << setw(4) << "STT" << setw(2) << "|";
    cout << left << setw(22) << "Ho va ten" << right << setw(2) << "|" << left << " ";
    cout << left << setw(10) << "Ngay sinh" << right << setw(2) << "|";
    cout << left << setw(1) << " " << setw(13) << "So dien thoai" << right << setw(2) << "|";
    cout << left << setw(8) << " Don vi" << setw(2) << "|";
    cout << left << setw(11) << "Thang nhap" << setw(2) << "|";
    cout << left << setw(17) << "So ngay lam viec" << setw(2) << "|";
    cout << left << setw(17) << "So ca phau thuat" << setw(2) << "|";
    cout << left << setw(15) << "So ca truc dem" << setw(2) << "|";
    cout << left << setw(14) << "Tien luong(vnd)" << setw(2) << "|";
    cout << endl; 
    for (int i=1;i<=4;i++)  cout <<"-"; cout << "+";
    for (int i=1;i<=24;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=12;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=15;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=8;i++)  cout <<"-"; cout << "+";
    for (int i=1;i<=12;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=18;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=18;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=16;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=16;i++) cout <<"-"; cout << "+";
    cout << endl;
} 

void printListPerson(vector<Person*> arrayPerson) { // Nguyễn Xuân Khánh 20213970
    cout << "Danh sach can bo" << endl;
    printTableHeading();
    for (int i=0;i<arrayPerson.size();i++) {
        cout << left << setw(4) << i+1 << setw(2) << "|";
        cout << left << setw(22) << arrayPerson[i]->getName() << right << setw(2) << "|" << left << " ";
        cout << left << setw(10) << arrayPerson[i]->getDob() << right << setw(2) << "|";
        cout << left << setw(1) << " " << setw(13) << arrayPerson[i]->getTel() << right << setw(2) << "|";
        cout << " ";
        if (arrayPerson[i]->getUnit()== "Bac si") {
            cout << left << setw(7) << arrayPerson[i]->getUnit() << setw(2) << "|";
            cout << left << setw(4) << " " << setw(7) << arrayPerson[i]->getMonth() << setw(2) << "|";
            cout << left << setw(8) << " " << setw(9) << arrayPerson[i]->getWorkDay() << setw(2) << "|";
            cout << left << setw(8) << " " << setw(9) << arrayPerson[i]->getSurgery() << setw(2) << "|";
            cout << left << setw(7) << " " << setw(8) << "X" << setw(2) << "|";
        } else if (arrayPerson[i]->getUnit() == "Y ta") {
            cout << left << setw(7) << arrayPerson[i]->getUnit() << setw(2) << "|";
            cout << left << setw(4) << " " << setw(7) << arrayPerson[i]->getMonth() << setw(2) << "|";
            cout << left << setw(8) << " " << setw(9) << arrayPerson[i]->getWorkDay() << setw(2) << "|";
            cout << left << setw(8) << " " << setw(9) << "X" << setw(2) << "|";
            cout << left << setw(7) << " " << setw(8) << arrayPerson[i]->getNightShift() << setw(2) << "|";
        }
        cout << left << setw(8) << arrayPerson[i]->salary() << setw(7) << " " << setw(2) << "|";
        cout << endl;
    }
    for (int i=1;i<=4;i++)  cout <<"-"; cout << "+";
    for (int i=1;i<=24;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=12;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=15;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=8;i++)  cout <<"-"; cout << "+";
    for (int i=1;i<=12;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=18;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=18;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=16;i++) cout <<"-"; cout << "+";
    for (int i=1;i<=16;i++) cout <<"-"; cout << "+";
    cout << endl;
}

/**
 * Hàm thêm cán bộ vào danh sách
 */
void addPerson() { // Nguyễn Xuân Khánh 20213970
    Person tempPerson;
    cin >> tempPerson;
    if (tempPerson.getUnit()=="Bac si") {
        int tempWorkDay,tempSurgery;
        cout << "Nhap so ngay lam viec: ";
        cin >> tempWorkDay;
        cout << "Nhap so ca phau thuat thuc hien: ";
        cin >> tempSurgery; cin.ignore();
        Person *p = new Doctor(tempPerson.getName(),tempPerson.getDob(),tempPerson.getTel(),tempPerson.getUnit(),tempPerson.getMonth(),tempWorkDay,tempSurgery);
        ListPerson.push_back(p);
    } else if (tempPerson.getUnit()=="Y ta") {
        int tempWorkDay,tempNightShift;
        cout << "Nhap so ngay lam viec: ";
        cin >> tempWorkDay;
        cout << "Nhap so ca truc dem: ";
        cin >> tempNightShift; cin.ignore();
        Person *p = new Nurse(tempPerson.getName(),tempPerson.getDob(),tempPerson.getTel(),tempPerson.getUnit(),tempPerson.getMonth(),tempWorkDay,tempNightShift);
        ListPerson.push_back(p);
    }
    system("clear");
    cout << "Da them can bo vao danh sach!\n";
}

/**
 * Hàm dùng để chỉnh sửa thông tin cán bộ có trong danh sách.
 */
void modifyPersonInformation() { // Tạ Đức Mạnh 20213995
    printListPerson(ListPerson);
    cout << "Chon STT can bo muon sua thong tin: ";
    int number_1; cin >> number_1;
    system("clear");
    cout << "(1)Sua ho ten\n";
    cout << "(2)Sua ngay thang nam sinh\n";
    cout << "(3)Sua so dien thoai\n";
    cout << "(4)Sua don vi\n";
    cout << "(5)Sua thang can bo duoc them vao\n";
    cout << "(6)Sua so ngay lam viec\n";
    cout << "(7)Sua so ca phau thuat/so ca truc dem\n";
    cout << "Chon thong tin muon chinh sua: ";
    int number_2; cin >> number_2;
    system("clear");
    switch (number_2) {
        case 1: {
            cout << "Ten cu: " << ListPerson[number_1-1]->getName() << endl;
            cout << "Nhap ten moi: ";
            string newName; cin.ignore(); getline(cin,newName);
            ListPerson[number_1-1]->setName(newName);
            break;
        }
        case 2: {
            cout << "Ngay thang nam sinh cu: " << ListPerson[number_1-1]->getDob() << endl;
            cout << "Nhap ngay thang nam sinh moi: ";
            string newDob; cin.ignore(); getline(cin,newDob);
            ListPerson[number_1-1]->setDob(newDob);
            break;
        }
        case 3: {
            cout << "So dien thoai cu: " << ListPerson[number_1-1]->getTel() << endl;
            cout << "Nhap so dien thoai moi: ";
            string newTel; cin.ignore(); getline(cin,newTel);
            ListPerson[number_1-1]->setTel(newTel);
            break;
        }
        case 4: {
            cout << "Don vi cu: " << ListPerson[number_1-1]->getUnit() << endl;
            cout << "Nhap don vi moi: ";
            string newUnit; cin.ignore(); getline(cin,newUnit);
            ListPerson[number_1-1]->setUnit(newUnit);
            break;
        }
        case 5: {
            cout << "Thang duoc them cu: " << ListPerson[number_1-1]->getMonth() << endl;
            cout << "Nhap thang can bo duoc them moi: ";
            int month; cin >> month;
            ListPerson[number_1-1]->setMonth(month);
            break;
        }
        case 6: {
            cout << "So ngay lam viec cu: " << ListPerson[number_1-1]->getWorkDay() << endl;
            cout << "Nhap so ngay lam viec moi: ";
            int newWorkDay; cin >> newWorkDay;
            ListPerson[number_1-1]->setWorkDay(newWorkDay);
            cin.ignore();
            break;
        }
        case 7: {
            if (ListPerson[number_1-1]->getUnit() == "Bac si") {
                cout << "So ca phau thuat cu: " << ListPerson[number_1-1]->getSurgery() << endl;
                cout << "Nhap so ca phau thuat moi: ";
                int newSurgery; cin >> newSurgery;
                ListPerson[number_1-1]->setSurgery(newSurgery);
            } else if (ListPerson[number_1-1]->getUnit() == "Y ta") {
                cout << "So ca truc dem cu: " << ListPerson[number_1-1]->getNightShift() << endl;
                cout << "Nhap so ca truc dem moi: ";
                int newNightShift; cin >> newNightShift;
                ListPerson[number_1-1]->setNightShift(newNightShift);
            }
            cin.ignore();
            break;
        }
    }
    system("clear");
    cout << "Thong tin da duoc chinh sua!" << endl;
}

/**
 * Xoá một cán bộ có trong danh sách.
 */
void deletePerson() { // Tạ Đức Mạnh 20213995
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

/**
 * Tìm kiếm một(nhiều) cán bộ theo kí tự được nhập vào từ người dùng.
 */
void findPersonByName() { // Nguyễn Xuân Khánh 20213970
//****************************************************
//  Đây là hàm dùng tìm kiếm cán bộ theo kí tự được người dùng nhập vào.
//  Các bước thực hiện:
//      Bước 1: Chuyển toàn bộ các kí tự do người dùng nhập vào thành chữ cái in hoa
//              Chuyển toàn bộ các kí tự trong tên cán bộ thành chữ cái in hoa.
//      Bước 2: Nếu trong tên cán bộ có chứa kí tự do người dùng nhập vào thì push vào
//              vector result.
//***************************************************
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
        if (tempPersonName.find(tempInputName) != string::npos) {
            result.push_back(ListPerson[i]);
        }
    }
    system("clear");
    printListPerson(result);
}

vector<Person*> DoctorList() { // Tạ Đức Mạnh 20213995
    vector<Person*> doctor;
    for (int i=0;i<ListPerson.size();i++) {
        if (ListPerson[i]->getUnit()=="Bac si") {
            doctor.push_back(ListPerson[i]);
        }
    }
    return doctor;
}

vector<Person*> NurseList() { // Nguyễn Xuân Khánh 20213970
    vector<Person*> nurse;
    for (int i=0;i<ListPerson.size();i++) {
        if (ListPerson[i]->getUnit()=="Y ta") {
            nurse.push_back(ListPerson[i]);
        }
    }
    return nurse;
}

/**
 * Tìm kiếm và in ra màn hình tất cả cán bộ có tiền lương lớn hơn một số X nhập vào.
 */
void findPersonHaveSalaryHigherThanX() { // Nguyễn Xuân Khánh 20213970
    long long X;
    cout << "Nhap so tien muon so sanh(vnd): ";cin >> X;
    vector<Person*> result;
    for (int i=0;i<ListPerson.size();i++) {
        if (ListPerson[i]->salary()>X) {
            result.push_back(ListPerson[i]);
        }
    }
    system("clear");
    if (result.size()==0) {
        cout << "Khong co ai co tien luon lon hon: " << X << "(vnd)"<<endl;
    } else {
        printListPerson(result);
    }
}

/**
 * Hàm dùng để thống kê cán bộ theo tháng mà cán bộ được thêm vào danh sách.
 */
void StatByMonth() { // Nguyễn Xuân Khánh 20213970
    cout << "Nhap thang muon thong ke: ";
    int tempMonth; cin >> tempMonth;
    vector<Person*> result;
    for (int i=0;i<ListPerson.size();i++) {
        if (ListPerson[i]->getMonth() == tempMonth) {
            result.push_back(ListPerson[i]);
        }
    }
    printListPerson(result);
}

/**
 * Ghi thông tin của từng cán bộ vào file data.txt theo mẫu:
 * tên;ngày sinh;số điện thoại;đơn vị;tháng được thêm vào;số ngày làm việc;số ca phẫu thuật;
 * số ca trực đêm;tiền lương.
 */
void BackUpData() { // Tạ Đức Mạnh 20213995
    sortListPerson();
    DataFile.open("data.txt",ios::out);
    for (int i=0;i<ListPerson.size();i++) {
        if (i == ListPerson.size()-1){
            if (ListPerson[i]->getUnit()=="Bac si") {
                DataFile << ListPerson[i]->getName() << ";" << ListPerson[i]->getDob() << ";" << ListPerson[i]->getTel() << ";" << ListPerson[i]->getUnit() << ";" << ListPerson[i]->getMonth() << ";" << ListPerson[i]->getWorkDay() << ";" << ListPerson[i]->getSurgery() << ";" << ListPerson[i]->salary();
            } else if (ListPerson[i]->getUnit()=="Y ta") {
                DataFile << ListPerson[i]->getName() << ";" << ListPerson[i]->getDob() << ";" << ListPerson[i]->getTel() << ";" << ListPerson[i]->getUnit() << ";" << ListPerson[i]->getMonth() << ";" << ListPerson[i]->getWorkDay() << ";" << ListPerson[i]->getNightShift() << ";" << ListPerson[i]->salary();
            }
        } else {
            if (ListPerson[i]->getUnit()=="Bac si") {
                DataFile << ListPerson[i]->getName() << ";" << ListPerson[i]->getDob() << ";" << ListPerson[i]->getTel() << ";" << ListPerson[i]->getUnit() << ";" << ListPerson[i]->getMonth() << ";" << ListPerson[i]->getWorkDay() << ";" << ListPerson[i]->getSurgery() << ";" << ListPerson[i]->salary() << endl;
            } else if (ListPerson[i]->getUnit()=="Y ta") {
                DataFile << ListPerson[i]->getName() << ";" << ListPerson[i]->getDob() << ";" << ListPerson[i]->getTel() << ";" << ListPerson[i]->getUnit() << ";" << ListPerson[i]->getMonth() << ";" << ListPerson[i]->getWorkDay() << ";" << ListPerson[i]->getNightShift() << ";" << ListPerson[i]->salary() << endl;
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
                printListPerson(DoctorList());
                cin.ignore();
                cout << "Nhan phim bat ky de thoat: ";
                cin.get();
                break;
            }
            case 7: {
                printListPerson(NurseList());
                cin.ignore();
                cout << "Nhan phim bat ky de thoat: ";
                cin.get();
                break;
            }
            case 8: {
                findPersonHaveSalaryHigherThanX();
                cin.ignore();
                cout << "Nhap phim bat ky de thoat: ";
                cin.get();
                break;
            }
            case 9: {
                StatByMonth();
                cin.ignore();
                cout << "Nhap phim bat ky de thoat: ";
                cin.get();
                break;
            }
            case 10: {
                BackUpData();
                cin.ignore();
                cout << "Nhap phim bat ky de thoat: ";
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