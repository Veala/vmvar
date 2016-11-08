#ifndef TYPEABSTRACT_H
#define TYPEABSTRACT_H

#include<iostream>
#include<vector>
#include<stdexcept>

using namespace std;

class typeAbstract
{
public:
    enum types {
        INT,      INTTABLE,
        STRING,   STRINGTABLE,
        VMUSER
    };
    typeAbstract(string vName)    { varName = vName; }
    void setName(string newName)  { varName = newName; }
    const string getName()        { return varName; }
    types getType()               { return type; }
    typedef unsigned int uint;
protected:
    string varName;
    types type;
private:

};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T> class simpleAbstract : public typeAbstract
{
public:
    simpleAbstract(string vName, T defVal, uint N);
    simpleAbstract(simpleAbstract &data);
    void setValue(uint index, T newValue);
    T getValue(uint index);
protected:
    vector<T> value;
private:

};

class vmInt : public simpleAbstract <int>
{
public:
    vmInt(string vName, int defVal, uint N) : simpleAbstract<int>(vName, defVal, N) { type = INT; }
    vmInt(vmInt &data) : simpleAbstract<int>(data) { type = INT; }
};
class vmString : public simpleAbstract <string>
{
public:
    vmString(string vName, string defVal, uint N) : simpleAbstract<string>(vName, defVal, N) { type = STRING; }
    vmString(vmString &data) : simpleAbstract<string>(data) { type = STRING; }
};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T> class tableAbstract : public typeAbstract
{
public:
    tableAbstract(string vName, T defVal, uint numRows, uint numColumns);
    tableAbstract(tableAbstract &data);
    void setValue(uint row, uint column, T newValue);
    T getValue(uint row, uint column);
protected:
    vector< vector<T> > value;
private:

};

class vmIntTable : public tableAbstract <int>
{
public:
    vmIntTable(string vName, int defVal, uint numRows, uint numColumns) : tableAbstract<int>(vName, defVal, numRows, numColumns) { type = INTTABLE; }
    vmIntTable(vmIntTable &data) : tableAbstract<int>(data) { type = INTTABLE; }
};
class vmStringTable : public tableAbstract <string>
{
public:
    vmStringTable(string vName, string defVal, uint numRows, uint numColumns) : tableAbstract<string>(vName, defVal, numRows, numColumns) { type = STRINGTABLE; }
    vmStringTable(vmStringTable &data) : tableAbstract<string>(data) { type = STRINGTABLE; }
};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class userAbstract : public typeAbstract
{
public:
    userAbstract(string vName) : typeAbstract(vName) { type = VMUSER; }
    void setValue(typeAbstract* val) { value.push_back(val); }
    void del(typeAbstract* v) {
        switch (v->getType()) {
        case INT:
            delete (vmInt*)v;
            break;
        case STRING:
            delete (vmString*)v;
            break;
        case INTTABLE:
            delete (vmIntTable*)v;
            break;
        case STRINGTABLE:
            delete (vmStringTable*)v;
            break;
        case VMUSER:
            delete (userAbstract*)v;
            break;
        }
    }
    typeAbstract* getValue(string vName, types t) {
        typeAbstract* val;
        for (uint i=0; i<value.size(); i++) {
            val = value.at(i);
            if ((val->getName() == vName) && (val->getType() == t)) return val;
        }
        return 0;
    }
    ~userAbstract() {
        for (uint i=0; i<value.size(); i++)
            del(value.at(i));
    }

protected:
    vector<typeAbstract*>   value;
private:

};

#endif // TYPEABSTRACT_H
