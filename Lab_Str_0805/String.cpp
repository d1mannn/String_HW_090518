#include "String.h"
#include "Library.h"


String::String(const char *str)
{
	length = strlen(str);
	m_stringRep = new char[strlen(str) + 1];
	for (int i = 0; i < strlen(str); i++)
		m_stringRep[i] = str[i];
	m_stringRep[strlen(str)] = '\0';
}

String::String(size_t len, char s)
{
	length = len;
	m_stringRep = new char[len + 1];
	for (int i = 0; i < len; i++)
		m_stringRep[i] = s;
	m_stringRep[len] = '\0';
}

String::String(size_t len)
{
	length = len;
	m_stringRep = new char[len + 1];
	for (int i = 0; i < len; i++)
		m_stringRep[i] = 'w';
	m_stringRep[len] = '\0';
}


const char * String::getStrRep()
{
	return m_stringRep;
}

char & String::getAt(size_t pos)
{
	return m_stringRep[pos];
							 // TODO: insert return statement here
}

String & String::AddCharAt(size_t pos, char c)
{
	length += 2;
	char * temp = new char[length];
	for (int i = 0; i < pos; i++)
	{
		temp[i] = m_stringRep[i];
	}
	temp[pos] = c;
	for (int i = pos + 1; i < length; i++)
	{
		temp[i] = m_stringRep[i - 1];
	}
	delete[]m_stringRep;
	m_stringRep = new char[length + 1];
	if (m_stringRep == NULL)
	{
		cerr << "Error" << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < length; i++)
	{
		m_stringRep[i] = temp[i];
	}
	m_stringRep[length] = '\0';
	return *this;
	// TODO: insert return statement here
}

String & String::DelCharAt(size_t pos)
{
	char * temp = new char[length];
	for (int i = 0; i < pos; i++)
	{
		temp[i] = m_stringRep[i];
	}
	for (int i = pos + 1; i < length; i++)
	{
		temp[i - 1] = m_stringRep[i];
	}
	temp[length] = '\0';
	delete[]m_stringRep;
	m_stringRep = new char[length + 1];
	if (m_stringRep == NULL)
	{
		cerr << "Error" << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i <= length; i++)
	{
		m_stringRep[i] = temp[i];
	}
	//m_stringRep = temp;
	return *this;
	// TODO: insert return statement here
}

String & String::ConcatStr(const String & str)
{	
	length = length + strlen(str.m_stringRep) + 1;
	char * temp = new char[length];
	for (int i = 0; i < Length(); i++)
	{
		temp[i] = m_stringRep[i];
	}
	for (int i = Length(); i < length; i++)
	{
		temp[i] = str.m_stringRep[i - Length()];
	}
	delete[] m_stringRep;
	m_stringRep = new char[length + 2];
	if (m_stringRep == NULL)
	{
		cerr << "Error" << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < length; i++)
	{
		m_stringRep[i] = temp[i];
	}
	m_stringRep[length + 1] = '\0';
	// TODO: insert return statement here
	return *this;
}

String & String::ConcatStr(const char * str)
{	
	length = length + strlen(str) + 1;
	char * temp = new char[length];
	for (int i = 0; i < Length(); i++)
	{
		temp[i] = m_stringRep[i];
	}
	for (int i = Length(); i < length; i++)
	{
		temp[i] = str[i - Length()];
	}
	delete[] m_stringRep;
	m_stringRep = new char[length + 2];
	if (m_stringRep == NULL)
	{
		cerr << "Error" << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < length; i++)
	{
		m_stringRep[i] = temp[i];
	}
	m_stringRep[length + 1] = '\0';
	// TODO: insert return statement here
	return *this;
	// TODO: insert return statement here
}

