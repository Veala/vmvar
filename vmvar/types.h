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

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T> class simpleAbstract : public typeAbstract
{
public:
    simpleAbstract(string vName, T defVal, uint N);
    simpleAbstract(simpleAbstract &data);
    void setValue(uint index, T newValue);
    const T getValue(uint index);
protected:
    vector<T> value;
private:

};

typedef simpleAbstract<int>      vmInt;
typedef simpleAbstract<string>   vmString;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T> class tableAbstract : public typeAbstract
{
public:
    tableAbstract(string vName, T defVal, uint numRows, uint numColumns);
    tableAbstract(tableAbstract &data);
    void setValue(uint row, uint column, T newValue);
    const T getValue(uint row, uint column);
protected:
    vector< vector<T> > value;
private:

};

typedef tableAbstract<int>      vmIntTable;
typedef tableAbstract<string>   vmStringTable;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class userAbstract : public typeAbstract
{
public:
    userAbstract(string vName, uint numVmInts, uint numVmStrings, uint numVmITables, uint numVmSTables);
protected:
    vector<vmInt>           vmIntValues;
    vector<vmString>        vmStringValues;
    vector<vmIntTable>      vmIntTables;
    vector<vmStringTable>   vmStringTables;
private:

};

#endif // TYPEABSTRACT_H
