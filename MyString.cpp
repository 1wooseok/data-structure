#include "MyString.h"
#include <cstring>
#include <cassert>
#include <iostream>

using namespace std;

MyString::MyString()
{
	str_ = nullptr;
	size_ = 0;
}

MyString::MyString(const char* init)
{
	size_ = 0;
	while (init[size_] != '\0')
	{
		++size_;
	}

	str_ = new char[size_];
	memcpy(str_, init, size_);
}

MyString::MyString(const MyString& str)
{
	size_ = str.size_;

	str_ = new char[size_];
	memcpy(str_, str.str_, size_);
}

bool MyString::IsEmpty()
{
	return size_ == 0;
}

bool MyString::IsEqual(const MyString& str)
{
	if (size_ != str.size_)
	{
		return false;
	}

	for (int i = 0; i < size_; ++i)
	{
		if (str_[i] != str.str_[i])
		{
			return false;
		}
	}

	return true;
}

int MyString::Length()
{
	return size_;
}

void MyString::Resize(const int new_size)
{
	char* temp = new char[new_size];
	int lesser = size_ < new_size ? size_ : new_size;
	memcpy(temp, str_, lesser);

	delete[] str_;
	str_ = temp;
	size_ = new_size;
}

MyString MyString::SubString(const int start, const int num)
{
	assert(start + num <= size_);

	MyString temp;
	temp.Resize(num);

	memcpy(temp.str_, &str_[start], num);

	return temp;
}

MyString MyString::Concat(MyString app_str)
{
	MyString temp;
	temp.Resize(size_ + app_str.size_);

	memcpy(temp.str_, str_, size_);
	memcpy(&temp.str_[size_], app_str.str_, app_str.size_);

	return temp;
}

MyString MyString::Insert(MyString t, int start)
{
	MyString temp;
	temp.Resize(size_ + t.size_);

	memcpy(temp.str_, str_, start);
	memcpy(&temp.str_[start], t.str_, t.size_);
	memcpy(&temp.str_[start + t.size_], &str_[start], size_ - start);

	return temp;
}

int MyString::Find(MyString pattern)
{
	const int range = size_ - pattern.Length() + 1;

	for (int i = 0; i < range; ++i)
	{
		for (int j = 0; j < pattern.Length(); ++j)
		{
			if (str_[i + j] != pattern.str_[j])
			{
				break;
			}

			if (j == (pattern.Length() - 1))
			{
				return i;
			}
		}
	}

	return -1;
}

void MyString::Print()
{
	for (int i = 0; i < size_; ++i)
	{
		cout << str_[i];
	}
}


MyString::~MyString()
{
	if (str_ != nullptr)
	{
		delete[] str_;

		str_ = nullptr;
		size_ = 0;
	}
}
