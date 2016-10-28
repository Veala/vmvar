#ifndef TYPEABSTRACT_H
#define TYPEABSTRACT_H

#include<iostream>
#include<vector>
#include<stdexcept>

using namespace std;

class typeAbstract
{
public:
    typeAbstract(string vName)    { varName = vName; }
    void setName(string newName)  { varName = newName; }
    const string getName()        { return varName; }
    typedef unsigned int uint;
protected:
    string varName;
private:

};

//---------------------------------------------------------------------------------------------------------------------------------

template <class T>
class simpleAbstract : public typeAbstract
{
public:
    simpleAbstract(string vName, T defVal) : typeAbstract(vName) { value = defVal; }
    void setValue(T newValue) { value = newValue; }
    const T getValue() { return value; }
protected:
    T value;
private:

};

class vmBool : public simpleAbstract <bool>
{
public:
    vmBool(string vName, bool defVal) : simpleAbstract<bool>(vName, defVal) { }
};
class vmInt : public simpleAbstract <int>
{
public:
    vmInt(string vName, int defVal) : simpleAbstract<int>(vName, defVal) { }
};
class vmLong : public simpleAbstract <long>
{
public:
    vmLong(string vName, long defVal) : simpleAbstract<long>(vName, defVal) { }
};
class vmString : public simpleAbstract <string>
{
public:
    vmString(string vName, string defVal) : simpleAbstract<string>(vName, defVal) { }
};

//---------------------------------------------------------------------------------------------------------------------------------

template <class T> class arrayAbstract : public typeAbstract
{
public:
    arrayAbstract(string vName, T defVal, uint N);
    void setValue(uint index, T newValue);
    const T getValue(uint index);
protected:
    vector<T> value;
private:

};

typedef arrayAbstract<int> intTypexxx;

class vmBoolArray : public arrayAbstract<bool>
{
public:
    vmBoolArray(string vName, bool defVal, uint N) : arrayAbstract<bool>(vName, defVal, N) { }
};
class vmIntArray : public arrayAbstract<int>
{
public:
    vmIntArray(string vName, int defVal, uint N) : arrayAbstract<int>(vName, defVal, N) { }
};
class vmLongArray : public arrayAbstract<long>
{
public:
    vmLongArray(string vName, long defVal, uint N) : arrayAbstract<long>(vName, defVal, N) { }
};
class vmStringArray : public arrayAbstract<string>
{
public:
    vmStringArray(string vName, string defVal, uint N) : arrayAbstract<string>(vName, defVal, N) { }
};

//---------------------------------------------------------------------------------------------------------------------------------

template <class T> class tableAbstract : public typeAbstract
{
public:
    tableAbstract(string vName, T defVal, uint numRows, uint numColumns);
    //~tableAbstract();
    void setValue(uint row, uint column, T newValue);
    const T getValue(uint row, uint column);
protected:
    //T** value;
    vector< vector<T>* > value;
private:

};

class vmBoolTable : public tableAbstract<bool>
{
public:
    vmBoolTable(string vName, bool defVal, uint numRows, uint numColumns) : tableAbstract<bool>(vName, defVal, numRows, numColumns) { }
};
class vmIntTable : public tableAbstract<int>
{
public:
    vmIntTable(string vName, int defVal, uint numRows, uint numColumns) : tableAbstract<int>(vName, defVal, numRows, numColumns) { }
};
class vmLongTable : public tableAbstract<long>
{
public:
    vmLongTable(string vName, long defVal, uint numRows, uint numColumns) : tableAbstract<long>(vName, defVal, numRows, numColumns) { }
};
class vmStringTable : public tableAbstract<string>
{
public:
    vmStringTable(string vName, string defVal, uint numRows, uint numColumns) : tableAbstract<string>(vName, defVal, numRows, numColumns) { }
};

#endif // TYPEABSTRACT_H
