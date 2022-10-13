
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct HtmlElement {
    std::string name, text;
    std::vector<HtmlElement> elements;
    const size_t indent_size = 2;
    HtmlElement() {}
    HtmlElement(const std::string &name, const std::string &text)
        : name(name), text(text) {}
    std::string str(int indent = 0) const {
        std::ostringstream oss;
        std::string i(indent_size * indent, ' ');
        oss << i << "<" << name << ">" << std::endl;
        if (text.size() > 0) {
            oss << std::string(indent_size * (indent + 1), ' ') << text
                << std::endl;
        }

        for (const auto &e : elements) {
            oss << e.str(indent + 1);
        }
        oss << i << "</" << name << ">" << std::endl;

        return oss.str();
    }
};

struct HtmlBuilder {
    HtmlElement root;
    HtmlBuilder(const std::string &root_name) { root.name = root_name; }
    void AddChild(const std::string &child_name, const std::string child_text) {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
    }
    std::string str() const { return root.str(); }
};

int main() {
    HtmlBuilder builder{"ul"};
    builder.AddChild("li", "Hello");
    builder.AddChild("li", "world");
    std::cout << builder.str() << std::endl;
}
