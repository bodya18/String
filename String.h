#pragma once
#define _CRT_SECURE_NO_WARNINGS
class String
{
public:
	String()
	{
		str = nullptr;
		length = 0;
	}
	String(const char* str)
	{
		length = strlen(str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
			this->str[i] = str[i];
		this->str[length] = '\0';
	}
	String(const String& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
			this->str[i] = other.str[i];
		this->str[length] = '\0';
	}
	~String()
	{
		clear();
	}
	void Print()
	{
		length = strlen(str);
		for (int i = 0; i < length; std::cout << str[i], i++);
		std::cout << std::endl;
	}
	String& operator =(const String& other)
	{
		if (this->str != nullptr)
			delete[] str;
		length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
			this->str[i] = other.str[i];
		this->str[length] = '\0';
		return *this;
	}
	String& operator =(const char *other)
	{
		length = strlen(other);
		if (this->str != nullptr)
			delete[] str;
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
			this->str[i] = other[i];
		this->str[length] = '\0';
		return *this;
	}
	String& operator +=(const String& other)
	{
		int newLength = length + other.length;
		char* newStr = new char[newLength + 1];
		int i = 0;
		for (; i < strlen(this->str); i++)
			newStr[i] = this->str[i];
		for (int j = 0; j < strlen(other.str); j++, i++)
			newStr[i] = other.str[j];
		newStr[newLength] = '\0';
		delete[] str;
		str = newStr;
		length = newLength;
		return *this;
	}
	String& operator +=(const char *other)
	{
		int newLength = length + strlen(other);
		char* newStr = new char[newLength + 1];
		int i = 0;
		for (; i < strlen(this->str); i++)
			newStr[i] = this->str[i];
		for (int j = 0; j < strlen(other); j++, i++)
			newStr[i] = other[j];
		newStr[newLength] = '\0';
		delete[] str;
		str = newStr;
		length = newLength;
		return *this;
	}
	int Length() { return length; }
	bool operator ==(const String& other)
	{
		if (this->length != other.length)
			return false;
		for (int i = 0; i < length; i++)
			if (this->str[i] != other.str[i])
				return false;
		return true;
	}
	bool operator !=(const String& other)
	{
		return !(this->operator ==(other));
	}
	char& operator [](int index) { return this->str[index]; }
	bool is_empty() { return (this->str == 0) || (str[0] == '\0'); }
	void clear()
	{
		delete[] this->str;
		length = 0;
		str = 0;
	}
	int find(const String& other, int pos = 0) //searches the first occurrence of the sequence
	{
		if (pos >= length||other.length > length)
			return -1;
		else
		{
			char *current = new char[other.length+1];
			for (int i = 0; i < other.length; i++)
				current[i] = str[pos + i];
			current[other.length] = '\0';
			for (int i = 0; i < length; i++)
			{
				int count = 0;
				for (int k = 0; k < other.length; k++)
				{
					if (current[k] == other.str[k])
						count++;
					if (count == other.length)
						return pos + i;
				}
				for (int j = 0; j < strlen(current); j++)
				{
					if (j == strlen(current) - 1)
						current[j] = str[pos + other.length + i];
					else
						current[j] = current[j + 1];
				}
			}
			return -1;	
		}
	}
	int find(const char* other, int pos = 0) //searches the first occurrence of the symbol
	{

	}
private:
	char* str;
	int length;
};