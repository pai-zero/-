#include <iostream>
#include <fstream>
#include <sstream>

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

void displayMenu();// �˵�ģ��
void addEmployee(Employee employees[], int& count);// ���ģ��
void updateEmployee(Employee employees[], int count);// �޸�ģ��
void deleteEmployee(Employee employees[], int& count);// ɾ��ģ��
void searchEmployeeById(const Employee employees[], int count);// ��ѯģ�飬���Ų�ѯ
void searchEmployeeByName(const Employee employees[], int count);// ��ѯģ�飬������ѯ
void saveToFile(const Employee employees[], int count);// ����ģ��
void readFromFile(Employee employees[], int& count);// ��ȡģ��
// const����ָ�����

void displayMenu() {
    // �˵�ģ��
    cout << "\nԱ������ϵͳ�˵���" << endl;
    cout << "1. ���Ա��" << endl;
    cout << "2. ����Ա��" << endl;
    cout << "3. ɾ��Ա��" << endl;
    cout << "4. �����Ų�ѯԱ��" << endl;
    cout << "5. ��������ѯԱ��" << endl;
    cout << "6. �����ļ�" << endl;
    cout << "7. ��ȡ�ļ�" << endl;
    cout << "8. �˳�" << endl;
}

void addEmployee(Employee employees[], int& count) {
    // ���ģ��
    Employee emp;
    cout << "\n�����������Ա������Ϣ:" << endl;
    cout << "����: ";
    cin >> emp.id;
    cin.ignore();// �ӻ�������������з�

    // ���Ա���Ƿ��Ѵ���
    for (int i = 0; i < count; ++i) {
        if (employees[i].id == emp.id) {
            cout << "�˹��� " << emp.id << " �Ѵ��ڡ�������ѡ��" << endl;
            return;
        }
    }

    cout << "����: ";
    getline(cin, emp.name);
    cout << "�Ա�: ";
    getline(cin, emp.gender);
    cout << "ѧ��: ";
    getline(cin, emp.education);
    cout << "ְλ: ";
    getline(cin, emp.position);
    cout << "���֤��: ";
    getline(cin, emp.idNumber);
    cout << "�绰��: ";
    getline(cin, emp.phoneNumber);
    cout << "��ע��Ϣ: ";
    getline(cin, emp.notes);

    employees[count++] = emp;
    cout << "Ա����Ϣ��ӳɹ���" << endl;
}

void updateEmployee(Employee employees[], int count) {
    // �޸�ģ��
    int empId;
    cout << "\n����Ҫ���µ�Ա���Ĺ���: ";
    cin >> empId;
    cin.ignore();// �ӻ�������������з� Ĭ��(64,'/n')

    for (int i = 0; i < count; ++i) {
        if (employees[i].id == empId) {
            cout << "�����Ա���ĸ�����ϸ��Ϣ " << empId << ":" << endl;
            cout << "����: ";
            getline(cin, employees[i].name);
            cout << "�Ա�: ";
            getline(cin, employees[i].gender);
            cout << "ѧ��: ";
            getline(cin, employees[i].education);
            cout << "ְλ: ";
            getline(cin, employees[i].position);
            cout << "���֤��: ";
            getline(cin, employees[i].idNumber);
            cout << "�绰��: ";
            getline(cin, employees[i].phoneNumber);
            cout << "��ע��Ϣ: ";
            getline(cin, employees[i].notes);

            cout << "Ա����Ϣ���³ɹ���" << endl;
            return;
        }
    }

    cout << "Ա��" << empId << " ��Ϣ������Ϣ���С�" << endl;
}

void deleteEmployee(Employee employees[], int& count) {
    // ɾ��ģ��
    int empId;
    cout << "\n����Ҫɾ����Ա���Ĺ���: ";
    cin >> empId;
    cin.ignore(); // �ӻ�������������з�

    for (int i = 0; i < count; ++i) {
        if (employees[i].id == empId) {
            for (int j = i; j < count - 1; ++j) {
                employees[j] = employees[j + 1];
            }

            --count;
            cout << "Ա�� " << empId << " ɾ���ɹ���" << endl;
            return;
        }
    }

    cout << "Ա�� " << empId << " ��Ϣ������Ϣ���С�" << endl;
}

void searchEmployeeById(const Employee employees[], int count) {
    // ��ѯģ�飬���Ų�ѯ
    int empId;
    cout << "\n����Ҫ���ҵ�Ա������: ";
    cin >> empId;

    for (int i = 0; i < count; ++i) {
        if (employees[i].id == empId) {
            cout << "\nԱ����Ϣ:" << endl;
            cout << "����: " << employees[i].id << endl;
            cout << "����: " << employees[i].name << endl;
            cout << "�Ա�: " << employees[i].gender << endl;
            cout << "ѧ��: " << employees[i].education << endl;
            cout << "ְλ: " << employees[i].position << endl;
            cout << "���֤��: " << employees[i].idNumber << endl;
            cout << "�绰��: " << employees[i].phoneNumber << endl;
            cout << "��ע��Ϣ: " << employees[i].notes << endl;
            return;
        }
    }

    cout << "Ա�� " << empId << " ��Ϣ������Ϣ���С�" << endl;
}

void searchEmployeeByName(const Employee employees[], int count) {
    // ��ѯģ�飬������ѯ
    string empName;
    cout << "\n����Ҫ���ҵ�Ա������: ";
    getline(cin, empName);

    for (int i = 0; i < count; ++i) {
        if (employees[i].name == empName) {
            cout << "\nԱ����Ϣ:" << endl;
            cout << "����: " << employees[i].id << endl;
            cout << "����: " << employees[i].name << endl;
            cout << "�Ա�: " << employees[i].gender << endl;
            cout << "ѧ��: " << employees[i].education << endl;
            cout << "ְλ: " << employees[i].position << endl;
            cout << "���֤��: " << employees[i].idNumber << endl;
            cout << "�绰��: " << employees[i].phoneNumber << endl;
            cout << "��ע��Ϣ: " << employees[i].notes << endl;
            return;
        }
    }

    cout << "Ա�� " << empName << " ��Ϣ������Ϣ����" << endl;
}

void saveToFile(const Employee employees[], int count) {
    // ����ģ��
    ofstream outfile("employee_data.csv");
    if (!outfile.is_open()) {
        cout << "���ļ�����д��ʱ����" << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        outfile << employees[i].id << "," << employees[i].name << "," << employees[i].gender << ","
            << employees[i].education << "," << employees[i].position << "," << employees[i].idNumber << ","
            << employees[i].phoneNumber << "," << employees[i].notes << endl;
    }

    outfile.close();
    cout << "�����ѳɹ����浽�ļ���" << endl;
}

void readFromFile(Employee employees[], int& count) {
    // ��ȡģ��
    count = 0; // ���ļ���ȡ֮ǰ�����������

    ifstream infile("employee_data.csv");// ifstreamĬ�������뷽ʽ���ļ�
    if (!infile.is_open()) {
        cout << "���ļ����ж�ȡʱ����" << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        Employee emp;
        char delimiter = ',';

        ss >> emp.id;
        ss >> delimiter;

        getline(ss, emp.name, delimiter);
        getline(ss, emp.gender, delimiter);
        getline(ss, emp.education, delimiter);
        getline(ss, emp.position, delimiter);
        getline(ss, emp.idNumber, delimiter);
        getline(ss, emp.phoneNumber, delimiter);
        getline(ss, emp.notes);

        employees[count++] = emp;
    }

    infile.close();
    cout << "�ѳɹ����ļ��ж�ȡ���ݡ�" << endl;
}
