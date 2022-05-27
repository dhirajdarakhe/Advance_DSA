// DHIRAJ LAXMAN DARAKHE
// 21118 (com)
// PICT, PUNE


#include <bits/stdc++.h>
using namespace std;
class HashEntry
{
    string name;
    string mobile_no;

public:
    HashEntry()
    {
        name = "none";
        mobile_no = "none";
    }
    friend class HashEntry1;
    friend class HashEntry2;
};
class HashEntry1
{
    int len;
    HashEntry *hash;

public:
    HashEntry1()
    {
        len = 10;
        hash = new HashEntry[len];
    }
    int location(string s1)
    {
        return s1[0] / 10;
    }
    void Insert(string s1, string s2)
    {
        if (find(s1))
        {
            cout << "\nDublicate Entry : ";
            return;
        }
        int index = location(s1);
        for (int i = 0; i < len; i++)
        {
            if (hash[(index + i) % len].name == "none")
            {
                hash[(index + i) % len].name = s1;
                hash[(index + i) % len].mobile_no = s2;
                return;
            }
            // cout << "\nEntry is added : ";
        }
        cout << "\nSorry , table is Fulled : ";
        return;
    }
    int find(string s)
    {
        int index = location(s);
        for (int i = 0; i < len; i++)
        {
            if (hash[(i + index) % len].name == "none")
            {
                return 0;
            }
            else if (hash[(i + index) % len].name == s)
            {
                return 1;
            }
        }
        return 0;
    }
    void Print()
    {
        cout << endl;
        for (int i = 0; i < len; i++)
        {
            cout << hash[i].name << " < - name  & mobile no - > " << hash[i].mobile_no << endl;
        }
        cout << endl;
    }
};
class HashEntry2
{
    HashEntry *hash;
    int len;

public:
    HashEntry2()
    {
        len = 10;
        hash = new HashEntry[len];
    }
    int location(string s)
    {
        return s[0] % 10;
    }
    void Insert(string s1, string s2)
    {
        if (find(s1) == 1)
        {   cout<<endl<<s1<<" "<<s2<<endl;
            cout << "\nDuplicate Entry : ";
            return;
        }
        int index = location(s1);
        if (hash[index].name == "none" || location(hash[index].name) == index)
        {
            for (int i = 0; i < len; ++i)
            {
                if (hash[(i + index) % len].name == "none")
                {
                    hash[(i + index) % len].name = s1;
                    hash[(i + index) % len].mobile_no = s2;
                    return;
                }
            }
            return;
        }
        else
        {
            string a1, a2;
            a1 = hash[index].name;
            a2 = hash[index].mobile_no;
            hash[index].name = s1;
            hash[index].mobile_no = s2;
            Insert(a1, a2);
        }
    }
    int find(string s)
    {
        int index = location(s);
        for (int i = 0; i < len; ++i)
        {
            if (hash[(i + index) % len].name == s)
            {
                return 1;
            }
            else if (hash[(i + index) % len].name == "none")
            {
                return 0;
            }
        }
        return 0;
    }
    void Print()
    {   cout<<endl;
        for (int i = 0; i < len; ++i)
        {
            cout<<i<<" ) "<<hash[i].name<<" "<<hash[i].mobile_no<<endl;
        }
    }
};
int main()
{
    HashEntry2 hs;
    hs.Insert("1", "20");
    hs.Insert("2", "70");
    hs.Insert("3", "80");
    hs.Insert("4", "25");
    hs.Insert("5", "44");
    hs.Insert("6", "32");
    hs.Insert("8", "11");
    hs.Insert("8", "78");
    hs.Insert("9", "98");
    hs.Print();
    return 0;
}