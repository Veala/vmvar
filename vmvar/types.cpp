#include "types.h"

template <class T> arrayAbstract<T>::arrayAbstract(string vName, T defVal, uint N) : typeAbstract(vName)
{
    for (unsigned i=0;i<N;i++) value.push_back(defVal);
}

template <class T> void arrayAbstract<T>::setValue(uint index, T newValue)
{
    try {
        value.at(index) = newValue;
    } catch (const std::out_of_range &err) {
        cout << err.what() << endl;
    }
}

template <class T> const T arrayAbstract<T>::getValue(uint index)
{
    try {
        return value.at(index);
    } catch (const std::out_of_range &err) {
        cout << err.what() << endl;
    }
}

template class arrayAbstract<bool>;
template class arrayAbstract<int>;
template class arrayAbstract<long>;
template class arrayAbstract<string>;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T> tableAbstract<T>::tableAbstract(string vName, T defVal, uint N_Rows, uint N_Columns) : typeAbstract(vName)
{
    for (uint i=0;i<N_Rows;i++) {
        vector<T> line;
        for (uint j=0;j<N_Columns;j++)
            line.push_back(defVal);
        value.push_back(line);
    }
}

template <class T> void tableAbstract<T>::setValue(uint row, uint column, T newValue)
{
    try {
        value.at(row).at(column) = newValue;
    } catch (const std::out_of_range &err) {
        cout << err.what() << endl;
    }
}

template <class T> const T tableAbstract<T>::getValue(uint row, uint column)
{
    try {
        return value.at(row).at(column);
    } catch (const std::out_of_range &err) {
        cout << err.what() << endl;
    }
}

template class tableAbstract<bool>;
template class tableAbstract<int>;
template class tableAbstract<long>;
template class tableAbstract<string>;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
userAbstract::userAbstract(string vName, uint numVmBools, uint numVmInts, uint numVmLongs, uint numVmStrings, uint numVmBTables, uint numVmITables, uint numVmLTables, uint numVmSTables) : typeAbstract(vName)
{
    //for (int i=0;i<numVmBools;i++) vmBoolValues.push_back(vmBool());
}

vmBool userAbstract::getBool(string name)
{
//    if (vmBoolValues.size() == 0) throw "Error";
//    for (int i=0; i<vmBoolValues.size(); i++)
}
*/
