#include"studentsystem.h"
//本文件用于函数定义
vector <string> ids;//用来存学号
list <student> studentlist;//学生链表初始化
list <student>& stul = studentlist;//用引用 简化
void studentsystem::showmenu()//展示菜单
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t╭───────────╮\t\t" << endl;
    cout << "\t| 1.录入学生|\t\t" << endl;
    cout << "\t| 2.浏览学生|\t\t" << endl;
    cout << "\t| 3.查找学生|\t\t" << endl;
    cout << "\t| 4.删除学生|\t\t" << endl;
    cout << "\t| 5.学生修改|\t\t" << endl;
    cout << "\t| 6.学生排序|\t\t" << endl;
    cout << "\t| 7.文件输出|\t\t" << endl;
    cout << "\t| 8.退出系统|\t\t" << endl;
    cout << "\t╰───────────╯\t\t" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}

void studentsystem::choose()//选择
{
   
    cout << "请输入你的选择:" << endl;
    int choice = {};
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        appendstu();
        system("pause");
        system("cls");
        showmenu();
        choose();
        break;
    case 2:
        system("cls");
        showlist();
        system("pause");
        system("cls");
        showmenu();
        choose();
        break;
    case 3:
        system("cls");
        searchstu();
        system("pause");
        system("cls");
        showmenu();
        choose();
        break;
    case 4:
        system("cls");
        deletestu();
        system("pause");
        system("cls");
        showmenu();
        choose();
        break;
    case 5:
        system("cls");
        modifystu();
        system("pause");
        system("cls");
        showmenu();
        choose();
        break;
    case 6:
        system("cls");
        sortstu();
        system("pause");
        system("cls");
        showmenu();
        choose();
        break;
    case 7:
        system("cls");
        writefile();
        system("pause");
        system("cls");
        showmenu();
        choose();
        break;
    case 8:
        system("cls");
        exitsys();
        break;
    default:
        system("cls");
        cout << "输入了错误的数字，请重新输入" << endl;
        system("pause");
        system("cls");
        showmenu();
        choose();
        break;
    }
}
void studentsystem::appendstu()//添加学生
{
    cout << "你选择了录入学生" << endl;
    int n;
    cout << "1.通过文件添加学生" << endl;
    cout << "2.通过键盘输入添加学生" << endl;
    cout << "3.返回" << endl;
    cin >> n;
    system("cls");
    if (n == 1)
    {
        cout << "你选择通过文件添加学生" << endl;
        cout << "注意:请将需要添加的学生数据按正确的格式输入到目标txt文本中!" << endl;
        cout << "否则会发生错误!请保证文件路径正确!" << endl;
        cout << "请输入文件路径:" << endl;
        string filepath;
        cin >> filepath;
        readfile(filepath);
        return;
    }
    if (n == 3)
    {
        return;
    }
    cout << "你选择键盘输入添加学生" << endl;
    int choice;
    cout << "1.批量添加学生" << endl;
    cout << "2.添加单个学生" << endl;
    cin >> choice;
    system("cls");
    if (choice == 1)
    {
        int num = {};
        cout << "请输入要批量添加学生的数量:" << endl;
        cin >> num;
        int total = num;//记录批量添加学生总数量
        while (num < 0)
        {
            cout << "输入的数量不能为负数!" << endl;
            cout << "请重新输入:" << endl;
            cin >> num;
        }
        if (num == 0)//如果批量添加的学生为0
        {
            cout << "一共添加了0位学生" << endl;
            return;
        }
        int cnt = 0;
        while (num--)
        {
            cnt++;
            cout << "当前输入的是第" << cnt << "位学生的信息" << endl;
            cout << "请依次输入学生的学号，姓名，性别，年龄，班级，电话，地址，任意两个元素中间请用空格隔开:" << endl;
            student newstu;
            cin >> newstu;
            while (!addid(newstu._id))
            {
                cout << "当前输入的是第" << cnt << "位学生的信息" << endl;
                cout << "请依次输入学生的学号，姓名，性别，年龄，班级，电话，地址，任意，两个元素中间请用空格隔开:" << endl;
                cin >> newstu;
            }
            studentlist.push_back(newstu);//list的push_back函数
            cout << "第" << cnt << "位学生添加成功" << endl;
        }
        cout << "一共添加了" << total << "位学生" << endl;

    }
    else if (choice == 2)
    {
        cout << "请依次输入学生的学号，姓名，性别，年龄，班级，电话，地址，任意两个元素中间请用空格隔开:" << endl;
        student newstu;
        cin >> newstu;
        while (!addid(newstu._id))
        {
            cout << "请依次输入学生的学号，姓名，性别，年龄，班级，电话，地址，任意两个元素中间请用空格隔开:" << endl;
            cin >> newstu;
        }
        studentlist.push_back(newstu);//list的push_back函数
        cout << "添加成功" << endl;
    }
    else//错误提醒
    {
        cout << "输入了错误的数字，请重新输入:" << endl;
        appendstu();
        return;
    }
}
void studentsystem::showlist()//打印链表
{
    if (checkempty())//先判断是否为空
    {
        return;
    }
    else
    {
        for (auto it = studentlist.begin(); it != studentlist.end(); it++)//用迭代器遍历打印
        {
            cout << *it << endl;
        }
        return;
    }
}
void studentsystem::searchstu()//查找学生
{
    cout << "你选择了查找学生" << endl;
    if (checkempty())//判断链表是否为空
    {
        return;
    }
    cout << "1.按学号查找学生" << endl;
    cout << "2.按姓名查找学生" << endl;
    cout << "3.返回" << endl;
    int choice = {};
    cin >> choice;
    system("cls");
    if (choice == 1)
    {
        cout << "请输入要查找的学号:" << endl;
        string id;
        cin >> id;
        system("cls");
        for (auto it = studentlist.begin(); it != studentlist.end(); it++)//迭代器遍历搜索
        {
            if (it->_id == id)
            {
                cout << "查找成功" << endl;
                cout << *it << endl;
                return;//因为学号唯一，找到就return
            }
        }
        cout << "没有找到此学号" << endl;
        return;
    }
    else if (choice == 2)
    {
        cout << "请输入要查找的姓名:" << endl;
        string name;
        cin >> name;
        bool flag = false;
        for (auto it = studentlist.begin(); it != studentlist.end(); it++)//迭代器遍历搜索
        {
            if (it->_name == name)
            {
                flag = true;
                cout << *it << endl;//名字不唯一，不return
            }
        }
        if (!flag)
            cout << "没有找到此姓名" << endl;
        return;
    }
    else if (choice == 3)
    {
        return;
    }
    else
    {
        cout << "输入了错误的数字，请重新输入:" << endl;
        searchstu();
        return;
    }
}
bool studentsystem::checkempty()//检查链表是否为空
{
    if (stul.empty())
    {
        cout << "当前系统没有记录学生，请添加学生!" << endl;
        return true;//空，返回true
    }
    return false;//不空，返回false
}
void studentsystem::deletestu()//删除学生
{
    cout << "你选择了删除学生" << endl;
    if (checkempty())//判断链表是否为空
    {
        return;
    }
    cout << "1.按学号删除学生" << endl;
    cout << "2.按姓名删除学生" << endl;
    cout << "3.返回" << endl;
    int choice = {};
    cin >> choice;
    system("cls");
    if (choice == 1)
    {
        cout << "请输入要删除的学号:" << endl;
        string id;
        cin >> id;
        for (auto it = stul.begin(); it != stul.end(); it++)//迭代器遍历搜索
        {
            if (it->_id == id)
            {
                stul.erase(it);////list的erase函数
                cout << "删除成功" << endl;
                return;//学号唯一，直接return
            }
        }
        cout << "没有找到此学号" << endl;
        return;
    }
    else if (choice == 2)
    {
        cout << "请输入要删除的名字:" << endl;
        string name;
        cin >> name;
        bool flag = false;

        for (auto it = stul.begin(); it != stul.end(); it++)
        {
            if (it->_name == name)
            {
                flag = true;
                cout << *it << endl;//名字不唯一，不return，这里的思路是先打印同名学生信息让用户选择对应的学号来进行删除
            }
        }

        if (!flag)
        {
            cout << "没有找到该姓名" << endl;
            return;
        }

        cout << "查询到以上学生，请输入以上要删除的学生的学号:" << endl;
        //防止重名同学
        while (true)
        {
            string id;
            cin >> id;
            for (auto it = stul.begin(); it != stul.end(); it++)//迭代器遍历链表搜索
            {
                if (it->_id == id)
                {
                    stul.erase(it);//list的erase函数
                    cout << "删除成功" << endl;
                    return;
                }
            }
            cout << "没有找到此学号，请重新输入以上要删除学生的学号" << endl;
        }
    }
    else if (choice == 3)
    {
        return;
    }
    else
    {
        cout << "输入了错误的数字，请重新输入:" << endl;
        deletestu();
        return;
    }
}
void studentsystem::modifystu()//修改学生信息
{
    cout << "你选择了修改学生" << endl;
    if (checkempty())
    {
        return;
    }
    cout << "请输入要修改学生的学号:" << endl;
    string id;
    cin >> id;
    system("cls");
    auto found_it = stul.end();//迭代器初始化，用于保存状态
    for (auto it = stul.begin(); it != stul.end(); it++)//迭代器遍历搜索
    {
        if (it->_id == id)
        {
            found_it = it;//保存当前迭代器所在的地址，赋值给found_it;
            cout << "查询到该学生的信息:" << endl;
            cout << *it << endl;
            break;
        }
    }
    if (found_it == stul.end())//found_it没变，说明没找到，否则找到了，可以进行下一步
    {
        cout << "没有找到该学号" << endl;
        return;
    }
    cout << "请输入你要修改的信息:" << endl;
    cout << "1.姓名" << endl;
    cout << "2.性别" << endl;
    cout << "3.年龄" << endl;
    cout << "4.班级" << endl;
    cout << "5.电话" << endl;
    cout << "6.地址" << endl;
    cout << "7.返回(不修改)" << endl;
    int choice = {};
    cin >> choice;
    system("cls");
    if (choice == 1)
    {
        cout << "请输入修改后的姓名:" << endl;
        string name;
        cin >> name;
        found_it->_name = name;//found_it迭代器保存了地址，直接赋值
        cout << "修改姓名成功" << endl;
    }
    else if (choice == 2)
    {
        cout << "请输入修改后的性别:" << endl;
        string gender;
        cin >> gender;
        found_it->_gender = gender;
        cout << "修改性别成功" << endl;
    }
    else if (choice == 3)
    {
        cout << "请输入修改后的年龄:" << endl;
        int age;
        cin >> age;
        found_it->_age = age;
        cout << "修改年龄成功" << endl;
    }
    else if (choice == 4)
    {
        cout << "请输入修改后的班级:" << endl;
        string classroom;
        cin >> classroom;
        found_it->_classroom = classroom;
        cout << "修改班级成功" << endl;
    }
    else if (choice == 5)
    {
        cout << "请输入修改后的电话:" << endl;
        string phone;
        cin >> phone;
        found_it->_phone = phone;
        cout << "修改电话成功" << endl;
    }
    else if (choice == 6)
    {
        cout << "请输入修改后的地址:" << endl;
        string address;
        cin >> address;
        found_it->_address = address;
        cout << "修改地址成功" << endl;
    }
    else if (choice == 7)
    {
        return;
    }
    else
    {
        cout << "输入了错误的数字，请重新输入:" << endl;
        modifystu();
        return;
    }
}

