#ifndef TYPEABSTRACT_H
#define TYPEABSTRACT_H

#include<iostream>
#include<string>
#include<istream>
#include<vector>
#include<stdexcept>

using namespace std;

class typeAbstract
{
public:
    enum types {
        BOOL,     BOOLTABLE,
        INT,      INTTABLE,
        LONG,     LONGTABLE,
        FLOAT,    FLOATTABLE,
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

class vmBool : public simpleAbstract <bool>
{
public:
    vmBool(string vName, bool defVal, uint N) : simpleAbstract<bool>(vName, defVal, N) { type = BOOL; }
    vmBool(vmBool &data) : simpleAbstract<bool>(data) { type = BOOL; }
};
class vmInt : public simpleAbstract <int>
{
public:
    vmInt(string vName, int defVal, uint N) : simpleAbstract<int>(vName, defVal, N) { type = INT; }
    vmInt(vmInt &data) : simpleAbstract<int>(data) { type = INT; }
};
class vmLong : public simpleAbstract <long>
{
public:
    vmLong(string vName, long defVal, uint N) : simpleAbstract<long>(vName, defVal, N) { type = LONG; }
    vmLong(vmLong &data) : simpleAbstract<long>(data) { type = LONG; }
};
class vmFloat : public simpleAbstract <float>
{
public:
    vmFloat(string vName, float defVal, uint N) : simpleAbstract<float>(vName, defVal, N) { type = FLOAT; }
    vmFloat(vmFloat &data) : simpleAbstract<float>(data) { type = FLOAT; }
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

class vmBoolTable : public tableAbstract <bool>
{
public:
    vmBoolTable(string vName, bool defVal, uint numRows, uint numColumns) : tableAbstract<bool>(vName, defVal, numRows, numColumns) { type = BOOLTABLE; }
    vmBoolTable(vmBoolTable &data) : tableAbstract<bool>(data) { type = BOOLTABLE; }
};
class vmIntTable : public tableAbstract <int>
{
public:
    vmIntTable(string vName, int defVal, uint numRows, uint numColumns) : tableAbstract<int>(vName, defVal, numRows, numColumns) { type = INTTABLE; }
    vmIntTable(vmIntTable &data) : tableAbstract<int>(data) { type = INTTABLE; }
};
class vmLongTable : public tableAbstract <long>
{
public:
    vmLongTable(string vName, long defVal, uint numRows, uint numColumns) : tableAbstract<long>(vName, defVal, numRows, numColumns) { type = LONGTABLE; }
    vmLongTable(vmLongTable &data) : tableAbstract<long>(data) { type = LONGTABLE; }
};
class vmFloatTable : public tableAbstract <float>
{
public:
    vmFloatTable(string vName, float defVal, uint numRows, uint numColumns) : tableAbstract<float>(vName, defVal, numRows, numColumns) { type = FLOATTABLE; }
    vmFloatTable(vmFloatTable &data) : tableAbstract<float>(data) { type = FLOATTABLE; }
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
    void addVar(typeAbstract* var) { vars.push_back(var); }

    void del(typeAbstract* v) {
        switch (v->getType()) {
        case BOOL:
            delete (vmBool*)v;
            break;
        case INT:
            delete (vmInt*)v;
            break;
        case LONG:
            delete (vmLong*)v;
            break;
        case FLOAT:
            delete (vmFloat*)v;
            break;
        case STRING:
            delete (vmString*)v;
            break;
        case BOOLTABLE:
            delete (vmBoolTable*)v;
            break;
        case INTTABLE:
            delete (vmIntTable*)v;
            break;
        case LONGTABLE:
            delete (vmLongTable*)v;
            break;
        case FLOATTABLE:
            delete (vmFloatTable*)v;
            break;
        case STRINGTABLE:
            delete (vmStringTable*)v;
            break;
        case VMUSER:
            delete (userAbstract*)v;
            break;
        }
    }

    typeAbstract* getVar(string vName, types t) {
        stringstream sstr;
        getline()

        typeAbstract* var;
        for (uint i=0; i<vars.size(); i++) {
            var = vars.at(i);
            if ((var->getName() == vName) && (var->getType() == t)) return var;
        }
        return 0;
    }
    userAbstract* clone() {
        userAbstract* clone = new userAbstract(varName);
        for (uint i=0; i<vars.size();i++) {
            typeAbstract* var = vars.at(i);
            switch (var->getType()) {
            case BOOL:
                clone->addVar(new vmBool(*(vmBool*)var));
                break;
            case INT:
                clone->addVar(new vmInt(*(vmInt*)var));
                break;
            case LONG:
                clone->addVar(new vmLong(*(vmLong*)var));
                break;
            case FLOAT:
                clone->addVar(new vmFloat(*(vmFloat*)var));
                break;
            case STRING:
                clone->addVar(new vmString(*(vmString*)var));
                break;
            case BOOLTABLE:
                clone->addVar(new vmBoolTable(*(vmBoolTable*)var));
                break;
            case INTTABLE:
                clone->addVar(new vmIntTable(*(vmIntTable*)var));
                break;
            case LONGTABLE:
                clone->addVar(new vmLongTable(*(vmLongTable*)var));
                break;
            case FLOATTABLE:
                clone->addVar(new vmFloatTable(*(vmFloatTable*)var));
                break;
            case STRINGTABLE:
                clone->addVar(new vmStringTable(*(vmStringTable*)var));
                break;
            case VMUSER:
                clone->addVar(((userAbstract*)var)->clone());
                break;
            }
        }
        return clone;
    }

    ~userAbstract() {
        for (uint i=0; i<vars.size(); i++)
            del(vars.at(i));
    }

protected:
    vector<typeAbstract*>   vars;
private:

};

#endif // TYPEABSTRACT_H
