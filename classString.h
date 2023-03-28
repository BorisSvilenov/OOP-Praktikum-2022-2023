
#ifndef classString.h
#define classString.h

class String {
private:
	char* str;

public:
	void setString(const char* str);
	void resize();

	String();
	String(const char* str);
	String(String const& other);
	String& operator=(String const& other);
	~String();

	String(String&& other);
	String& operator=(String&& other);

	String& operator+=(String const& other);
	String& operator+=(const char* str);
	String& operator+(String const& other);


};
	


#endif // !"String.h"

