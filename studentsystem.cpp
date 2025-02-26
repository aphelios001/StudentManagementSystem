#include"studentsystem.h"
//���ļ����ں�������
vector <string> ids;//������ѧ��
list <student> studentlist;//ѧ�������ʼ��
list <student>& stul = studentlist;//������ ��
void studentsystem::showmenu()//չʾ�˵�
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t�q�����������������������r\t\t" << endl;
    cout << "\t| 1.¼��ѧ��|\t\t" << endl;
    cout << "\t| 2.���ѧ��|\t\t" << endl;
    cout << "\t| 3.����ѧ��|\t\t" << endl;
    cout << "\t| 4.ɾ��ѧ��|\t\t" << endl;
    cout << "\t| 5.ѧ���޸�|\t\t" << endl;
    cout << "\t| 6.ѧ������|\t\t" << endl;
    cout << "\t| 7.�ļ����|\t\t" << endl;
    cout << "\t| 8.�˳�ϵͳ|\t\t" << endl;
    cout << "\t�t�����������������������s\t\t" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}

void studentsystem::choose()//ѡ��
{
   
    cout << "���������ѡ��:" << endl;
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
        cout << "�����˴�������֣�����������" << endl;
        system("pause");
        system("cls");
        showmenu();
        choose();
        break;
    }
}
void studentsystem::appendstu()//���ѧ��
{
    cout << "��ѡ����¼��ѧ��" << endl;
    int n;
    cout << "1.ͨ���ļ����ѧ��" << endl;
    cout << "2.ͨ�������������ѧ��" << endl;
    cout << "3.����" << endl;
    cin >> n;
    system("cls");
    if (n == 1)
    {
        cout << "��ѡ��ͨ���ļ����ѧ��" << endl;
        cout << "ע��:�뽫��Ҫ��ӵ�ѧ�����ݰ���ȷ�ĸ�ʽ���뵽Ŀ��txt�ı���!" << endl;
        cout << "����ᷢ������!�뱣֤�ļ�·����ȷ!" << endl;
        cout << "�������ļ�·��:" << endl;
        string filepath;
        cin >> filepath;
        readfile(filepath);
        return;
    }
    if (n == 3)
    {
        return;
    }
    cout << "��ѡ������������ѧ��" << endl;
    int choice;
    cout << "1.�������ѧ��" << endl;
    cout << "2.��ӵ���ѧ��" << endl;
    cin >> choice;
    system("cls");
    if (choice == 1)
    {
        int num = {};
        cout << "������Ҫ�������ѧ��������:" << endl;
        cin >> num;
        int total = num;//��¼�������ѧ��������
        while (num < 0)
        {
            cout << "�������������Ϊ����!" << endl;
            cout << "����������:" << endl;
            cin >> num;
        }
        if (num == 0)//���������ӵ�ѧ��Ϊ0
        {
            cout << "һ�������0λѧ��" << endl;
            return;
        }
        int cnt = 0;
        while (num--)
        {
            cnt++;
            cout << "��ǰ������ǵ�" << cnt << "λѧ������Ϣ" << endl;
            cout << "����������ѧ����ѧ�ţ��������Ա����䣬�༶���绰����ַ����������Ԫ���м����ÿո����:" << endl;
            student newstu;
            cin >> newstu;
            while (!addid(newstu._id))
            {
                cout << "��ǰ������ǵ�" << cnt << "λѧ������Ϣ" << endl;
                cout << "����������ѧ����ѧ�ţ��������Ա����䣬�༶���绰����ַ�����⣬����Ԫ���м����ÿո����:" << endl;
                cin >> newstu;
            }
            studentlist.push_back(newstu);//list��push_back����
            cout << "��" << cnt << "λѧ����ӳɹ�" << endl;
        }
        cout << "һ�������" << total << "λѧ��" << endl;

    }
    else if (choice == 2)
    {
        cout << "����������ѧ����ѧ�ţ��������Ա����䣬�༶���绰����ַ����������Ԫ���м����ÿո����:" << endl;
        student newstu;
        cin >> newstu;
        while (!addid(newstu._id))
        {
            cout << "����������ѧ����ѧ�ţ��������Ա����䣬�༶���绰����ַ����������Ԫ���м����ÿո����:" << endl;
            cin >> newstu;
        }
        studentlist.push_back(newstu);//list��push_back����
        cout << "��ӳɹ�" << endl;
    }
    else//��������
    {
        cout << "�����˴�������֣�����������:" << endl;
        appendstu();
        return;
    }
}
void studentsystem::showlist()//��ӡ����
{
    if (checkempty())//���ж��Ƿ�Ϊ��
    {
        return;
    }
    else
    {
        for (auto it = studentlist.begin(); it != studentlist.end(); it++)//�õ�����������ӡ
        {
            cout << *it << endl;
        }
        return;
    }
}
void studentsystem::searchstu()//����ѧ��
{
    cout << "��ѡ���˲���ѧ��" << endl;
    if (checkempty())//�ж������Ƿ�Ϊ��
    {
        return;
    }
    cout << "1.��ѧ�Ų���ѧ��" << endl;
    cout << "2.����������ѧ��" << endl;
    cout << "3.����" << endl;
    int choice = {};
    cin >> choice;
    system("cls");
    if (choice == 1)
    {
        cout << "������Ҫ���ҵ�ѧ��:" << endl;
        string id;
        cin >> id;
        system("cls");
        for (auto it = studentlist.begin(); it != studentlist.end(); it++)//��������������
        {
            if (it->_id == id)
            {
                cout << "���ҳɹ�" << endl;
                cout << *it << endl;
                return;//��Ϊѧ��Ψһ���ҵ���return
            }
        }
        cout << "û���ҵ���ѧ��" << endl;
        return;
    }
    else if (choice == 2)
    {
        cout << "������Ҫ���ҵ�����:" << endl;
        string name;
        cin >> name;
        bool flag = false;
        for (auto it = studentlist.begin(); it != studentlist.end(); it++)//��������������
        {
            if (it->_name == name)
            {
                flag = true;
                cout << *it << endl;//���ֲ�Ψһ����return
            }
        }
        if (!flag)
            cout << "û���ҵ�������" << endl;
        return;
    }
    else if (choice == 3)
    {
        return;
    }
    else
    {
        cout << "�����˴�������֣�����������:" << endl;
        searchstu();
        return;
    }
}
bool studentsystem::checkempty()//��������Ƿ�Ϊ��
{
    if (stul.empty())
    {
        cout << "��ǰϵͳû�м�¼ѧ���������ѧ��!" << endl;
        return true;//�գ�����true
    }
    return false;//���գ�����false
}
void studentsystem::deletestu()//ɾ��ѧ��
{
    cout << "��ѡ����ɾ��ѧ��" << endl;
    if (checkempty())//�ж������Ƿ�Ϊ��
    {
        return;
    }
    cout << "1.��ѧ��ɾ��ѧ��" << endl;
    cout << "2.������ɾ��ѧ��" << endl;
    cout << "3.����" << endl;
    int choice = {};
    cin >> choice;
    system("cls");
    if (choice == 1)
    {
        cout << "������Ҫɾ����ѧ��:" << endl;
        string id;
        cin >> id;
        for (auto it = stul.begin(); it != stul.end(); it++)//��������������
        {
            if (it->_id == id)
            {
                stul.erase(it);////list��erase����
                cout << "ɾ���ɹ�" << endl;
                return;//ѧ��Ψһ��ֱ��return
            }
        }
        cout << "û���ҵ���ѧ��" << endl;
        return;
    }
    else if (choice == 2)
    {
        cout << "������Ҫɾ��������:" << endl;
        string name;
        cin >> name;
        bool flag = false;

        for (auto it = stul.begin(); it != stul.end(); it++)
        {
            if (it->_name == name)
            {
                flag = true;
                cout << *it << endl;//���ֲ�Ψһ����return�������˼·���ȴ�ӡͬ��ѧ����Ϣ���û�ѡ���Ӧ��ѧ��������ɾ��
            }
        }

        if (!flag)
        {
            cout << "û���ҵ�������" << endl;
            return;
        }

        cout << "��ѯ������ѧ��������������Ҫɾ����ѧ����ѧ��:" << endl;
        //��ֹ����ͬѧ
        while (true)
        {
            string id;
            cin >> id;
            for (auto it = stul.begin(); it != stul.end(); it++)//������������������
            {
                if (it->_id == id)
                {
                    stul.erase(it);//list��erase����
                    cout << "ɾ���ɹ�" << endl;
                    return;
                }
            }
            cout << "û���ҵ���ѧ�ţ���������������Ҫɾ��ѧ����ѧ��" << endl;
        }
    }
    else if (choice == 3)
    {
        return;
    }
    else
    {
        cout << "�����˴�������֣�����������:" << endl;
        deletestu();
        return;
    }
}
void studentsystem::modifystu()//�޸�ѧ����Ϣ
{
    cout << "��ѡ�����޸�ѧ��" << endl;
    if (checkempty())
    {
        return;
    }
    cout << "������Ҫ�޸�ѧ����ѧ��:" << endl;
    string id;
    cin >> id;
    system("cls");
    auto found_it = stul.end();//��������ʼ�������ڱ���״̬
    for (auto it = stul.begin(); it != stul.end(); it++)//��������������
    {
        if (it->_id == id)
        {
            found_it = it;//���浱ǰ���������ڵĵ�ַ����ֵ��found_it;
            cout << "��ѯ����ѧ������Ϣ:" << endl;
            cout << *it << endl;
            break;
        }
    }
    if (found_it == stul.end())//found_itû�䣬˵��û�ҵ��������ҵ��ˣ����Խ�����һ��
    {
        cout << "û���ҵ���ѧ��" << endl;
        return;
    }
    cout << "��������Ҫ�޸ĵ���Ϣ:" << endl;
    cout << "1.����" << endl;
    cout << "2.�Ա�" << endl;
    cout << "3.����" << endl;
    cout << "4.�༶" << endl;
    cout << "5.�绰" << endl;
    cout << "6.��ַ" << endl;
    cout << "7.����(���޸�)" << endl;
    int choice = {};
    cin >> choice;
    system("cls");
    if (choice == 1)
    {
        cout << "�������޸ĺ������:" << endl;
        string name;
        cin >> name;
        found_it->_name = name;//found_it�����������˵�ַ��ֱ�Ӹ�ֵ
        cout << "�޸������ɹ�" << endl;
    }
    else if (choice == 2)
    {
        cout << "�������޸ĺ���Ա�:" << endl;
        string gender;
        cin >> gender;
        found_it->_gender = gender;
        cout << "�޸��Ա�ɹ�" << endl;
    }
    else if (choice == 3)
    {
        cout << "�������޸ĺ������:" << endl;
        int age;
        cin >> age;
        found_it->_age = age;
        cout << "�޸�����ɹ�" << endl;
    }
    else if (choice == 4)
    {
        cout << "�������޸ĺ�İ༶:" << endl;
        string classroom;
        cin >> classroom;
        found_it->_classroom = classroom;
        cout << "�޸İ༶�ɹ�" << endl;
    }
    else if (choice == 5)
    {
        cout << "�������޸ĺ�ĵ绰:" << endl;
        string phone;
        cin >> phone;
        found_it->_phone = phone;
        cout << "�޸ĵ绰�ɹ�" << endl;
    }
    else if (choice == 6)
    {
        cout << "�������޸ĺ�ĵ�ַ:" << endl;
        string address;
        cin >> address;
        found_it->_address = address;
        cout << "�޸ĵ�ַ�ɹ�" << endl;
    }
    else if (choice == 7)
    {
        return;
    }
    else
    {
        cout << "�����˴�������֣�����������:" << endl;
        modifystu();
        return;
    }
}