bool cmp1(const student& a, const student& b)//sort自定义排序规则，按学号排序，升序
{
    return a._id < b._id;
}
bool cmp11(const student& a, const student& b)//自定义排序规则，按学号排序，降序
{
    return a._id > b._id;
}
bool cmp2(const student& a, const student& b)//自定义排序规则，按年龄排序，升序
{
    return a._age < b._age;
}
bool cmp22(const student& a, const student& b)//自定义排序规则，按年龄排序，降序
{
    return a._age > b._age;
}

void studentsystem::sortstu()//学生排序
{
    cout << "你选择了学生排序" << endl;
    if (checkempty())//先检查是否为空链表
    {
        return;
    }
    else
    {
        cout << "1.按学号排序(升序)" << endl;
        cout << "2.按学号排序(降序)" << endl;
        cout << "3.按年龄排序(升序)" << endl;
        cout << "4.按年龄排序(降序)" << endl;
        cout << "5.返回" << endl;
        int choice = {};
        cin >> choice;
        if (choice == 1)
        {
            studentlist.sort(cmp1);
            cout << "按学号排序(升序)成功!" << endl;
            return;
        }
        else if (choice == 2)
        {
            studentlist.sort(cmp11);
            cout << "按学号排序(降序)成功" << endl;
            return;
        }
        else if (choice == 3)
        {
            studentlist.sort(cmp2);
            cout << "按年龄排序(升序)成功" << endl;
            return;
        }
        else if (choice == 4)
        {
            studentlist.sort(cmp22);
            cout << "按年龄排序(降序)成功" << endl;
            return;
        }
        else if (choice == 5)
        {
            return;
        }
        else
        {
            cout << "输入了错误的数字，请重新输入:" << endl;
            sortstu();
            return;
        }
    }
}
bool studentsystem::addid(const string& id)//存id，检查学号是否重复，保证学号唯一
//（思路是把输入的学号存入数组中，每次输入学号时遍历数组，检查是否有重复学号）
//（这里可以用unordered_map或map来优化时间复杂度(?)）.
{
    if (!ids.empty())//若存id的数组不为空
    {
        for (auto it = ids.begin(); it != ids.end(); it++)//迭代器遍历链表搜索
        {
            if (id == *it)
            {
                cout << "系统中已存在此学生的学号，请检查后再重新输入" << endl;
                return false;//有重复学号，返回false
            }
        }
    }
    ids.push_back(id);
    return true;//没有重复学号，返回true
}
void studentsystem::readfile(const string& url)//读取文件
{
    fstream file(url, ios::in);//输入流
    if (!file)
    {
        cout << "文件打开失败!" << endl;
        return;
    }
    else
    {
        student newstu;
        while (true)
        {
            file >> newstu;
            if (file.eof())//判断文件结尾
            {
                break;
            }
            if (!addid(newstu._id))//检查是否有重复学号出现
            {
                cout << "文件中有重复学号出现，请修改后再通过文件输入！" << endl;
                cout << "通过文件输入失败！" << endl;
                return;
            }
            stul.push_back(newstu);
        }
        file.close();//关闭文件
        cout << "通过文件添加成功!" << endl;
    }

}
void studentsystem::writefile()//文件输出
{
    cout << "你选择了文件输出" << endl;
    if (checkempty())
    {
        return;
    }   
    cout << "请输入输出目标文件地址(包含后缀名.txt):" << endl;
    string url;//目标地址
    cin >> url;
    fstream file(url, ios::out);//输出流
    for (auto it = stul.begin(); it != stul.end(); it++)
    {
        file << *it;
    }
    file.close();
    cout << "文件输出成功,输出的文件的路径为:" << url << endl;
    cout << "如只有文件名，输出文件路径默认地址为项目所在地址！" << endl;

}
void studentsystem::exitsys()//退出系统
{
    cout << "退出成功" << '\n';
    exit(0);//退出程序
}