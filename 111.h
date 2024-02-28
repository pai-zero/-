#include <iostream>
#include <fstream>// 包含ifstream、ofstream两类，包含输入输出文件
#include <sstream>// istringstream输入、ostringstream输出 和 stringstream输入输出


using namespace std;


struct Employee {
    int id;
    string name;
    string gender;
    string education;
    string position;
    string idNumber;
    string phoneNumber;
    string notes;
};

void displayMenu();// 菜单模块
void addEmployee(Employee employees[], int& count);// 添加模块
void updateEmployee(Employee employees[], int count);// 修改模块
void deleteEmployee(Employee employees[], int& count);// 删除模块
void searchEmployeeById(const Employee employees[], int count);// 查询模块，工号查询
void searchEmployeeByName(const Employee employees[], int count);// 查询模块，姓名查询
void saveToFile(const Employee employees[], int count);// 保存模块
void readFromFile(Employee employees[], int& count);// 读取模块
// const修饰指针变量,防止其意外修改，例如 const int i=5;之后i无法被赋予新值

void displayMenu() {
    // 菜单模块
    cout << "\n员工管理系统菜单：" << endl;
    cout << "1. 添加员工" << endl;
    cout << "2. 更新员工" << endl;
    cout << "3. 删除员工" << endl;
    cout << "4. 按工号查询员工" << endl;
    cout << "5. 按姓名查询员工" << endl;
    cout << "6. 保存文件" << endl;
    cout << "7. 读取文件" << endl;
    cout << "8. 退出" << endl;
}

void addEmployee(Employee employees[], int& count) {
    // 添加模块
    Employee emp;
    cout << "\n请输入需添加员工的信息:" << endl;
    cout << "工号: ";
    cin >> emp.id;
    cin.ignore();// 从缓冲区中清除换行符

    // 检查员工是否已存在
    for (int i = 0; i < count; ++i) {
        if (employees[i].id == emp.id) {
            cout << "此工号 " << emp.id << " 已存在。请重新选择" << endl;
            return;
        }
    }

     // getline()包含于<iostream>中
    cout << "姓名: ";
    getline(cin, emp.name);// cin >> emp.name;
    cout << "性别: ";
    getline(cin, emp.gender);
    cout << "学历: ";
    getline(cin, emp.education);
    cout << "职位: ";
    getline(cin, emp.position);
    cout << "身份证号: ";
    getline(cin, emp.idNumber);
    cout << "电话号: ";
    getline(cin, emp.phoneNumber);
    cout << "备注信息: ";
    getline(cin, emp.notes);

    employees[count++] = emp;
    cout << "员工信息添加成功！" << endl;
}

void updateEmployee(Employee employees[], int count) {
    // 修改模块
    int empId;// 欲修改员工工号
    cout << "\n输入要更新的员工的工号: ";
    cin >> empId;
    cin.ignore();// 从缓冲区中清除换行符 

    for (int i = 0; i < count; ++i) {
        if (employees[i].id == empId) {
            cout << "输入此员工的更新详细信息 " << empId << ":" << endl;
            cout << "姓名: ";
            getline(cin, employees[i].name);
            cout << "性别: ";
            getline(cin, employees[i].gender);
            cout << "学历: ";
            getline(cin, employees[i].education);
            cout << "职位: ";
            getline(cin, employees[i].position);
            cout << "身份证号: ";
            getline(cin, employees[i].idNumber);
            cout << "电话号: ";
            getline(cin, employees[i].phoneNumber);
            cout << "备注信息: ";
            getline(cin, employees[i].notes);

            cout << "员工信息更新成功！" << endl;
            return;
        }
    }

    cout << "员工" << empId << " 信息不在信息库中。" << endl;
}

