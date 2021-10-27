#include <iostream>
#include <vector>
using namespace std;
class IntVector
{
private:
    int len;
    int* pArr;
public:
    IntVector(int len = 0, int value = 0) {
        this->len = len;
        pArr = new int[this->len];
        for (int i = 0; i < this->len; i++) {
            *(pArr + i) = value;
        }
    }
    IntVector(const IntVector& vt) {
        this->len = vt.len;
        pArr = new int[this->len];
        for (int i = 0; i < this->len; i++) {
            *(this->pArr + i) = *(vt.pArr + i);
        }
    }
    void pop_back() {  //1 2 3 4
        //*(pArr + len-2) = *(pArr + len - 1);
        len--;
    }
    void push_back(int value) {
        *(pArr + len) = value;
        len++;
    }
    void display() {
        for (int i = 0; i < this->len; i++) {
            if (i < this->len - 1) {
                cout << *(pArr + i) << " ";
            }
            else {
                cout << *(pArr + i) << endl;
            }
        }

    }
    ~IntVector()
    {
        delete[] pArr;
    }
};
int main()
{
    IntVector vt1(4, 8); // 8 8 8 8
    IntVector vt2 = vt1; // 8 8 8 8
    vt2.pop_back(); // 8 8 8
    vt2.pop_back(); // 8 8

    // Number of new items
    int newItems;
    cin >> newItems;

    // Add items
    for (int i = 0; i < newItems; i++) {
        int val;
        cin >> val;
        vt2.push_back(val);
    }

    vt1.display(); // 8 8 8 8
    vt2.display(); // ???
    return 0;
}
