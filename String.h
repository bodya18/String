#pragma once

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
		delete[] this->str;
		length = 0;
		str = 0;
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
private:
	char* str;
	int length;
};
