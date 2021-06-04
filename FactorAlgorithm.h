/* Copyright (C) 2021 Bill Rubin
 * Contact: rubin@contractor.net
 *
 * This program is licensed under the MIT license, a copy of which
 * has been provided with this program. You can also find the MIT
 * license at https://OpenSource.org/licenses/MIT
 */

#ifndef FACTORALGORITHM_H
#define FACTORALGORITHM_H

#include "LongNumberVectorResult.h"
#include "Debug_Tasks.h"
#include <memory>

class TaskPolicy;

class FactorAlgorithm {
    public:
        using ResultPtr = std::unique_ptr<LongNumberVectorResult>;
        using long_number_type = typename LongNumberVectorResult::long_number_type;

        FactorAlgorithm(const long_number_type = 123456789);
        DEBUG_TASKS(FactorAlgorithm(const FactorAlgorithm&));
        ResultPtr operator()(const TaskPolicy&);
        long_number_type longNumber() const {return number_;}

    private:
        const long_number_type number_;
};

std::ostream& operator<<(std::ostream&, const FactorAlgorithm&);

#endif
