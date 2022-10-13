#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct HtmlBuilder;

class HtmlElement {
    friend struct HtmlBuilder;

   private:
    std::string name, text;
    std::vector<HtmlElement> elements;
    const size_t indent_size = 2;
    HtmlElement() {}
    HtmlElement(const std::string &name, const std::string &text)
        : name(name), text(text) {}

   public:
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
    static HtmlBuilder create(const std::string &root_name);
};

class HtmlBuilder {
   private:
    HtmlElement root;

   public:
    HtmlBuilder(const std::string &root_name) { root.name = root_name; }
    HtmlBuilder &AddChild(const std::string &child_name,
                          const std::string child_text) {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return *this;
    }
    std::string str() const { return root.str(); }
    operator HtmlElement() const { return root; }
    HtmlElement build() const { return root; }
};

HtmlBuilder HtmlElement::create(const std::string &root_name) {
    return {root_name};
}

int main() {
    HtmlElement el = HtmlElement::create("ul").AddChild("", "");
    HtmlElement::create("").AddChild("", "").build();
}
