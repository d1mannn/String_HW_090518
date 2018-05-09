#pragma once
#include "Library.h"
class String
{
public:
	String(const char *str);
	String(size_t len, char s);
	String(size_t len);

	const char* getStrRep();
	char &getAt(size_t pos);
	String& AddCharAt(size_t pos, char c);
	String& DelCharAt(size_t pos);
	String& ConcatStr(const String& str);
	String& ConcatStr(const char* str);
	String& AddStrAt(const String& str, size_t pos);
	String& AddStrAt(const char* str, size_t pos);
	String& DelStrAt(size_t beg, size_t end);
	size_t SubStr(const String& what);
	size_t SubStr(const char* what);
	size_t Length();
	~String();


	void operator()(const char *str);
private:
	char *m_stringRep;
	size_t length;
};

