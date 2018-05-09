#include "Library.h"
#include "String.h"

int main()
{
	setlocale(LC_ALL, "");
	String s("Hello, my name is");
	String s3("Hello");
	String ss("12345");
	String s1(6, 'a');
	String s2(6);
	s2("HELLO");
	s2.getAt(0) = 'z';
	s2.AddCharAt(3, 'x');
	cout << s2.getStrRep() << endl;
	cout << s2.Length() << endl;
	s2.DelCharAt(3);
	s2.ConcatStr(s);
	cout << s2.getStrRep() << endl;
	s2.ConcatStr("asas");
	cout << s2.getStrRep() << endl;
	s2.AddStrAt(ss, 2);
	cout << s2.getStrRep() << endl;
	s2.AddStrAt("ZZZ", 6);
	cout << s2.getStrRep() << endl;
	s2.DelStrAt(3, 6);
	cout << s2.getStrRep() << endl;
	cout << s2.SubStr(s3) << endl;
	cout << s2.SubStr("name") << endl;
	system("pause");
	return 0;
}