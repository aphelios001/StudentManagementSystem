#pragma once
#include<iostream>
#include<list>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;

class studentsystem//学生系统类(主要是声明要用的函数)
{
public://公共元素  //静态函数不需要实例化
    static void showmenu();//显示菜单
    static void choose();//选择函数
    static void appendstu();//添加学生函数
    static void showlist();//浏览学生函数
    static void searchstu();//查询学生函数
    static void exitsys();//退出系统函数
    static void deletestu();//删除学生函数
    static void modifystu();//修改学生函数
    static void sortstu();//学生排序函数
    static bool checkempty();//检查学生链表是否为空函数
    static bool addid(const string& id);//向id表添加id函数
    static void writefile();//文件输出函数
    static void readfile(const string& url);//文件读取函数
};

class student//学生类
{
    //声明友元函数,使其可访问私有元素
    friend void studentsystem::appendstu();
    friend void studentsystem::searchstu();
    friend void studentsystem::deletestu();
    friend void studentsystem::modifystu();
    friend void studentsystem::readfile(const std::string& url);
    friend bool cmp1(const student& a, const student& b);
    friend bool cmp2(const student& a, const student& b);
    friend bool cmp11(const student& a, const student& b);
    friend bool cmp22(const student& a, const student& b);
public://公共元素
    //重载运算符
    friend istream& operator>>(istream& cin, student& s)//重载>>,通过控制台输入
    {
        cin >> s._id >> s._name >> s._gender >> s._age >> s._classroom >> s._phone >> s._address;
        return cin;
    }
    friend ostream& operator<<(ostream& cout, student& s)//重载<<,通过控制台输出
    {
        cout << "学号:" << s._id << '\t' << "姓名:" << s._name << '\t' << "性别:" << s._gender << '\t' << "年龄:" << s._age << '\t' << "班级:" << s._classroom << '\t' << "电话:" << s._phone << "地址:" << s._address;
        return cout;
    }
    friend fstream& operator<<(fstream& out, student& s)//重载<<，通过文件输出
    {
        out << s._id << '\t' << s._name << '\t' << s._gender << '\t' << s._age << '\t' << s._classroom << '\t' << s._phone << '\t' << s._address << endl;
        return out;
    }
    friend fstream& operator>>(fstream& in, student& s)//重载>>，通过文件输入
    {
        in >> s._id >> s._name >> s._gender >> s._age >> s._classroom >> s._phone >> s._address;
        return in;
    }
private://私有元素，非友元不可访问
    string _id = {};
    string _name;
    string _gender;
    int _age = {};
    string _classroom;
    string _phone;
    string _address;
};

