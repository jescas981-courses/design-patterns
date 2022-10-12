#include <boost/lexical_cast.hpp>
#include <fstream>
#include <string>
#include <vector>

struct Journal {
    std::string title;
    std::vector<std::string> entries;

    Journal(const std::string& title) : title(title) {}
    void AddEntry(const std::string& entry) {
        static int count = 1;
        entries.push_back(boost::lexical_cast<std::string>(count++) + ": " +
                          entry);
    }

    // Saving and managing files isn't the concern of the Journal struct
    //
    // void Save(const std::string& filename) {
    //         std::ofstream os(filename);
    //         os << title << std::endl;
    //         for (const auto& entry : entries) {
    //             os << entry << std::endl;
    //         }
    //     }
};

struct PersistenceManager {
    // PersistanceManager has the responsability to manage files
    //
    void Save(const Journal& j, const std::string& filename) {
        std::ofstream os(filename);
        os << j.title << std::endl;
        for (const auto& e : j.entries) {
            os << e << std::endl;
        }
    }
};

int main() {
    Journal journal{"Dear diary"};
    journal.AddEntry("I went to the market");
    journal.AddEntry("I played video Games");
    PersistenceManager pm;
    pm.Save(journal, "diary.txt");
    return 0;
}