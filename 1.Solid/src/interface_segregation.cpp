struct Document;
// This interface has multiple definitions so
// if you create a new derived class from this, that class
// will have to inherit unnecesary methods
//
// struct IMachine {
//     virtual void print(Document& doc) = 0;
//     virtual void scan(Document& doc) = 0;
//     virtual void fax(Document& doc) = 0;
// };

// This principle states that a interface must be segregated
// as many times as needed, so we will avoid to have unnecesary
// methods in new derived classes

struct IPrinter {
    virtual void print(Document& doc) = 0;
};

struct IScanner {
    virtual void scan(Document& doc) = 0;
};

struct IFax {
    virtual void fax(Document& doc) = 0;
};

struct Printer : IPrinter {
    void print(Document& doc) override{};
};

struct Scanner : IScanner {
    void scan(Document& doc) override{};
};

struct Fax : IFax {
    void fax(Document& doc) override{};
};

struct IMachine : IPrinter, IScanner {};

struct Machine : IMachine {
    IPrinter& printer;
    IScanner& scanner;
    Machine(IPrinter& printer, IScanner& scanner)
        : printer(printer), scanner(scanner) {}

    void print(Document& doc) override{};
    void scan(Document& doc) override{};
};

int main() { return 0; }