// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
// if debugging is solving errors in code.
// then programming is the process of introducing errors in the code.
class employee
{
private:
    int ID;
    string name;
    string designation;

public:
    // constructor
    employee(int id, string name, string designation)
    {
        cout << "doosra wala constructor is called " << endl;
        this->ID = id;
        this->name = name;
        this->designation = designation;
    }
    employee()
    {
        cout << "Default constructor is called " << endl;
    }
    employee(int id, string name)
    {
        cout << "teesra wala constructor is called " << endl;
        this->ID = id;
        this->name = name;
    }
    // setter functions
    void setID(int ID)
    {
        this->ID = ID;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setDesignation(string designation)
    {
        this->designation = designation;
    }

    // getter function --> return
    int getID()
    {
        return ID;
    }
    string getName()
    {
        return name;
    }
    string getDesignation()
    {
        return designation;
    }
    void DisplayInformation()
    {
        cout << this->ID << " " << this->name << " " << this->designation << endl;
    }
};

int main()
{
    employee emp1;
    employee emp2(11, "muneeb", "Learner of OOP");
    employee emp3(11, "muneeb");

    emp1.setID(10);
    emp1.setName("abdul raheem");
    emp1.setDesignation("Senior c++ engineer");

    emp1.DisplayInformation();
    cout << endl;
    emp2.DisplayInformation();
    cout << endl;
    emp3.DisplayInformation();
}