
//write a c++ program to manage a universtiy department using the following requiremwents 
//1. create a class faculty 
//  a - faculty name 
//   b - employee id
//   c- constructor and a function display faculty
//2. create a class office with 
//   - room number
//   - room capacity
//   - constructor and a function display office
//3. Create a class department with 
//   a- deptname
//   b- a pointer or reference to a faculty object to show aggregation
//   c- an office objct as a data member to show composition
//4. A nested class deptinfo containing 
//   a- building name 
//   b- floor number 
//   c- contructor 
 //  d- display infor
//5. A function display department that displays all dept details
//   a- In the main funct create a faculty object independent to the dept
//   b- create a dept object associated with that faculty member
//   c- display the dept, faculty , office and building info

#include<iostream>
#include<string>
using namespace std;

class Faculty
{
    public:
    string facultyname;
    int employeeid;
    
    Faculty(string name, int id) {
        facultyname = name;
        employeeid = id;
    }
 
 void displayFaculty() {
        cout << "Faculty Name: " << facultyname << endl;
        cout << "Employee ID: " << employeeid << endl;
    }
};
class Office {
public:
    int roomNumber;
    int roomCapacity;

    Office(int room, int capacity) {
        roomNumber = room;
        roomCapacity = capacity;
    }

    void displayOffice() {
        cout << "Room Number: " << roomNumber << endl;
        cout << "Room Capacity: " << roomCapacity << endl;
    }
};

class Department{
    public:
    string deptName;
    Faculty* faculty;   
    //aggregation points to faculty
    Office office;      
    // Composition in Office is created by Department
    class DeptInfo 
    {
      public:
        string buildingName;
        int floorNumber;

        DeptInfo(string bname, int floor) 
        {
            buildingName = bname;
            floorNumber = floor;
        }
        void displayInfo() 
        {
            cout << "Building Name: " << buildingName << endl;
            cout << "Floor Number: " << floorNumber << endl;
        }    
    };
 DeptInfo info;
    Department(string dname,
               Faculty* f, 
               int room, 
               int capacity,
               string bname, 
               int floor)
        : office(room, capacity), 
          info(bname, floor)
// due to deotinfo being a nested class we make an object to call and define object to call it in display function 
// int main mei islie nhi banaya due to 
  {
        deptName = dname;
        faculty = f;
    }


 void displayDepartment() {
        cout << "\n--- Department Details ---\n" << endl;
        cout << "=====================================" << endl;
        cout << "Department Name: " << deptName << endl;
        cout << "--------------------------------------------" << endl;
        cout << "[Faculty Details]" << endl;
        faculty->displayFaculty();
        cout << "--------------------------------------------" << endl;
        cout << "[Office Details]" << endl;
        office.displayOffice();
        cout << "--------------------------------------------" << endl;
        cout << "[Building Info]" << endl;
        info.displayInfo();
        cout << "==============================================" << endl;
    }
};
int main() {
    int empId, room, capacity, floor;
    string facultyName, deptName, building;

    cout << "Enter Faculty Name: ";
    getline(cin, facultyName);

    cout << "Enter Employee ID: ";
    cin >> empId;

    cin.ignore();
    cout << "Enter Department Name: ";
    getline(cin, deptName);

    cout << "Enter Office Room Number: ";
    cin >> room;

    cout << "Enter Room Capacity: ";
    cin >> capacity;

    cin.ignore();
    cout << "Enter Building Name: ";
    getline(cin, building);

    cout << "Enter Floor Number: ";
    cin >> floor;

    Faculty f(facultyName, empId);

    Department d(deptName, &f, room, capacity, building, floor);

    d.displayDepartment();
    return 0;
};
