#include"111.h"


const int MAX_EMPLOYEES = 1000; // 最大员工数量


int main() {
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;// 总员工数
    readFromFile(employees, employeeCount);
    //初始化，读取文件，将文件数据保存


    char choice;
    do {
        displayMenu();
        cout << "请在数字范围内选择: ";
        cin >> choice;
        cin.ignore();// 从缓冲区中清除换行符

        switch (choice) {
        case '1':
            addEmployee(employees, employeeCount);
            break;
        case '2':
            updateEmployee(employees, employeeCount);
            break;
        case '3':
            deleteEmployee(employees, employeeCount);
            break;
        case '4':
            searchEmployeeById(employees, employeeCount);
            break;
        case '5':
            searchEmployeeByName(employees, employeeCount);
            break;
        case '6':
            saveToFile(employees, employeeCount);
            break;
        case '7':
            readFromFile(employees, employeeCount);
            break;
        case '8':
            cout << "程序退出成功!" << endl;
            break;
        default:
            cout << "请重新范围输入内的编号数字" << endl;
        }
    } while (choice != '8');

    return 0;
}
