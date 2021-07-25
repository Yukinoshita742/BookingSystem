#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include"Identity.h"
#include "globalFile.h"
#include<fstream>
#include"Student.h"
#include"Teacher.h"
#include<algorithm>
#include"computerRoom.h"

class Manager :public Identity
{
public:
	Manager();


	//有参构造
	Manager(string name, string pwd);


	//菜单界面
	virtual void operMenu();


	//添加账号
	void addPerson();


	//查看账号
	void showPerson();


	//查看机房信息
	void showComputer();


	//清空预约记录
	void cleanFile();


	//检测重复 id检测学号或职工号 2检测类型
	bool checkRepeat(int id, int type);

	//初始化容器
	void initVector();


	//学生容器
	vector<Student> vStu;


	//教师容器
	vector<Teacher> vTea;

	//机房信息容器
	vector<ComputerRoom> vCom;

private:

};
