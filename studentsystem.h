#pragma once
#include<iostream>
#include<list>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;

class studentsystem//ѧ��ϵͳ��(��Ҫ������Ҫ�õĺ���)
{
public://����Ԫ��  //��̬��������Ҫʵ����
    static void showmenu();//��ʾ�˵�
    static void choose();//ѡ����
    static void appendstu();//���ѧ������
    static void showlist();//���ѧ������
    static void searchstu();//��ѯѧ������
    static void exitsys();//�˳�ϵͳ����
    static void deletestu();//ɾ��ѧ������
    static void modifystu();//�޸�ѧ������
    static void sortstu();//ѧ��������
    static bool checkempty();//���ѧ�������Ƿ�Ϊ�պ���
    static bool addid(const string& id);//��id�����id����
    static void writefile();//�ļ��������
    static void readfile(const string& url);//�ļ���ȡ����
};

class student//ѧ����
{
    //������Ԫ����,ʹ��ɷ���˽��Ԫ��
    friend void studentsystem::appendstu();
    friend void studentsystem::searchstu();
    friend void studentsystem::deletestu();
    friend void studentsystem::modifystu();
    friend void studentsystem::readfile(const std::string& url);
    friend bool cmp1(const student& a, const student& b);
    friend bool cmp2(const student& a, const student& b);
    friend bool cmp11(const student& a, const student& b);
    friend bool cmp22(const student& a, const student& b);
public://����Ԫ��
    //���������
    friend istream& operator>>(istream& cin, student& s)//����>>,ͨ������̨����
    {
        cin >> s._id >> s._name >> s._gender >> s._age >> s._classroom >> s._phone >> s._address;
        return cin;
    }
    friend ostream& operator<<(ostream& cout, student& s)//����<<,ͨ������̨���
    {
        cout << "ѧ��:" << s._id << '\t' << "����:" << s._name << '\t' << "�Ա�:" << s._gender << '\t' << "����:" << s._age << '\t' << "�༶:" << s._classroom << '\t' << "�绰:" << s._phone << "��ַ:" << s._address;
        return cout;
    }
    friend fstream& operator<<(fstream& out, student& s)//����<<��ͨ���ļ����
    {
        out << s._id << '\t' << s._name << '\t' << s._gender << '\t' << s._age << '\t' << s._classroom << '\t' << s._phone << '\t' << s._address << endl;
        return out;
    }
    friend fstream& operator>>(fstream& in, student& s)//����>>��ͨ���ļ�����
    {
        in >> s._id >> s._name >> s._gender >> s._age >> s._classroom >> s._phone >> s._address;
        return in;
    }
private://˽��Ԫ�أ�����Ԫ���ɷ���
    string _id = {};
    string _name;
    string _gender;
    int _age = {};
    string _classroom;
    string _phone;
    string _address;
};

