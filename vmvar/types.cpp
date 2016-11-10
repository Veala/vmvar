#include "types.h"

template <class T> simpleAbstract<T>::simpleAbstract(string vName, T defVal, uint N) : typeAbstract(vName)
{
    for (uint i=0;i<N;i++) value.push_back(defVal);
}

template <class T> simpleAbstract<T>::simpleAbstract(simpleAbstract &data) : typeAbstract(data.varName)
{
    for (uint i=0;i<data.value.size();i++) value.push_back(data.value.at(i));
    type = data.getType();
}

template <class T> void simpleAbstract<T>::setValue(uint index, T newValue)
{
    try {
        value.at(index) = newValue;
    } catch (const std::out_of_range &err) {
        cout << err.what() << endl;
    }
}

template <class T> T simpleAbstract<T>::getValue(uint index)
{
    try {
        return value.at(index);
    } catch (const std::out_of_range &err) {
        cout << err.what() << endl;
    }
}

template class simpleAbstract<bool>;
template class simpleAbstract<int>;
template class simpleAbstract<long>;
template class simpleAbstract<float>;
template class simpleAbstract<string>;

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

template <class T> tableAbstract<T>::tableAbstract(tableAbstract &data) : typeAbstract(data.varName)
{
    for (uint i=0;i<data.value.size();i++) {
        vector<T> line;
        for (uint j=0;j<data.value.at(i).size();j++)
            line.push_back(data.getValue(i,j));
        value.push_back(line);
    }
    type = data.getType();
}

template <class T> void tableAbstract<T>::setValue(uint row, uint column, T newValue)
{
    try {
        value.at(row).at(column) = newValue;
    } catch (const std::out_of_range &err) {
        cout << err.what() << endl;
    }
}

template <class T> T tableAbstract<T>::getValue(uint row, uint column)
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
template class tableAbstract<float>;
template class tableAbstract<string>;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

