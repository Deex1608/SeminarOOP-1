#include "Song.h"
#include <iostream>
#include <sstream>
using namespace std;

Song::Song(const string& url, const string& title, int& duration, const string& artist)
	: Media(url, title, duration), artist(artist) {}

string Song::display() const {
	ostringstream ss;
	//ss << "Song: " << title << " by " << artist << " (" << duration << "s) [" << url << "]\n";
	ss << "Song" << "," << url << "," << title << "," << duration << "," << artist << ",N/A,N/A\n";
	return ss.str();
}
string Song::getArtist() const {
	return artist;
}