#include "Test.h"
#include "FactorAlgorithm.h"
#include "FactorAnalysis.h"
#include <cassert>

void unitTests() {
    const TaskPolicy taskPolicy(8, 3, std::launch::async);
    std::cout<<"TaskPolicy:\n"<<taskPolicy<<'\n';
    const FactorAlgorithm factorAlgorithm;
    std::cout<<"FactorAlgorithm:  "<<factorAlgorithm<<'\n';
    LongNumberVectorResult longNumberVectorResult;
    longNumberVectorResult.append(3);
    longNumberVectorResult.append(4);
    std::cout<<"LongNumberVectorResult: "<<longNumberVectorResult<<'\n';

    Task<FactorAlgorithm> task(factorAlgorithm, 4);
    task.start(taskPolicy);
    task.waitForCompletion();
    std::cout<<"Algorithm: "<<task.algorithm()<<'\n';
    std::cout<<"Result: "<<*task.result()<<'\n';
    const AbstractTask* at = static_cast<AbstractTask*>(&task);
    const Task<FactorAlgorithm>* ft = at->downcast<FactorAlgorithm>();
    std::cout<<"Result from base class: "<<*ft->result()<<"\n\n";
  //Task<FactorAlgorithm> task2(std::move(task));
    ConstTask<FactorAlgorithm> constTask(ft);
    std::cout<<"Instantiated ConstTask\n";
    std::cout<<"Algorithm: "<<constTask.algorithm()<<'\n';
    std::cout<<"Task "<<constTask.taskNumber()<<'\n';
    std::cout<<"Result: "<<*constTask.result()<<'\n';
}

int mainO() {
    unitTests();
    FactorAlgorithm factorAlgorithm(123456789);
    std::cout<<"Before Test test(TestPolicy(false, 1));\n";
    //Test test; //(TestPolicy(true, 1));
    Test test;
    assert(!test.fill(factorAlgorithm));
    std::cout<<"Before test.fill(FactorAlgorithm(123456789));\n";
    assert(test.fill(FactorAlgorithm(0x80'00'00'00 - 1)));
    std::cout<<"Before test.run();\n";
    assert(!test.run());
    std::cout<<"Before analyzeFactor(test);\n\n";
    analyze(test.tasks<FactorAlgorithm>());
    try {Test badTest(false);}
    catch (std::exception& e) {std::cout<<"Exception caught: "<<e.what()<<'\n';}
    std::cout<<"\nBefore instantiating test2 ...\n";
    Test test2(3);
    assert(!test2.fill(factorAlgorithm));
    assert(test2.fill(factorAlgorithm));
    assert(test2.incrementNumSlots(0));
    assert(!test2.incrementNumSlots(4));
    assert(test2.run());
    assert(!test2.fill(factorAlgorithm));
    assert(!test2.run());
    analyze(test2.tasks<FactorAlgorithm>());
    return 0;
}
