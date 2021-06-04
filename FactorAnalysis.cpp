/* Copyright (C) 2021 Bill Rubin
 * Contact: rubin@contractor.net
 *
 * This program is licensed under the MIT license, a copy of which
 * has been provided with this program. You can also find the MIT
 * license at https://OpenSource.org/licenses/MIT
 */

#include "FactorAnalysis.h"
#include "FactorAlgorithm.h"
#include "Task.h"
#include <iostream>

inline void display(const ConstTaskVector<FactorAlgorithm>& tasks) {
    if(tasks.size()==0) return;
    std::cout<<"\nNumber to factor: "<<tasks[0].algorithm()<<"\nFactors:\n";
    for(auto& task : tasks)
        std::cout<<"Task "<<task.taskNumber()<<": "<<*task.result()<<'\n';
}

void analyze(const ConstTaskVector<FactorAlgorithm>& tasks) {
    if(tasks.size()==0) return;
    // Partition tasks into one vector for each long number:
    using AlgorithmList = std::vector<ConstTaskVector<FactorAlgorithm>>;
    AlgorithmList algorithmList;
    algorithmList.reserve(tasks.size());
    for(auto& task : tasks) {
        const FactorAlgorithm::long_number_type number = task.algorithm().longNumber();
        bool makeNewList = true;
        for(auto& list : algorithmList) {
            if(list[0].algorithm().longNumber()==number) {
                list.push_back(task);
                makeNewList = false;
                break;
                }
            }
        if(makeNewList) algorithmList.push_back(ConstTaskVector<FactorAlgorithm>(1, task));
        }

    // Display the vectors sequentially:
    for(auto list : algorithmList) display(list);
}
