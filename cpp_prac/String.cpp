#include "String.h"

String::String() : len(0)
{
	str=NULL;
}
		
String::String(const char *s)
{
	len=strlen(s)+1;
	str=new char[len];
	strcpy(str,s);
}

String::String(const String& s)
{
	len=s.len;
	str=new char[len];
	strcpy(str,s.str);
}
		
String::~String()
{
	if(str!=NULL) delete []str;
}

String& String::operator=(const String& s)
{
	len=s.len;
	if(str!=NULL) delete str;
	str=new char[len];
	strcpy(str,s.str);
	
	return *this;
}

String& String::operator+=(const String& s)
{
	len+=(s.len-1);
	char *tempstr = new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);
	
	if(str!=NULL) delete []str;
	str=tempstr;
	
	return *this;
}

bool String::operator==(const String& s)
{
	if(strcmp(str,s.str)!=0) return false;
	return true;
}

String String::operator+(const String& s)
{
	String temp(*this);
	temp+=s	;
	
	return temp;
}
		
ostream& operator<<(ostream& os, const String& s)
{
	os<<s.str;
	return os;
}

istream& operator>>(istream& is, String& s)
{
	char str[30];
	is>>str;
	s=String(str);
	
	return is;
}
