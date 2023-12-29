#pragma once
#include <string>
using namespace std;

class Color {
public:
// Given an integer value, convert it to RGB and Hex values
    void SetValue(int value);
    void SetName(const char *name);

    // Accessors
    unsigned char GetR() const;
    unsigned char GetG() const;
    unsigned char GetB() const;
    string GetHexValue() const;
    string GetName() const;

private:
    unsigned char r;
    unsigned char g;
    unsigned char b;
    string name;
    string hex;
    int intValue;

};