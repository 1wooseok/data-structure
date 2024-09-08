#include <iostream>
#include <assert.h>
#include "MyString.h"

using namespace std;

int MyStringTest()
{
    {
        MyString str1("Hello world!!");
        str1.Print();
    }
    // Find
    {
        cout << "Find" << endl;
        assert(MyString("Hi, Hello World!").Find("Hell") == 4);
        assert(MyString("ABCDEF").Find("A") == 0);
        assert(MyString("ABCDEF").Find("AB") == 0);
        assert(MyString("ABCDEF").Find("CDE") == 2);
        assert(MyString("ABCDEF").Find("EF") == 4);
        assert(MyString("ABCDEF").Find("EFG") == -1);
        assert(MyString("ABCDEF").Find("EFGHIJ") == -1);
    }
    // copy constructor
    {
        cout << "copy constructor" << endl;
        MyString str1("Hello World 2!!");
        MyString str2 = str1;
        str2.Print();
    }
    // IsEqual
    {
        cout << "IsEqual" << endl;
        MyString str3("Hello, World!");
        assert(str3.IsEqual("Hello, World!"));
        assert(str3.IsEqual("Hello, world!") == false);
    }
    // Insert
    {
        cout << "Insert" << endl;
        MyString str4("ABCD");
        for (int i = 0; i < str4.Length(); ++i)
        {
            MyString str5 = str4.Insert("123", i);
            str5.Print();
        }
    }
    // SubString
    {
        cout << "SubString" << endl;
        MyString str("ABCDEFGHIJ");
        assert(str.SubString(3, 4).IsEqual("DEFG"));
    }
    // Concat
    {
        cout << "Concat" << endl;
        MyString str1("Hello, ");
        MyString str2("World!");
        MyString str3 = str1.Concat(str2);
        assert(str3.IsEqual("Hello, World!"));
    }
    return 0;
}