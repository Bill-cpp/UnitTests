#ifndef SUBTRACTALGORITHM_H
#define SUBTRACTALGORITHM_H

#include "Test.h"
#include <memory>
#include <iostream>

class TaskPolicy;

class SubtractAlgorithm {
    public:
        using long_number_type = long long;
        using ResultPtr = std::unique_ptr<long_number_type>;

        SubtractAlgorithm(long_number_type minuend, long_number_type subtrahend)
            : minuend_(minuend), subtrahend_(subtrahend) {}

        ResultPtr operator()(const TaskPolicy&)
            {return std::make_unique<ResultPtr::element_type>(minuend_ - subtrahend_);}

        friend std::ostream& operator<<(std::ostream& os, const SubtractAlgorithm& sa)
            {os<<sa.minuend_<<" - "<<sa.subtrahend_<<" = "; return os;}

    private:
        const long_number_type minuend_;
        const long_number_type subtrahend_;
};

void analyze(const ConstTaskVector<SubtractAlgorithm>& tasks) {
    for(auto& task : tasks)
        std::cout<<"Task "<<task.taskNumber()<<": "
                 <<task.algorithm()<<*task.result()<<'\n';
}

#endif
