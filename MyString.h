#pragma once
class MyString
{
public:
	MyString();
	MyString(const char* init);
	MyString(const MyString& str);
	~MyString();

	bool IsEmpty();
	bool IsEqual(const MyString& str);
	int Length();
	void Resize(const int new_size);

	MyString SubString(const int start, const int num);
	MyString Concat(MyString app_str);
	MyString Insert(MyString t, int start);

	int Find(MyString patter);
	void Print();


private:
	int size_;
	char* str_;
};
