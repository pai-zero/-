#include"111.h"


const int MAX_EMPLOYEES = 1000; // ���Ա������


int main() {
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;// ��Ա����
    readFromFile(employees, employeeCount);
    //��ʼ������ȡ�ļ������ļ����ݱ���


    char choice;
    do {
        displayMenu();
        cout << "�������ַ�Χ��ѡ��: ";
        cin >> choice;
        cin.ignore();// �ӻ�������������з�

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
            cout << "�����˳��ɹ�!" << endl;
            break;
        default:
            cout << "�����·�Χ�����ڵı������" << endl;
        }
    } while (choice != '8');

    return 0;
}
