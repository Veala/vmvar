#include <types.h>

int main()
{
    vmIntArray arr("arr", 14, 10);
    cout << arr.getName() << endl;
    cout << arr.getValue(9) << endl;
    arr.setValue(10, 5);
    cout << arr.getValue(9) << endl;

    vmIntTable it("it", 123, 2, 10);
    cout << it.getName() << endl;
    cout << it.getValue(1,9) << endl;

    vmInt data("data", 7);
    cout << data.getName() << endl;
    cout << data.getValue() << endl;

    vmStringTable dataT("dataT", "Igor", 3, 3);
    cout << dataT.getName() << endl;
    cout << dataT.getValue(1,1) << endl;

    return 0;
}

