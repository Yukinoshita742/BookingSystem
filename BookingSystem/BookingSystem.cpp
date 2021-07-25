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


//进入老师的子菜单界面
void teacherMenu(Identity*& teacher) {
	while (true) {
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2) {
			//审核预约
			tea->validOrder();
		}
		else{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入学生的子菜单界面
void studentMenu(Identity*& student) {
	while (true) {
		//调用学生子菜单
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;

		if (select == 1) {
			//申请预约
			stu->applyOrder();
		}
		else if (select == 2) {
			//查看自身预约
			stu->showMyOrder();
		}
		else if (select == 3) {
			//查看所有人预约
			stu->showAllOrder();
		}
		else if (select == 4) {
			//取消预约
			stu->cancelOrder();
		}
		else {
			//注销登录
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		
	}
}


//进入管理员的子菜单界面
void managerMenu(Identity*& manager) {
	while (true) {
		//调用管理员子菜单
		manager->operMenu();

		//将父类的指针转为子类指针，调用子类其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接受用户选项
		cin >> select;

		//添加账号
		if (select == 1) {
			//cout << "添加账号" << endl;
			man->addPerson();
		}
		//查看账号
		else if (select == 2) {
			//cout << "查看账号" << endl;
			man->showPerson();
		}
		//查看机房
		else if (select == 3) {
			//cout << "查看机房" << endl;
			man->showComputer();
		}
		//清空预约
		else if (select == 4) {
			//cout << "清空预约" << endl;
			man->cleanFile();
		}
		//注销
		else {
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}



//登录功能
void LoginIn(string fileName, int type) {
	//父类指针 指向子类对象
	Identity* person = nullptr;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1) {//学生身份
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1) {
		//学生身份验证
		int fId;//从文件中读取的id
		string fName;//文件姓名
		string fPwd;//文件密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入到学生身份子菜单
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2) {
		//教师身份验证
		int fId;//从文件中读取的id
		string fName;//文件姓名
		string fPwd;//文件密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入到教师身份子菜单
				teacherMenu(person);
				

				return;
			}
		}
	}
	else if (type == 3) {
		//管理员身份验证
		string fName;//文件姓名
		string fPwd;//文件密码
		while (ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做对比
			if (fName == name && fPwd == pwd) {
				cout << "管理员验证登录成功！" << endl;
				person = new Manager(name, pwd);
				system("cls");
				//进入到管理员身份子菜单
				managerMenu(person);

				return;
			}
		}
	}
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
}
int main() {

	//用于接受用户的选择
	int select = 0;


	while (true) {



		cout << "请输入您的身份" << endl;
		cout << "1.学生" << endl;
		cout << "2.老师" << endl;
		cout << "3.管理员" << endl;
		cout << "0.退出" << endl;
		cout << "请输入你的选择" << endl;

		//用户输入选择
		cin >> select;

		//根据用户的选择实现不同的接口
		switch (select)
		{
			//学生
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
			//老师
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
			//管理员
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
			//退出
		case 0:
			cout << "正在退出..." << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误请重新选择！" << endl;
			system("pause");
			system("cls");
			break;


		}




	}







	system("pause");
	return 0;
}
