#include "Video.h"
#include <iostream>
#include <sstream>
using namespace std;

Video::Video(const string& url, const string& title, int& duration, const pair<int,int>& resolution, const string& director)
	: Media(url, title, duration), resolution(resolution), director(director) {}

string Video::display() const {
	ostringstream ss;
	ss << "Video" << "," << url << "," << title << "," << duration << ",N/A," << resolution.first << "x" << resolution.second << "," << director << "\n";

	return ss.str();
}