#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
using namespace std;

class Media;  // Forward declaration

// Abstract base class
class Search {
  public:
    virtual ~Search() {}

    virtual bool matches(const Media*) const = 0;
    virtual void print(ostream& ost) const = 0;

    friend ostream& operator<<(ostream& ost, const Search& s) {
        s.print(ost);
        return ost;
    }
};

// O_Search class (Search by owner)
class O_Search : public virtual Search {
  public:
    O_Search(const string&);
    bool matches(const Media*) const override;
    void print(ostream& ost) const override;

  protected:
    string owner;
};

// C_Search class (Search by category)
class C_Search : public virtual Search {
  public:
    C_Search(const string&);
    bool matches(const Media*) const override;
    void print(ostream& ost) const override;

  protected:
    string category;
};

// OorC_Search class (Search by owner OR category)
class OorC_Search : public O_Search, public C_Search {
  public:
    OorC_Search(const string& owner, const string& category);
    bool matches(const Media*) const override;
    void print(ostream& ost) const override;
};

#endif
