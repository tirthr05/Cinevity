#ifndef CHANNEL_H
#define CHANNEL_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Media.h"

using namespace std;

class Channel {
  public:
    Channel(const string& title, const string& owner);
    bool equals(const string& title) const;
    Media* get(int index) const;
    int getSize() const;
    void print(ostream& ost) const;
    void printWithMedia(ostream& ost) const;
    void add(Media* media);

    friend ostream& operator<<(ostream& ost, const Channel& c);

  private:
    Array<Media*> media;
    string title;
    string owner;
};

#endif