String & String::AddStrAt(const String & str, size_t pos)
{	
	int length = strlen(str.m_stringRep) + Length();
	char * temp = new char[length];
	int count = 0;
	for (int i = 0; i < pos; i++)
	{
		temp[i] = m_stringRep[i];
	}
	int i = pos;
	while (count != strlen(str.m_stringRep))
	{
		temp[i] = str.m_stringRep[count];
		i++;
		count++;
	}
	count = pos;
	while (count != strlen(m_stringRep))
	{
		temp[i] = m_stringRep[count];
		i++;
		count++;
	}
	/*for (int i = pos; i < length; i++)
	{
		temp[i] = str.m_stringRep[i - pos];
	}*/
	/*for (int i = pos + strlen(str.m_stringRep); i < length; i++)
	{
		temp[i] = m_stringRep[i - pos - 1];
	}*/
	delete[]m_stringRep;
	m_stringRep = new char[length + 1];
	if (m_stringRep == NULL)
	{
		cerr << "Error" << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < length; i++)
	{
		m_stringRep[i] = temp[i];
	}
	m_stringRep[length] = '\0';
	// TODO: insert return statement here
	return *this;
}

String & String::AddStrAt(const char * str, size_t pos)
{	
	int length = strlen(str) + Length();
	char * temp = new char[length];
	int count = 0;
	for (int i = 0; i < pos; i++)
	{
		temp[i] = m_stringRep[i];
	}
	int i = pos;
	while (count != strlen(str))
	{
		temp[i] = str[count];
		i++;
		count++;
	}
	count = pos;
	while (count != strlen(m_stringRep))
	{
		temp[i] = m_stringRep[count];
		i++;
		count++;
	}
	/*for (int i = pos; i < length; i++)
	{
	temp[i] = str.m_stringRep[i - pos];
	}*/
	/*for (int i = pos + strlen(str.m_stringRep); i < length; i++)
	{
	temp[i] = m_stringRep[i - pos - 1];
	}*/
	delete[]m_stringRep;
	m_stringRep = new char[length + 1];
	if (m_stringRep == NULL)
	{
		cerr << "Error" << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < length; i++)
	{
		m_stringRep[i] = temp[i];
	}
	m_stringRep[length] = '\0';
	// TODO: insert return statement here
	return *this;
}

String & String::DelStrAt(size_t beg, size_t end)
{	
	char * temp = new char[length - (end - beg)];
	for (int i = 0; i < beg; i++)
	{
		temp[i] = m_stringRep[i];
	}
	int j = beg;
	for (int i = end + 1; i < length; i++)
	{
		temp[j] = m_stringRep[i];
		j++;
	}
	delete[]m_stringRep;
	length = j;
	m_stringRep = new char[length + 1];
	if (m_stringRep == NULL)
	{
		cerr << "Error" << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < length; i++)
	{
		m_stringRep[i] = temp[i];
	}
	m_stringRep[length] = '\0';
	// TODO: insert return statement here
}

size_t String::SubStr(const String & what)
{	
	int count = 0;
	int j = 0;
	for (int i = 0; i < Length(); i++)
	{
		if (m_stringRep[i] == what.m_stringRep[0])
			if (m_stringRep[i + 1] == what.m_stringRep[1])
				if (m_stringRep[i + 2] == what.m_stringRep[2])
					return i;
		/*{
			while (what.m_stringRep[j] != '\0')
			{
				if (m_stringRep[i] == what.m_stringRep[j])
					count++;
				j++;
				i++;
			}
			if (count == strlen(what.m_stringRep))
				return i - count;
		}*/
	}
	return 0;
}

size_t String::SubStr(const char * what)
{
	int count = 0;
	int j = 0;
	for (int i = 0; i < Length(); i++)
	{
		if (m_stringRep[i] == what[0])
			if (m_stringRep[i + 1] == what[1])
				if (m_stringRep[i + 2] == what[2])
					return i;
	}
	return 0;
}

size_t String::Length()
{
	return size_t(strlen(m_stringRep));
}

String::~String()
{
	delete[] m_stringRep;
}

void String::operator()(const char * str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		m_stringRep[i] = str[i];
	}
	m_stringRep[strlen(str)] = '\0';
}
