#include "types.h"

void f(typeAbstract* data) {
    switch (data->getType()) {
    case typeAbstract::BOOL:
        cout << ((vmBool*)data)->getValue(0) << endl;
        break;
    case typeAbstract::INT:
        cout << ((vmInt*)data)->getValue(0) << endl;
        break;
    case typeAbstract::LONG:
        cout << ((vmLong*)data)->getValue(0) << endl;
        break;
    case typeAbstract::FLOAT:
        cout << ((vmFloat*)data)->getValue(0) << endl;
        break;
    case  typeAbstract::STRING:
        cout << ((vmString*)data)->getValue(0) << endl;
        break;
    case  typeAbstract::BOOLTABLE:
        cout << ((vmBoolTable*)data)->getValue(0,1) << endl;
        break;
    case  typeAbstract::INTTABLE:
        cout << ((vmIntTable*)data)->getValue(0,1) << endl;
        break;
    case  typeAbstract::LONGTABLE:
        cout << ((vmLongTable*)data)->getValue(0,1) << endl;
        break;
    case  typeAbstract::FLOATTABLE:
        cout << ((vmFloatTable*)data)->getValue(0,1) << endl;
        break;
    case  typeAbstract::STRINGTABLE:
        cout << ((vmStringTable*)data)->getValue(0,1) << endl;
        break;
    case  typeAbstract::VMUSER:
        cout << ((userAbstract*)data)->getName() << endl;
        break;
    }
}

int main()
{
    userAbstract userVal("userVal");
    typeAbstract *data1 = new vmInt("data1", 7, 1);
    typeAbstract *data2 = new vmIntTable("data2", 8, 3, 3);
    ((vmInt*)data1)->setValue(0, 17);
    ((vmIntTable*)data2)->setValue(0, 1, 18);
    userVal.addVar(data1);
    userVal.addVar(data2);
    typeAbstract *value = userVal.getVar("data1", typeAbstract::INT);
    if (value!=0) {
        f(value);
    }
    value = userVal.getVar("data2", typeAbstract::INTTABLE);
    if (value!=0) {
        f(value);
    }

    typeAbstract *data3 = new vmInt("data3", 21, 1);
    typeAbstract *data4 = new vmIntTable("data4", 42, 4, 4);
    userAbstract *uv = new userAbstract("uv");
    uv->addVar(data3);
    uv->addVar(data4);
    uv->addVar(&userVal);

    delete (vmInt*)data3; delete (vmIntTable*)data4;

    userAbstract *uVal = uv->clone();

    delete uv;

    value = uVal->getVar("data3", typeAbstract::INT);
    if (value!=0) {
        f(value);
    }
    value = uVal->getVar("data4", typeAbstract::INTTABLE);
    if (value!=0) {
        f(value);
    }
    value = uVal->getVar("userVal.data1", typeAbstract::INT);
    if (value!=0) {
        f(value);
    }
    value = uVal->getVar("userVal.data2", typeAbstract::INTTABLE);
    if (value!=0) {
        f(value);
    }
    value = uVal->getVar("userVal", typeAbstract::VMUSER);
    if (value!=0) {
        f(value);
    }

    delete uVal;

//    value = uv->getVar("data3", typeAbstract::INT);
//    if (value!=0) {
//        f(value);
//    }
//    value = uv->getVar("data4", typeAbstract::INTTABLE);
//    if (value!=0) {
//        f(value);
//    }
//    value = uv->getVar("userVal.data1", typeAbstract::INT);
//    if (value!=0) {
//        f(value);
//    }
//    value = uv->getVar("userVal.data2", typeAbstract::INTTABLE);
//    if (value!=0) {
//        f(value);
//    }


    //delete data1;
    //delete data2;

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

