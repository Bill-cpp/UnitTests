#include "Test.h"
#include "FactorAlgorithm.h"
#include "SubtractAlgorithm.h"
#include "FactorAnalysis.h"

int main1() {
    Test test;
    test.fill(FactorAlgorithm());
    test.run();
    analyze(test.tasks<FactorAlgorithm>());
    return 0;
}

int main2() {
    Test test;
    test.fill(FactorAlgorithm());
    test.run(false);
    analyze(test.tasks<FactorAlgorithm>());
    return 0;
}

int main3() {
    Test test(1);
    test.fill(FactorAlgorithm());
    test.run();
    analyze(test.tasks<FactorAlgorithm>());
    return 0;
}

int main4() {
    Test test(3);
    test.fill(FactorAlgorithm(0x80'00'00'00 - 1));
    test.run();
    analyze(test.tasks<FactorAlgorithm>());
    return 0;
}

int main5() {
    Test test;
    test.add(FactorAlgorithm(123456789), 3);
    test.add(FactorAlgorithm(2147483647), 2);
    test.fill(FactorAlgorithm(1073741824));
    test.run();
    analyze(test.tasks<FactorAlgorithm>());
    return 0;
}

int main6() {
    Test test;
    test.add(SubtractAlgorithm(61, 31), 2);
    test.add(SubtractAlgorithm(29, 61));
    test.add(FactorAlgorithm(123456789), 2);
    test.fill(SubtractAlgorithm(13, 7));
    test.run();
    analyze(test.tasks<FactorAlgorithm>());
    analyze(test.tasks<SubtractAlgorithm>());
    return 0;
}

int main() {
    main3();
    return 0;
}

/*
 * Output from executing main1():

Number to factor: 123456789
Factors:
Task 0:  3 3 3607 3803
Task 1:  3 3 3607 3803
Task 2:  3 3 3607 3803
Task 3:  3 3 3607 3803
Task 4:  3 3 3607 3803
Task 5:  3 3 3607 3803
Task 6:  3 3 3607 3803
Task 7:  3 3 3607 3803
*/
