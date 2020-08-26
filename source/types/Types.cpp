
#include <iostream>
#include <map>

#define LAMBDA_TOKEN \\;

using namespace std;

class Type {
    public:
    virtual string encodingOf(const &string literal) = 0;
};

class BoolType : public Type {
    private:
    map<string, string> encodings;
    public:
    BoolType();
    string encodingOf(const &string literal) override {
        if (encodings.contains(literal)) {
            return encodings[literal];
        }
        return nullptr;
    }
};

class IntType : public Type {
    private:
    string generateChurchEncoding(const &int number) {
        const string churchNumeral;
        churchNumeral.append("(\\f: *.\\x: *.");
        for (size_t i = 0; i < number; i++)
            churchNumeral.append("f (");
        churchNumeral.append(" x");
        for (size_t i = 0; i < number; i++)
            churchNumeral.append(")");
        churchNumeral.append(")");
        return churchNumeral;
    }
    public:
    IntType();
    string encodingOf(const &string literal) override {
        const int value = stoi(literal);
        return generateChurchEncoding(value);
    }
};