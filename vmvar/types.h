#ifndef TYPEABSTRACT_H
#define TYPEABSTRACT_H

#include<iostream>
#include<vector>
#include<stdexcept>

using namespace std;

class typeAbstract
{
public:
    typeAbstract(string vName);
    void setName(string newName);
    const string getName();
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
    simpleAbstract(string vName, T defVal);
    void setValue(T newValue);
    const T getValue();
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
    vector< vector<T> > value;
private:

};

class vmBoolTable : public tableAbstract<bool>
{
public:
    vmBoolTable(string vName, bool defVal, uint numRows, uint numColumns) : tableAbstract(vName, defVal, numRows, numColumns) { }
};
class vmIntTable : public tableAbstract<int>
{
public:
    vmIntTable(string vName, int defVal, uint numRows, uint numColumns) : tableAbstract(vName, defVal, numRows, numColumns) { }
};
class vmLongTable : public tableAbstract<long>
{
public:
    vmLongTable(string vName, long defVal, uint numRows, uint numColumns) : tableAbstract(vName, defVal, numRows, numColumns) { }
};
class vmStringTable : public tableAbstract<string>
{
public:
    vmStringTable(string vName, string defVal, uint numRows, uint numColumns) : tableAbstract(vName, defVal, numRows, numColumns) { }
};

//=============================================================================================================================================================================================

typeAbstract::typeAbstract(string vName)
{
    varName = vName;
}

//void typeAbstract::setName(string newName)
//{
//    varName = newName;
//}

//const string typeAbstract::getName()
//{
//    return varName;
//}

//---------------------------------------------------------------------------------------------------------------------------------

template <class T> simpleAbstract<T>::simpleAbstract(string vName, T defVal) : typeAbstract(vName)
{
    value = defVal;
}

//template <class T> void simpleAbstract<T>::setValue(T newValue)
//{
//    value = newValue;
//}

//template <class T> const T simpleAbstract<T>::getValue()
//{
//    return value;
//}

//---------------------------------------------------------------------------------------------------------------------------------

template <class T> arrayAbstract<T>::arrayAbstract(string vName, T defVal, uint N) : typeAbstract(vName)
{
    for (unsigned i=0;i<N;i++) value.push_back(defVal);
}

//template <class T> void arrayAbstract<T>::setValue(uint index, T newValue)
//{
//    try {
//        value[index] = newValue;
//    } catch (const std::out_of_range &err) {
//        cout << err.what() << endl;
//    }
//}

//template <class T> const T arrayAbstract<T>::getValue(uint index)
//{
//    try {
//        return value[index];
//    } catch (const std::out_of_range &err) {
//        cout << err.what() << endl;
//    }
//}

//---------------------------------------------------------------------------------------------------------------------------------

template <class T> tableAbstract<T>::tableAbstract(string vName, T defVal, uint N_Rows, uint N_Columns) : typeAbstract(vName)
{
    for (uint i=0;i<N_Rows;i++) {
        vector<T> line;
        value.push_back(line);
        for (uint j=0;j<N_Columns;j++) {
            line.push_back(defVal);
        }
    }
}

//template <class T> void tableAbstract<T>::setValue(uint row, uint column, T newValue)
//{
//    try {
//        value[row][column] = newValue;
//    } catch (const std::out_of_range &err) {
//        cout << err.what() << endl;
//    }
//}

//template <class T> const T tableAbstract<T>::getValue(uint row, uint column)
//{
//    try {
//        return value[row][column];
//    } catch (const std::out_of_range &err) {
//        cout << err.what() << endl;
//    }
//}
#endif // TYPEABSTRACT_H
