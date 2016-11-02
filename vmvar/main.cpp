#include <types.h>

int main()
{
    vmIntTable it("it", 123, 2, 10);
    cout << it.getName() << endl;
    cout << it.getValue(1,9) << endl;
    vmIntTable it2(it);
    cout << it2.getName() << endl;
    cout << it2.getValue(1,9) << endl;


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

