#include <iostream>
#include <math.h>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date() {
        day = 1; month = 1; year = 1900;
    }

    Date(int day, int month, int year) {
        this->day = day; this->month = month; this->year = year;
    }

    void input() {
        cin >> this->day >> this->month >> this->year;
    }

    void display() {
        cout << this->day << "-" << this->month << "-" << this->year << endl;
    }

    int dayOfMonth(int m, int y) {
        int numofday;
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            numofday = 31;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            numofday = 30;
        }
        if (m == 2) {
            if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
                numofday = 29;
            }
            else {
                numofday = 28;
            }
        }
        return numofday;
    }
    bool namNhuan(int y) {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            return true;
        }
        return false;
    }


    int dayOfTheYear() {
        int count = day;
        for (int i = 1; i < month; i++) {
            count = count + dayOfMonth(i, year);
        }
        return count;
    }

    int differentDays(Date dt) {
        int first = 0, last = 0, dau = 0, cuoi = 0, value = 0;

        if (dt.year > year) {
            first = year;
            last = dt.year;
            dau = dayOfTheYear();
            cuoi = dt.dayOfTheYear();
        }
        else {
            first = dt.year;
            last = year;
            cuoi = dayOfTheYear();
            dau = dt.dayOfTheYear();
        }

        if (dt.year == year) {
            return abs(dt.dayOfTheYear() - dayOfTheYear());
        }
        else {
            for (int i = first + 1; i < last; i++) {
                if (namNhuan(i)) {
                    value = value + 366;
                }
                else {
                    value = value + 365;
                }
            }
            if (namNhuan(first)) {
                first = 366 - dau;
            }
            else {
                first = 365 - dau;
            }
            last = cuoi;

            return first + value + last;
        }

    }



};
int main()
{
    Date dt1;
    Date dt2(20, 10, 2001);
    Date dt3;
    Date dt4;

    dt3.input();
    dt4.input();

    dt1.display(); // 1-1-1900
    dt2.display(); // 20-10-2001
    dt3.display();
    dt4.display();

    cout << dt3.differentDays(dt4);

    return 0;
}
