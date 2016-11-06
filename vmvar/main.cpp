#include <types.h>

int main()
{
    vector<typeAbstract> data;

    vmInt data1("data1", 7, 1);
    vmIntTable data2("data2", 8, 3, 3);

    data.push_back(data1);
    data.push_back(data2);
    cout << ((vmInt)(data.at(0))).getValue(0) << endl;
    cout << ((vmIntTable)data.at(1)).getValue(0,0) << endl;

//    vector<typeAbstract*> data;

//    typeAbstract *data1 = new vmInt("data1", 7, 1);
//    typeAbstract *data2 = new vmIntTable("data2", 8, 3, 3);

//    data.push_back(data1);
//    data.push_back(data2);
//    cout << ((vmInt*)data.at(0))->getValue(0) << endl;
//    cout << ((vmIntTable*)data.at(1))->getValue(0,0) << endl;

//    delete data1;
//    delete data2;


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

