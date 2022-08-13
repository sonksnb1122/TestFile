#include <iostream>
#include <vector>

using namespace std;

class Employee{
protected:
    string m_name;
    int m_age;
    string m_projectName;
public:
    string m_employeeID;
    Employee(string m_Name, int m_Age, string m_EmployeeID, string m_ProjectName){
        m_name = m_Name;
        m_age = m_Age;
        m_employeeID = m_EmployeeID;
        m_projectName = m_ProjectName;
    }

    virtual void printInformation(){
        cout << "Name : " << m_name << endl;
        cout << "Age : " << m_age << endl;
        cout << "Employee ID : " << m_employeeID << endl;
        cout << "ProjectName : " << m_projectName << endl;
    }

    void doWork(){
        Tester::doWork();
    }
};

class Tester : public Employee {

public:
    Tester(string m_Name, int m_Age, string m_EmployeeID, string m_ProjectName): Employee(m_Name,m_Age,m_EmployeeID,m_ProjectName){}
    void doWork(){
        cout << "Tester: " << Tester::m_name << " is testing software in project " << Tester::m_projectName << endl;
    }
};

class Developer : public Employee {

public:
    Developer(string m_Name, int m_Age, string m_EmployeeID, string m_ProjectName): Employee(m_Name,m_Age,m_EmployeeID,m_ProjectName){}

    void doWork(){
        cout << "Developer: " << Developer::m_name << " is developing software in project " << Developer::m_projectName << endl;
    }
};

class ProjectManager : public Employee {

public:
    ProjectManager(string m_Name, int m_Age, string m_EmployeeID, string m_ProjectName): Employee(m_Name,m_Age,m_EmployeeID,m_ProjectName){}
    void doWork(){
        cout << "Project Manager: " << ProjectManager::m_name << " is managing project " << ProjectManager::m_projectName << endl;
    }
};

class TeamLeader : public Employee {

};

class Project{
    std::vector<Employee*> m_employees;
    string m_projectName;
public:
    Project(string m_ProjectName) {
        m_projectName = m_ProjectName;
    }
    enum EmployeeRole{
        E_TESTER,
        E_DEVELOPER,
        E_MANAGER
    };
    void addEmployee(string name, int age, string employeeID, EmployeeRole role){
        if (role == E_TESTER)
            m_employees.push_back(new Tester(name, age, employeeID, m_projectName));
        else if (role == E_DEVELOPER)
            m_employees.push_back(new Developer(name, age, employeeID, m_projectName));
        else if (role == E_MANAGER)
            m_employees.push_back(new ProjectManager(name, age, employeeID, m_projectName));
    }
    void removeEmployee(string employeeID){
        for (int i = 0; i < m_employees.size(); i++) {
            if (m_employees[i]->m_employeeID == employeeID) {
                m_employees.erase(m_employees.begin() + i);
                break;
            }
        }
    }
    void showEmployees(){
        for (int i = 0; i < m_employees.size(); i++) {
            m_employees[i]->printInformation();
        }
    }
    void projectWorking(){
        for (int i = 0; i < m_employees.size(); i++){
            m_employees[i]->doWork();
        }
    }

};

int main()
{
    string projectname;
    cout << "Nhap project name : ";
    cin >> projectname;
    Project project(projectname);
    cout << "Nhap so thanh vien : ";
    int member;
    cin >> member;
    for ( int i = 0 ; i < member ; i++ ){
        cout << "\nNhap thanh vien thu "<< i+1 << endl;
        string name;
        cout << "Nhap ten : ";
        cin >> name;
        int age;
        cout << "Nhap tuoi : ";
        cin >> age;
        string id;
        cout << "Nhap ID : ";
        cin >> id;
        string job;
        cout << "Nhap cong viec (tester,developer,manager) : ";
        fflush(stdin);
        cin >> job;
        if (job == "tester"){
            project.addEmployee(name,age,id,Project::E_TESTER);
        }
        else if (job == "developer"){
            project.addEmployee(name,age,id,Project::E_DEVELOPER);
        }
        else if (job == "manager"){
            project.addEmployee(name,age,id,Project::E_MANAGER);
        }
    }
    string dltID;
    cout << "\nNhap ID nguoi can xoa : ";
    cin >> dltID;
    cout << endl;
    project.removeEmployee(dltID);
    project.projectWorking();
    project.showEmployees();

    return 0;
}
