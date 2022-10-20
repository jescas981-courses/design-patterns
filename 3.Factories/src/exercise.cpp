#include <string>
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory {
public:
  Person create_person(const string &name) {
    static int id = 0;
    return {id++, name};
  }
};