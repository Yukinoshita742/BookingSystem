#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include"Identity.h"
#include"globalFile.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
using namespace std;


//������ʦ���Ӳ˵�����
void teacherMenu(Identity*& teacher) {
	while (true) {
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2) {
			//���ԤԼ
			tea->validOrder();
		}
		else{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����ѧ�����Ӳ˵�����
void studentMenu(Identity*& student) {
	while (true) {
		//����ѧ���Ӳ˵�
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;

		if (select == 1) {
			//����ԤԼ
			stu->applyOrder();
		}
		else if (select == 2) {
			//�鿴����ԤԼ
			stu->showMyOrder();
		}
		else if (select == 3) {
			//�鿴������ԤԼ
			stu->showAllOrder();
		}
		else if (select == 4) {
			//ȡ��ԤԼ
			stu->cancelOrder();
		}
		else {
			//ע����¼
			delete student;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		
	}
}


//�������Ա���Ӳ˵�����
void managerMenu(Identity*& manager) {
	while (true) {
		//���ù���Ա�Ӳ˵�
		manager->operMenu();

		//�������ָ��תΪ����ָ�룬�������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		//����˺�
		if (select == 1) {
			//cout << "����˺�" << endl;
			man->addPerson();
		}
		//�鿴�˺�
		else if (select == 2) {
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		//�鿴����
		else if (select == 3) {
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		//���ԤԼ
		else if (select == 4) {
			//cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		//ע��
		else {
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}



//��¼����
void LoginIn(string fileName, int type) {
	//����ָ�� ָ���������
	Identity* person = nullptr;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}
	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1) {//ѧ�����
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1) {
		//ѧ�������֤
		int fId;//���ļ��ж�ȡ��id
		string fName;//�ļ�����
		string fPwd;//�ļ�����
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//���뵽ѧ������Ӳ˵�
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2) {
		//��ʦ�����֤
		int fId;//���ļ��ж�ȡ��id
		string fName;//�ļ�����
		string fPwd;//�ļ�����
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//���뵽��ʦ����Ӳ˵�
				teacherMenu(person);
				

				return;
			}
		}
	}
	else if (type == 3) {
		//����Ա�����֤
		string fName;//�ļ�����
		string fPwd;//�ļ�����
		while (ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fName == name && fPwd == pwd) {
				cout << "����Ա��֤��¼�ɹ���" << endl;
				person = new Manager(name, pwd);
				system("cls");
				//���뵽����Ա����Ӳ˵�
				managerMenu(person);

				return;
			}
		}
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}
int main() {

	//���ڽ����û���ѡ��
	int select = 0;


	while (true) {



		cout << "�������������" << endl;
		cout << "1.ѧ��" << endl;
		cout << "2.��ʦ" << endl;
		cout << "3.����Ա" << endl;
		cout << "0.�˳�" << endl;
		cout << "���������ѡ��" << endl;

		//�û�����ѡ��
		cin >> select;

		//�����û���ѡ��ʵ�ֲ�ͬ�Ľӿ�
		switch (select)
		{
			//ѧ��
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
			//��ʦ
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
			//����Ա
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
			//�˳�
		case 0:
			cout << "�����˳�..." << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;


		}




	}







	system("pause");
	return 0;
}
