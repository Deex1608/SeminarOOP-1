#ifndef VIDEO_H
#define VIDEO_H

#include "Media.h"

class Video : public Media {
private:
	std::pair<int,int> resolution;
	string director;

public:
	Video(const string& url, const string& title, int& duration, const pair<int,int>& resolution, const string& director);
	string display() const override;

};
#endif