#include "types.h"

//---------------------------------------------------------------------------------------------------------------------------------

template <class T> arrayAbstract<T>::arrayAbstract(string vName, T defVal, uint N) : typeAbstract(vName)
{
    for (unsigned i=0;i<N;i++) value.push_back(defVal);
}

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
template class arrayAbstract<bool>;
template class arrayAbstract<int>;
template class arrayAbstract<long>;
template class arrayAbstract<string>;

//---------------------------------------------------------------------------------------------------------------------------------

template <class T> tableAbstract<T>::tableAbstract(string vName, T defVal, uint N_Rows, uint N_Columns) : typeAbstract(vName)
{
    for (uint i=0;i<N_Rows;i++) {
        vector<T> *line;
        value.push_back(line);
        for (uint j=0;j<N_Columns;j++) {
            line->push_back(defVal);
        }
    }

    cout << "dadada" << endl;
}

template <class T> void tableAbstract<T>::setValue(uint row, uint column, T newValue)
{
    try {
        value[1].
        (value[row])->at(column) = newValue;
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
template class tableAbstract<bool>;
template class tableAbstract<int>;
template class tableAbstract<long>;
template class tableAbstract<string>;
