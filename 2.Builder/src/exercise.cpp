#include <ostream>
#include <string>
#include <vector>

using namespace std;

class CodeBuilder {
    string class_name;
    vector<pair<string, string>> fields;

   public:
    CodeBuilder(const string& class_name) : class_name(class_name) {}

    CodeBuilder& add_field(const string& name, const string& type) {
        fields.push_back({type, name});
        return *this;
    }

    friend ostream& operator<<(ostream& os, const CodeBuilder& obj) {
        os << "class " << obj.class_name << "\n{";
        for (const auto& f : obj.fields) {
            os << "\n  " << f.first << " " << f.second << ";";
        }
        os << "\n};";
        return os;
    }
};