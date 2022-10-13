#include <iostream>
#include <string>
#include <tuple>
#include <vector>

enum class Relationship { kParent, kChild, kSibling };

struct Person {
    std::string name;
};

struct RelationshipBrowser {
    virtual std::vector<Person> FindAllChildrenOf(const std::string& name) = 0;
};

// Low-level
struct Relationships : RelationshipBrowser {
    std::vector<std::tuple<Person, Relationship, Person>> relations;
    void AddParentAndChild(const Person& parent, const Person& child) {
        relations.push_back({parent, Relationship::kParent, child});
        relations.push_back({child, Relationship::kChild, parent});
    }
    std::vector<Person> FindAllChildrenOf(const std::string& name) override {
        std::vector<Person> result;
        for (auto& i : relations) {
            if (std::get<0>(i).name == name &&
                std::get<1>(i) == Relationship::kParent) {
                result.push_back(std::get<2>(i));
            }
        }
        return result;
    }
};

// High-level
struct Research {
    // This constructor depends on a abstraction dependency
    //
    Research(RelationshipBrowser& browser) {
        for (auto& child : browser.FindAllChildrenOf("John")) {
            std::cout << "John has a child named " << child.name << std::endl;
        }
    }
    // This constructor depends on a implementation dependency
    //
    // Research(Relationships& relationships) {
    //     auto& relations = relationships.relations;
    //     for (auto& i : relations) {
    //         if (std::get<0>(i).name == "John" &&
    //             std::get<1>(i) == Relationship::kParent) {
    //             std::cout << "John has a child named " << std::get<2>(i).name
    //                       << std::endl;
    //         }
    //     }
    // }
};

int main() {
    Person parent{"John"};
    Person child1{"Chris"}, child2{"Matt"};
    Relationships relationships;
    relationships.AddParentAndChild(parent, child1);
    relationships.AddParentAndChild(parent, child2);

    Research _(relationships);
    return 0;
}
