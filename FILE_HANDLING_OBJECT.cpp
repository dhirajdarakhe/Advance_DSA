#include <iostream>
#include <fstream>
using namespace std;

class student
{
    int roll;
    char name[30];
    char division[30];
    char address[30];
    int deleteIndicator;

public:
    student() {}
    void getData();
    void deleteData(int key);
    int displayData();
    int searchData(int key);
};

void student ::getData()
{
    cout << "\nEnter Roll Number: ";
    cin >> roll;
    cin.ignore();
    cout << "\nEnter Name: ";
    cin.getline(name, 30);
    cout << "\nEnter Division: ";
    cin.getline(division, 30);
    cout << "\nEnter Address: ";
    cin.getline(address, 30);
    deleteIndicator = 0;
}

int student ::displayData()
{
    if (deleteIndicator == 1)
    {
        return 0;
    }
    cout << "\nRoll No. \tName \t Div \t Address \t Deleted?" << endl;
    cout << "\n"
         << roll << "\t\t" << name << "\t" << division << "\t" << address << "\t" << deleteIndicator << endl;
    return 1;
}

int student ::searchData(int key)
{
    if (deleteIndicator == 1)
    {
        return -1;
    }
    if (roll == key)
    {
        return 1;
    }
    return 0;
}

void student ::deleteData(int key)
{
    fstream fs;
    int flag = 0;
    int pos = 0;
    fs.open("dhira_39.txt", ios::in | ios::binary | ios::out);
    while (!fs.eof())
    {
        pos = fs.tellg();
        fs.read((char *)this, sizeof(student));
        if (fs)
            ;
        ;
        ;
        {
            if (deleteIndicator == 0 && roll == key)
            {
                flag = 1;
                deleteIndicator = 1;
                fs.seekp(pos);
                fs.write((char *)this, sizeof(student));
                break;
            }
        }
    }
    fs.close();
    if (flag == 1)
        cout << "\nRecord successfully deleted \n";
    else
        cout << "\nRecord not found \n";
}

int main()
{
    int stu_ct;
    cout << "\nEnter the number of student  : ";
    cin >> stu_ct;
    student s[stu_ct];
    fstream file;
    int i, choice;
    int res, key, flag;
    string option;
    student obj;

    do
    {
        cout << "\nEnter the choice: \n1. Write into file\n2. Read from file\n3. Search an entry\n4. Delete an entry\n Your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            file.open("dhira_39.txt", ios ::out | ios ::binary);
            for (i = 0; i < stu_ct; i++)
            {
                s[i].getData();
                file.write((char *)&s[i], sizeof(s[i]));
            }
            file.close();
            break;
        }
        case 2:
        {
            file.open("dhira_39.txt", ios ::in | ios::binary);
            for (i = 0; i < stu_ct; i++)
            {
                file.read((char *)&s[i], sizeof(s[i]));
                res = s[i].displayData();
            }
            file.close();
            break;
        }
        case 3:
        {
            cout << "Enter the roll number to search: ";
            cin >> key;
            flag = 0;
            file.open("dhira_39.txt", ios ::in | ios::binary);
            for (i = 0; i < stu_ct; i++)
            {
                file.read((char *)&s[i], sizeof(s[i]));
                res = s[i].searchData(key);
                if (res == 1)
                {
                    res = s[i].displayData();
                    flag = 1;
                    break;
                }
                else if (res == -1)
                {
                    cout << "Element was delelted"; // for deleted data
                    break;
                }
            }
            file.close();
            if (flag == 0)
            {
                cout << "Element not found"; // for those data which were not there
            }
            break;
        }
        case 4:
        {
            cout << "Enter the roll number to delete: ";
            cin >> key;
            flag = 0;
            obj.deleteData(key);
        }
        }
        cout << "\nDo you wish to continue? (y/n): ";
        cin >> option;
    } while (option == "Y" or option == "y");
    return 0;
}