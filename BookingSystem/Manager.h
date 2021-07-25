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


	//�вι���
	Manager(string name, string pwd);


	//�˵�����
	virtual void operMenu();


	//����˺�
	void addPerson();


	//�鿴�˺�
	void showPerson();


	//�鿴������Ϣ
	void showComputer();


	//���ԤԼ��¼
	void cleanFile();


	//����ظ� id���ѧ�Ż�ְ���� 2�������
	bool checkRepeat(int id, int type);

	//��ʼ������
	void initVector();


	//ѧ������
	vector<Student> vStu;


	//��ʦ����
	vector<Teacher> vTea;

	//������Ϣ����
	vector<ComputerRoom> vCom;

private:

};
