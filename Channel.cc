#include "Channel.h"
#include <cstdlib>

// Constructor
Channel::Channel(const string& t, const string& o)
  : title(t), owner(o) {}

// equals
bool Channel::equals(const string& t) const {
  return title == t;
}

// get
Media* Channel::get(int index) const {
  if (index < 0 || index >= media.getSize()) {
    cerr << "Channel get(): index out of bounds" << endl;
    exit(1);
  }
  return media[index];
}

// getSize
int Channel::getSize() const {
  return media.getSize();
}

// print
void Channel::print(ostream& ost) const {
  ost << "Channel: " << title << " | Owner: " << owner;
}

// printWithMedia
void Channel::printWithMedia(ostream& ost) const {
  print(ost);
  ost << endl;
  for (int i = 0; i < media.getSize(); ++i) {
    ost << "  " << *media[i] << endl;
  }
}

// add
void Channel::add(Media* m) {
  media += m;
}

// << operator
ostream& operator<<(ostream& ost, const Channel& c) {
  c.print(ost);
  return ost;
}
