#ifndef N2AbstractType_H
#define N2AbstractType_H

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

class N2AbstractType
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
    N2AbstractType(string vName)    { varName = vName; }
    void setName(string newName)    { varName = newName; }
    const string getName()          { return varName; }
    types getType()                 { return type; }
    virtual N2AbstractType* clone() {  }
    typedef unsigned int uint;
    ~N2AbstractType() {   cout << "deleting tA: " << varName << endl; }
protected:
    string varName;
    types type;
private:

};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T> class N2AbstractSimple : public N2AbstractType
{
public:
    N2AbstractSimple(string vName, T defVal, uint N);
    N2AbstractSimple(N2AbstractSimple &data);
    void setValue(uint index, T newValue);
    T getValue(uint index);
    N2AbstractType* clone() { return new N2AbstractSimple<T>(*this); }
    ~N2AbstractSimple() { cout << "deleting sA: " << varName << endl; }
protected:
    vector<T> value;
private:

};

class N2Bool : public N2AbstractSimple <bool>
{
public:
    N2Bool(string vName, bool defVal, uint N) : N2AbstractSimple<bool>(vName, defVal, N) { type = BOOL; }
    //N2Bool(N2Bool &data) : N2AbstractSimple<bool>(data) { type = BOOL; }
};
class N2Int : public N2AbstractSimple <int>
{
public:
    N2Int(string vName, int defVal, uint N) : N2AbstractSimple<int>(vName, defVal, N) { type = INT; }
    //N2Int(N2Int &data) : N2AbstractSimple<int>(data) { type = INT; }
};
class N2Long : public N2AbstractSimple <long>
{
public:
    N2Long(string vName, long defVal, uint N) : N2AbstractSimple<long>(vName, defVal, N) { type = LONG; }
    //N2Long(N2Long &data) : N2AbstractSimple<long>(data) { type = LONG; }
};
class N2Float : public N2AbstractSimple <float>
{
public:
    N2Float(string vName, float defVal, uint N) : N2AbstractSimple<float>(vName, defVal, N) { type = FLOAT; }
    //N2Float(N2Float &data) : N2AbstractSimple<float>(data) { type = FLOAT; }
};
class N2String : public N2AbstractSimple <string>
{
public:
    N2String(string vName, string defVal, uint N) : N2AbstractSimple<string>(vName, defVal, N) { type = STRING; }
    //N2String(N2String &data) : N2AbstractSimple<string>(data) { type = STRING; }
};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T> class N2AbstractTable : public N2AbstractType
{
public:
    N2AbstractTable(string vName, T defVal, uint numRows, uint numColumns);
    N2AbstractTable(N2AbstractTable &data);
    void setValue(uint row, uint column, T newValue);
    T getValue(uint row, uint column);
    N2AbstractType* clone() { return new N2AbstractTable<T>(*this); }
    ~N2AbstractTable() { cout << "deleting ttA: " << varName << endl; }
protected:
    vector< vector<T> > value;
private:

};

class N2BoolTable : public N2AbstractTable <bool>
{
public:
    N2BoolTable(string vName, bool defVal, uint numRows, uint numColumns) : N2AbstractTable<bool>(vName, defVal, numRows, numColumns) { type = BOOLTABLE; }
    //N2BoolTable(N2BoolTable &data) : N2AbstractTable<bool>(data) { type = BOOLTABLE; }
};
class N2IntTable : public N2AbstractTable <int>
{
public:
    N2IntTable(string vName, int defVal, uint numRows, uint numColumns) : N2AbstractTable<int>(vName, defVal, numRows, numColumns) { type = INTTABLE; }
    //N2IntTable(N2IntTable &data) : N2AbstractTable<int>(data) { type = INTTABLE; }
};
class N2LongTable : public N2AbstractTable <long>
{
public:
    N2LongTable(string vName, long defVal, uint numRows, uint numColumns) : N2AbstractTable<long>(vName, defVal, numRows, numColumns) { type = LONGTABLE; }
    //N2LongTable(N2LongTable &data) : N2AbstractTable<long>(data) { type = LONGTABLE; }
};
class N2FloatTable : public N2AbstractTable <float>
{
public:
    N2FloatTable(string vName, float defVal, uint numRows, uint numColumns) : N2AbstractTable<float>(vName, defVal, numRows, numColumns) { type = FLOATTABLE; }
    //N2FloatTable(N2FloatTable &data) : N2AbstractTable<float>(data) { type = FLOATTABLE; }
};
class N2StringTable : public N2AbstractTable <string>
{
public:
    N2StringTable(string vName, string defVal, uint numRows, uint numColumns) : N2AbstractTable<string>(vName, defVal, numRows, numColumns) { type = STRINGTABLE; }
    //N2StringTable(N2StringTable &data) : N2AbstractTable<string>(data) { type = STRINGTABLE; }
};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class N2User : public N2AbstractType
{
public:
    N2User(string vName) : N2AbstractType(vName) { type = VMUSER; }
    void addCopyVar(N2AbstractType* var) { vars.push_back(var->clone()); }

    N2AbstractType* getVar(string strHierarchy, types t) {
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
            N2AbstractType* var = searchVar(names[0], VMUSER);
            if(var) return ((N2User*)var)->getVar(strHierarchy,t);
            else    return 0;
        }
    }

    N2User* clone() {
        N2User* clone = new N2User(varName);
        for (uint i=0; i<vars.size();i++) {
            N2AbstractType* var = vars.at(i);
            clone->addCopyVar(var->clone());
        }
        return clone;
    }

    ~N2User() {
        cout << "deleting uA: " << varName << endl;
        for (uint i=0; i<vars.size(); i++)
            del(vars.at(i));
    }

protected:
    vector<N2AbstractType*>   vars;
private:
    N2AbstractType* searchVar(string vName, types t) {
        N2AbstractType* var;
        for (uint i=0; i<vars.size(); i++) {
            var = vars.at(i);
            if ((var->getName() == vName) && (var->getType() == t)) return var;
        }
        return 0;
    }
    void del(N2AbstractType* v) {
        switch (v->getType()) {
//        delete v;
        case BOOL:
            delete (N2Bool*)v;
            break;
        case INT:
            delete (N2Int*)v;
            break;
        case LONG:
            delete (N2Long*)v;
            break;
        case FLOAT:
            delete (N2Float*)v;
            break;
        case STRING:
            delete (N2String*)v;
            break;
        case BOOLTABLE:
            delete (N2BoolTable*)v;
            break;
        case INTTABLE:
            delete (N2IntTable*)v;
            break;
        case LONGTABLE:
            delete (N2LongTable*)v;
            break;
        case FLOATTABLE:
            delete (N2FloatTable*)v;
            break;
        case STRINGTABLE:
            delete (N2StringTable*)v;
            break;
        case VMUSER:
            delete (N2User*)v;
            break;
        }
    }
};

#endif // N2AbstractType_H
