#include "gc_pointer.h"
#include "LeakTester.h"

void TestPointerConstructorStoresPointerAndPointerCanBeRetrieved(){
    Pointer<int> p = new int(2);
    assert(*p == 2);
}

void TestEqualOperatorTakesPointerAndPointerCanBeRetrieved(){
    Pointer<int> p;
    p = new int(2);
    assert(*p == 2);
}

void TestPointerValueCanBeChanged(){
    Pointer<int> p;
    p = new int(2);
    assert(*p == 2);
    *p = 3;
    assert(*p == 3);
}

void TestArrayPointerCanBeRetrieved(){
    Pointer<int, 3> p = new int[3]{1,2,3};
    assert(p[2] == 3);
}

void TestCopyConstructorKeepsRefContainerSizeSame(){
    Pointer<int> p = new int(3);
    assert(p.refContainerSize() == 1);
    Pointer<int> p2 = p;
    assert(p.refContainerSize() == 1);
}

void TestEqualOperatorTakesSmartPointerAndPointerCanBeRetrieved(){
    Pointer<int> p = new int(2);
    Pointer<int> p2;
    p2 = p;
    assert(*p2 == 2);
    assert(*p == 2);
}

int main()
{
    TestPointerConstructorStoresPointerAndPointerCanBeRetrieved();
    TestEqualOperatorTakesPointerAndPointerCanBeRetrieved();
    TestPointerValueCanBeChanged();
    TestArrayPointerCanBeRetrieved();
    TestCopyConstructorKeepsRefContainerSizeSame();
    TestEqualOperatorTakesSmartPointerAndPointerCanBeRetrieved();

    return 0;
}