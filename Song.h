
#ifndef SONG_H
#define SONG_H

#include "Media.h"

class Song : public Media {
private:
	string artist;

public:
	Song(const string& url, const string& title, int& duration, const string& artist);
	string display() const override;
	string getArtist() const;
};

#endif