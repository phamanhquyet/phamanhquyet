#include <iostream>
#include <vector>

using namespace std;
class Date
{
private:
    int day, month, year;
public:
    Date() {
        this->day = 1;
        this->month = 1;
        this->year = 1;
    }
    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    int getDay() {
        return day;
    }
};
class Student
{
private:
    string id;
    string fullName;
    string address;
    Date dt;
public:
    Student() {}
    Student(string id, string fullName, string address, Date dt) {
        this->id = id;
        this->fullName = fullName;
        this->address = address;
        this->dt = dt;
    }
    string getID() {
        return id;
    }
    string getFullName() {
        return fullName;
    }
    string getAddress() {
        return address;
    }
    Date getDate() {
        return dt;
    }
    void display() {
        cout << getID() << " " << getFullName() << " " << getAddress() << " " << getDate().getDay() << endl;
    }
};

class Students
{
private:
    int len = 0;
    Student* pArr;
public:
    Students() {
        this->len = 0;
        pArr = nullptr;
        pArr = new Student[this->len+1];
    }
    void pop_back() {
        this->len -= 1;
    }
    void push_back(Student value) {
        if (this->len <= 0) {
            pArr = new Student[this->len + 1];
            *(pArr + this->len) = value;
            this->len = this->len + 1;
        }
        else { // neu this->len > 0;
            Student* pArr1 = new Student[this->len + 1];
            for (int i = 0; i < this->len; i++) {
                *(pArr1 + i) = *(pArr + i);
            }
            *(pArr1 + this->len) = value;
            pArr = pArr1;
            this->len = this->len + 1;
        }
    }
    int size() {
        int count = 0;
        for (int i = 0; i < this->len; i++) {
            count++;
        }
        return count;
    }
    void display() {
        for (int i = 0; i < this->len; i++) {
            cout << "- "<<(*(pArr + i)).getFullName()<<" ("<< (*(pArr + i)).getID()<<")"<<endl;
        }
    }
    Students(const Students& st) {
        this->len = st.len;
        pArr = new Student[this->len];
        for (int i = 0; i < this->len; i++) {
            *(this->pArr + i) = *(st.pArr + i);
        }
    }
    ~Students() {
        delete[] pArr;
    }
};

int main()
{
    Date dt1(12, 2, 2002);
    Student st1("26201242086", "Nguyen Hoc Lan", "12 Hoang Hoa Tham", dt1);

    Date dt2(12, 3, 2001);
    Student st2("26211441593", "Nguyen Quoc Nhat", "254 Nguyen Van Linh", dt2);

    Date dt3(8, 9, 2000);
    Student st3("26211238959", "Tran Thanh Thien", "128 Tai Do", dt3);
    Students sts1;
    sts1.push_back(st1); // sts1 contains: st1
    sts1.push_back(st2); // sts1 contains: st1, st2
    sts1.push_back(st3); // sts1 contains: st1, st2, st3

    Students sts2 = sts1; // sts2 contains: st1, st2, st3
    sts2.pop_back(); // sts2 contains: st1, st2
    sts2.pop_back(); // sts2 contains: st1
    sts2.push_back(st3); // sts2 contains: st1, st3

    cout << "sts1 has " << sts1.size() << " students:" << endl;
    sts1.display();

    cout << "sts2 has " << sts2.size() << " students:" << endl;
    sts2.display();
    return 0;
}
