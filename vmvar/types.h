#ifndef TYPEABSTRACT_H
#define TYPEABSTRACT_H

#include<iostream>
#include<sstream>
#include<string>
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
    virtual typeAbstract* clone() { }
    typedef unsigned int uint;
    ~typeAbstract() {   cout << "deleting tA: " << varName << endl; }
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
    ~simpleAbstract() { cout << "deleting sA: " << varName << endl; }
protected:
    vector<T> value;
private:

};

class vmBool : public simpleAbstract <bool>
{
public:
    vmBool(string vName, bool defVal, uint N) : simpleAbstract<bool>(vName, defVal, N) { type = BOOL; }
    vmBool(vmBool &data) : simpleAbstract<bool>(data) { type = BOOL; }
    typeAbstract* clone() { return new vmBool(*this); }
};
class vmInt : public simpleAbstract <int>
{
public:
    vmInt(string vName, int defVal, uint N) : simpleAbstract<int>(vName, defVal, N) { type = INT; }
    vmInt(vmInt &data) : simpleAbstract<int>(data) { type = INT; }
    typeAbstract* clone() { return new vmInt(*this); }
};
class vmLong : public simpleAbstract <long>
{
public:
    vmLong(string vName, long defVal, uint N) : simpleAbstract<long>(vName, defVal, N) { type = LONG; }
    vmLong(vmLong &data) : simpleAbstract<long>(data) { type = LONG; }
    typeAbstract* clone() { return new vmLong(*this); }
};
class vmFloat : public simpleAbstract <float>
{
public:
    vmFloat(string vName, float defVal, uint N) : simpleAbstract<float>(vName, defVal, N) { type = FLOAT; }
    vmFloat(vmFloat &data) : simpleAbstract<float>(data) { type = FLOAT; }
    typeAbstract* clone() { return new vmFloat(*this); }
};
class vmString : public simpleAbstract <string>
{
public:
    vmString(string vName, string defVal, uint N) : simpleAbstract<string>(vName, defVal, N) { type = STRING; }
    vmString(vmString &data) : simpleAbstract<string>(data) { type = STRING; }
    typeAbstract* clone() { return new vmString(*this); }
};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T> class tableAbstract : public typeAbstract
{
public:
    tableAbstract(string vName, T defVal, uint numRows, uint numColumns);
    tableAbstract(tableAbstract &data);
    void setValue(uint row, uint column, T newValue);
    T getValue(uint row, uint column);
    ~tableAbstract() { cout << "deleting ttA: " << varName << endl; }
protected:
    vector< vector<T> > value;
private:

};

class vmBoolTable : public tableAbstract <bool>
{
public:
    vmBoolTable(string vName, bool defVal, uint numRows, uint numColumns) : tableAbstract<bool>(vName, defVal, numRows, numColumns) { type = BOOLTABLE; }
    vmBoolTable(vmBoolTable &data) : tableAbstract<bool>(data) { type = BOOLTABLE; }
    typeAbstract* clone() { return new vmBoolTable(*this); }
};
class vmIntTable : public tableAbstract <int>
{
public:
    vmIntTable(string vName, int defVal, uint numRows, uint numColumns) : tableAbstract<int>(vName, defVal, numRows, numColumns) { type = INTTABLE; }
    vmIntTable(vmIntTable &data) : tableAbstract<int>(data) { type = INTTABLE; }
    typeAbstract* clone() { return new vmIntTable(*this); }
};
class vmLongTable : public tableAbstract <long>
{
public:
    vmLongTable(string vName, long defVal, uint numRows, uint numColumns) : tableAbstract<long>(vName, defVal, numRows, numColumns) { type = LONGTABLE; }
    vmLongTable(vmLongTable &data) : tableAbstract<long>(data) { type = LONGTABLE; }
    typeAbstract* clone() { return new vmLongTable(*this); }
};
class vmFloatTable : public tableAbstract <float>
{
public:
    vmFloatTable(string vName, float defVal, uint numRows, uint numColumns) : tableAbstract<float>(vName, defVal, numRows, numColumns) { type = FLOATTABLE; }
    vmFloatTable(vmFloatTable &data) : tableAbstract<float>(data) { type = FLOATTABLE; }
    typeAbstract* clone() { return new vmFloatTable(*this); }
};
class vmStringTable : public tableAbstract <string>
{
public:
    vmStringTable(string vName, string defVal, uint numRows, uint numColumns) : tableAbstract<string>(vName, defVal, numRows, numColumns) { type = STRINGTABLE; }
    vmStringTable(vmStringTable &data) : tableAbstract<string>(data) { type = STRINGTABLE; }
    typeAbstract* clone() { return new vmStringTable(*this); }
};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class userAbstract : public typeAbstract
{
public:
    userAbstract(string vName) : typeAbstract(vName) { type = VMUSER; }
    void addVar(typeAbstract* var) { vars.push_back(var->clone()); }

    typeAbstract* getVar(string strHierarchy, types t) {
        istringstream iss(strHierarchy);   vector<string> names;
        while (getline(iss, strHierarchy, '.'))    names.push_back(strHierarchy);

        if (names.size() == 0)  return 0;
        else if (names.size() == 1)  return searchVar(names[0], t);
        else {
            strHierarchy.clear();
            for (uint i=1;i<names.size();i++) {
                strHierarchy+=names[i];
                if (i!=names.size()-1) strHierarchy+='.';
            }
            typeAbstract* var = searchVar(names[0], VMUSER);
            if(var) return ((userAbstract*)var)->getVar(strHierarchy,t);
            else    return 0;
        }
    }

    userAbstract* clone() {
        userAbstract* clone = new userAbstract(varName);
        for (uint i=0; i<vars.size();i++) {
            typeAbstract* var = vars.at(i);
            clone->addVar(var->clone());
        }
        return clone;
    }

    ~userAbstract() {
        cout << "deleting uA: " << varName << endl;
        for (uint i=0; i<vars.size(); i++)
            del(vars.at(i));
    }

protected:
    vector<typeAbstract*>   vars;
private:
    typeAbstract* searchVar(string vName, types t) {
        typeAbstract* var;
        for (uint i=0; i<vars.size(); i++) {
            var = vars.at(i);
            if ((var->getName() == vName) && (var->getType() == t)) return var;
        }
        return 0;
    }
    void del(typeAbstract* v) {
        switch (v->getType()) {
//        delete v;
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
};

#endif // TYPEABSTRACT_H
