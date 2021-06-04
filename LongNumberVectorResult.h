/* Copyright (C) 2021 Bill Rubin
 * Contact: rubin@contractor.net
 *
 * This program is licensed under the MIT license, a copy of which
 * has been provided with this program. You can also find the MIT
 * license at https://OpenSource.org/licenses/MIT
 */

#ifndef LONGNUMBERVECTORRESULT_H
#define LONGNUMBERVECTORRESULT_H

#include <vector>
#include <iostream>

class LongNumberVectorResult {
    public:
        using long_number_type = unsigned long long;
        using LongNumberVector = std::vector<long_number_type>;

        void append(long_number_type longNumber) {longNumberVector_.push_back(longNumber);}
        const LongNumberVector& get() const {return longNumberVector_;}

    private:
        LongNumberVector longNumberVector_;
};

std::ostream& operator<<(std::ostream&, const LongNumberVectorResult&);

#endif