void deleteEmployee(Employee employees[], int& count) {
    // 删除模块
    int empId;// 欲删除员工工号
    cout << "\n输入要删除的员工的工号: ";
    cin >> empId;
    cin.ignore(); // 从缓冲区中清除换行符

    for (int i = 0; i < count; ++i) {
        if (employees[i].id == empId) {
            for (int j = i; j < count - 1; ++j) {
                employees[j] = employees[j + 1];
            }

            --count;
            cout << "员工 " << empId << " 删除成功！" << endl;
            return;
        }
    }

    cout << "员工 " << empId << " 信息不在信息库中。" << endl;
}

void searchEmployeeById(const Employee employees[], int count) {
    // 查询模块，工号查询
    int empId;// 欲查询员工工号
    cout << "\n输入要查找的员工工号: ";
    cin >> empId;

    for (int i = 0; i < count; ++i) {
        if (employees[i].id == empId) {
            cout << "\n员工信息:" << endl;
            cout << "工号: " << employees[i].id << endl;
            cout << "姓名: " << employees[i].name << endl;
            cout << "性别: " << employees[i].gender << endl;
            cout << "学历: " << employees[i].education << endl;
            cout << "职位: " << employees[i].position << endl;
            cout << "身份证号: " << employees[i].idNumber << endl;
            cout << "电话号: " << employees[i].phoneNumber << endl;
            cout << "备注信息: " << employees[i].notes << endl;
            return;
        }
    }

    cout << "员工 " << empId << " 信息不在信息库中。" << endl;
}

void searchEmployeeByName(const Employee employees[], int count) {
    // 查询模块，姓名查询
    string empName;// 欲查询员工姓名
    cout << "\n输入要查找的员工姓名: ";
    getline(cin, empName);

    for (int i = 0; i < count; ++i) {
        if (employees[i].name == empName) {
            cout << "\n员工信息:" << endl;
            cout << "工号: " << employees[i].id << endl;
            cout << "姓名: " << employees[i].name << endl;
            cout << "性别: " << employees[i].gender << endl;
            cout << "学历: " << employees[i].education << endl;
            cout << "职位: " << employees[i].position << endl;
            cout << "身份证号: " << employees[i].idNumber << endl;
            cout << "电话号: " << employees[i].phoneNumber << endl;
            cout << "备注信息: " << employees[i].notes << endl;
            return;
        }
    }

    cout << "员工 " << empName << " 信息不在信息库中" << endl;
}

void saveToFile(const Employee employees[], int count) {
    // 保存模块
    ofstream outfile("employee_data.csv");//  写入文件，使用<<
    if (!outfile.is_open()) {
        cout << "打开文件进行写入时出错。" << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        outfile << employees[i].id << "," << employees[i].name << "," << employees[i].gender << ","
            << employees[i].education << "," << employees[i].position << "," << employees[i].idNumber << ","
            << employees[i].phoneNumber << "," << employees[i].notes << endl;
    }

    outfile.close();
    cout << "数据已成功保存到文件。" << endl;
}

void readFromFile(Employee employees[], int& count) {
    // 读取模块
    count = 0; // 在文件读取之前清除现有数据

    system("cls");
    
    ifstream infile("employee_data.csv");// ifstream默认以输入方式打开文件
    if (!infile.is_open()) {
        cout << "打开文件进行读取时出错。" << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        // stringstream包含于std中，允许将字符串作为流进行处理
        // 可以理解为将line中的元素拆分为数个Employee中的元素，拆分判断为“,”
        Employee emp;
        char delimiter = ',';

        ss >> emp.id;
        ss >> delimiter;

        getline(ss, emp.name, delimiter);
        // 用于从字符串 ss 中读取一行数据，直到遇到指定的分隔符 delimiter 或者到达流的结尾。
        // 用于读取并存储员工的姓名，直到遇到逗号分隔符或者到达行尾。
        
        getline(ss, emp.gender, delimiter);
        getline(ss, emp.education, delimiter);
        getline(ss, emp.position, delimiter);
        getline(ss, emp.idNumber, delimiter);
        getline(ss, emp.phoneNumber, delimiter);
        getline(ss, emp.notes);

        employees[count++] = emp;
    }

    infile.close();
    cout << "已成功从文件中读取数据。" << endl;
}
