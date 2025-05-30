#include "Search.h"
#include "Media.h"

// O_Search Implementation
O_Search::O_Search(const string& o) : owner(o) {}

bool O_Search::matches(const Media* media) const {
  return media->getOwner() == owner;
}

void O_Search::print(ostream& ost) const {
  ost << "Search by owner: " << owner;
}

// C_Search Implementation
C_Search::C_Search(const string& c) : category(c) {}

bool C_Search::matches(const Media* media) const {
  return media->getCategory() == category;
}

void C_Search::print(ostream& ost) const {
  ost << "Search by category: " << category;
}

// OorC_Search Implementation
OorC_Search::OorC_Search(const string& o, const string& c)
  : Search(), O_Search(o), C_Search(c) {}

bool OorC_Search::matches(const Media* media) const {
  return media->getOwner() == owner || media->getCategory() == category;
}

void OorC_Search::print(ostream& ost) const {
  ost << "Search by owner: " << owner << " OR category: " << category;
}
