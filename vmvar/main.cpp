#include <types.h>

int main()
{
    //vmIntArray arr("Yaa", 14, 10);
    //cout << arr.getName() << endl;
    //cout << arr.getValue(12) << endl;

    vmIntTable it("tab", 123, 2, 10);
    cout << it.getName() << endl;
    cout << it.getValue(1,1) << endl;

    //vmIntArray arr("vminarr", 8, 5);
    //arrayAbstract<long> arr("arr", 4, 3);
    //cout << arr.getName() << endl;
    //cout << arr.getValue(1) << endl;

//    vmInt var("XXX", 16);
//    simpleAbstract<int> xxx("YYY", 10);
//    simpleAbstract<long> lll("LLL", 22);
//    cout << var.getName() << endl;
//    cout << var.getValue() << endl;
//    cout << xxx.getName() << endl;
//    cout << xxx.getValue() << endl;
//    cout << lll.getName() << endl;
//    cout << lll.getValue() << endl;


    return 0;
}

