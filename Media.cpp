#include "Media.h"
#include<iostream>
using namespace std;

Media::Media(const string& url, const string& title, int& duration) 
	: url(url), title(title), duration(duration) {}

string Media::getTitle() const {
	return title;
}

string Media::getUrl() const {
	return url;
}

int Media::getDuration() const {
	return duration;
}