bool cmp1(const student& a, const student& b)//sort�Զ���������򣬰�ѧ����������
{
    return a._id < b._id;
}
bool cmp11(const student& a, const student& b)//�Զ���������򣬰�ѧ�����򣬽���
{
    return a._id > b._id;
}
bool cmp2(const student& a, const student& b)//�Զ���������򣬰�������������
{
    return a._age < b._age;
}
bool cmp22(const student& a, const student& b)//�Զ���������򣬰��������򣬽���
{
    return a._age > b._age;
}

void studentsystem::sortstu()//ѧ������
{
    cout << "��ѡ����ѧ������" << endl;
    if (checkempty())//�ȼ���Ƿ�Ϊ������
    {
        return;
    }
    else
    {
        cout << "1.��ѧ������(����)" << endl;
        cout << "2.��ѧ������(����)" << endl;
        cout << "3.����������(����)" << endl;
        cout << "4.����������(����)" << endl;
        cout << "5.����" << endl;
        int choice = {};
        cin >> choice;
        if (choice == 1)
        {
            studentlist.sort(cmp1);
            cout << "��ѧ������(����)�ɹ�!" << endl;
            return;
        }
        else if (choice == 2)
        {
            studentlist.sort(cmp11);
            cout << "��ѧ������(����)�ɹ�" << endl;
            return;
        }
        else if (choice == 3)
        {
            studentlist.sort(cmp2);
            cout << "����������(����)�ɹ�" << endl;
            return;
        }
        else if (choice == 4)
        {
            studentlist.sort(cmp22);
            cout << "����������(����)�ɹ�" << endl;
            return;
        }
        else if (choice == 5)
        {
            return;
        }
        else
        {
            cout << "�����˴�������֣�����������:" << endl;
            sortstu();
            return;
        }
    }
}
bool studentsystem::addid(const string& id)//��id�����ѧ���Ƿ��ظ�����֤ѧ��Ψһ
//��˼·�ǰ������ѧ�Ŵ��������У�ÿ������ѧ��ʱ�������飬����Ƿ����ظ�ѧ�ţ�
//�����������unordered_map��map���Ż�ʱ�临�Ӷ�(?)��.
{
    if (!ids.empty())//����id�����鲻Ϊ��
    {
        for (auto it = ids.begin(); it != ids.end(); it++)//������������������
        {
            if (id == *it)
            {
                cout << "ϵͳ���Ѵ��ڴ�ѧ����ѧ�ţ����������������" << endl;
                return false;//���ظ�ѧ�ţ�����false
            }
        }
    }
    ids.push_back(id);
    return true;//û���ظ�ѧ�ţ�����true
}
void studentsystem::readfile(const string& url)//��ȡ�ļ�
{
    fstream file(url, ios::in);//������
    if (!file)
    {
        cout << "�ļ���ʧ��!" << endl;
        return;
    }
    else
    {
        student newstu;
        while (true)
        {
            file >> newstu;
            if (file.eof())//�ж��ļ���β
            {
                break;
            }
            if (!addid(newstu._id))//����Ƿ����ظ�ѧ�ų���
            {
                cout << "�ļ������ظ�ѧ�ų��֣����޸ĺ���ͨ���ļ����룡" << endl;
                cout << "ͨ���ļ�����ʧ�ܣ�" << endl;
                return;
            }
            stul.push_back(newstu);
        }
        file.close();//�ر��ļ�
        cout << "ͨ���ļ���ӳɹ�!" << endl;
    }

}
void studentsystem::writefile()//�ļ����
{
    cout << "��ѡ�����ļ����" << endl;
    if (checkempty())
    {
        return;
    }   
    cout << "���������Ŀ���ļ���ַ(������׺��.txt):" << endl;
    string url;//Ŀ���ַ
    cin >> url;
    fstream file(url, ios::out);//�����
    for (auto it = stul.begin(); it != stul.end(); it++)
    {
        file << *it;
    }
    file.close();
    cout << "�ļ�����ɹ�,������ļ���·��Ϊ:" << url << endl;
    cout << "��ֻ���ļ���������ļ�·��Ĭ�ϵ�ַΪ��Ŀ���ڵ�ַ��" << endl;

}
void studentsystem::exitsys()//�˳�ϵͳ
{
    cout << "�˳��ɹ�" << '\n';
    exit(0);//�˳�����
}