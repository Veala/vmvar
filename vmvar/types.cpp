#include "types.h"

//typeAbstract::typeAbstract(string vName)
//{
//    varName = vName;
//}

void typeAbstract::setName(string newName)
{
    varName = newName;
}

const string typeAbstract::getName()
{
    return varName;
}

//---------------------------------------------------------------------------------------------------------------------------------

//template <class T> simpleAbstract<T>::simpleAbstract(string vName, T defVal) : typeAbstract(vName)
//{
//    value = defVal;
//}

template <class T> void simpleAbstract<T>::setValue(T newValue)
{
    value = newValue;
}

template <class T> const T simpleAbstract<T>::getValue()
{
    return value;
}

//---------------------------------------------------------------------------------------------------------------------------------

//template <class T> arrayAbstract<T>::arrayAbstract(string vName, T defVal, uint N) : typeAbstract(vName)
//{
//    for (unsigned i=0;i<N;i++) value.push_back(defVal);
//}

template <class T> void arrayAbstract<T>::setValue(uint index, T newValue)
{
    try {
        value[index] = newValue;
    } catch (const std::out_of_range &err) {
        cout << err.what() << endl;
    }
}

template <class T> const T arrayAbstract<T>::getValue(uint index)
{
    try {
        return value[index];
    } catch (const std::out_of_range &err) {
        cout << err.what() << endl;
    }
}

//---------------------------------------------------------------------------------------------------------------------------------

//template <class T> tableAbstract<T>::tableAbstract(string vName, T defVal, uint N_Rows, uint N_Columns) : typeAbstract(vName)
//{
//    for (uint i=0;i<N_Rows;i++) {
//        vector<T> line;
//        value.push_back(line);
//        for (uint j=0;j<N_Columns;j++) {
//            line.push_back(defVal);
//        }
//    }
//}

template <class T> void tableAbstract<T>::setValue(uint row, uint column, T newValue)
{
    try {
        value[row][column] = newValue;
    } catch (const std::out_of_range &err) {
        cout << err.what() << endl;
    }
}

template <class T> const T tableAbstract<T>::getValue(uint row, uint column)
{
    try {
        return value[row][column];
    } catch (const std::out_of_range &err) {
        cout << err.what() << endl;
    }
}
