#include "FactorAlgorithm.h"

DEBUG_TASKS(std::time_t now() {return  std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())%100;})

FactorAlgorithm::FactorAlgorithm(const long_number_type number)
    : number_(number) {DEBUG_TASKS(std::cout<<"FactorAlgorithm created at "<<now()<<std::endl;)}

DEBUG_TASKS(FactorAlgorithm::FactorAlgorithm(const FactorAlgorithm& a) : number_(a.number_)
            {std::cout<<"FactorAlgorithm copied at "<<now()<<std::endl;})

// A deliberately non-optimized way of factoring a number:
FactorAlgorithm::ResultPtr FactorAlgorithm::operator()(const TaskPolicy& DEBUG_TASKS(taskPolicy)) {
    DEBUG_TASKS(std::cout<<"FactorCommand task "<<taskPolicy.taskNumber()<<" executing at "<<now()<<std::endl;)
    auto factors = std::make_unique<ResultPtr::element_type>();
    long_number_type number = number_;
    // Try dividing by every possible number up to what remains to be factored:
    for(long_number_type factor = 2; factor<=number; ++factor) if (number%factor==0) {
        factors->append(factor);
        number /= factor;
        --factor;
        }
    return factors;
}

std::ostream& operator<<(std::ostream& os, const FactorAlgorithm& factorAlgorithm) {
    os<<factorAlgorithm.longNumber();
    return os;
}
