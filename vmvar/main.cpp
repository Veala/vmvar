#include <types.h>

void f(typeAbstract *data) {
    switch (data->getType()) {
    case typeAbstract::INT:
        cout << ((vmInt*)data)->getValue(0) << endl;
        break;
    case  typeAbstract::STRING:
        cout << ((vmString*)data)->getValue(0) << endl;
        break;
    case  typeAbstract::INTTABLE:
        cout << ((vmIntTable*)data)->getValue(0,1) << endl;
        break;
    case  typeAbstract::STRINGTABLE:
        cout << ((vmStringTable*)data)->getValue(0,1) << endl;
        break;
    }
}

int main()
{
    vector<typeAbstract*> data;

    typeAbstract *data1 = new vmInt("data1", 7, 1);
    typeAbstract *data2 = new vmIntTable("data2", 8, 3, 3);

    data.push_back(data1);
    data.push_back(data2);

    f(data.at(0));
    f(data.at(1));

    delete data1;
    delete data2;


//    vmIntTable it("it", 123, 2, 10);
//    cout << it.getName() << endl;
//    cout << it.getValue(1,9) << endl;
//    vmIntTable it2(it);
//    cout << it2.getName() << endl;
//    cout << it2.getValue(1,9) << endl;

//    vmInt data("data", 7, 1);
//    cout << data.getName() << endl;
//    cout << data.getValue(0) << endl;
//    vmInt data2(data);
//    cout << data2.getName() << endl;
//    cout << data2.getValue(0) << endl;


//    vmStringTable dataT("dataT", "Igor", 3, 3);
//    cout << dataT.getName() << endl;
//    cout << dataT.getValue(1,1) << endl;

    return 0;
}

