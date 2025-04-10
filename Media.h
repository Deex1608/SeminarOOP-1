
#ifndef MEDIA_H
#define MEDIA_H

#include<string>
using namespace std;

class Media {
protected:
	string url;
	string title;
	int duration;

public:
	Media(const string& url, const string& title, int& duration);
	virtual string display() const = 0;
	virtual ~Media()=default;
	string getTitle() const;
	string getUrl() const;
	int getDuration() const;
};

#endif