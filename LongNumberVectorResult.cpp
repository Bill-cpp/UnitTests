/* Copyright (C) 2021 Bill Rubin
 * Contact: rubin@contractor.net
 *
 * This program is licensed under the MIT license, a copy of which
 * has been provided with this program. You can also find the MIT
 * license at https://OpenSource.org/licenses/MIT
 */

#include "LongNumberVectorResult.h"

std::ostream& operator<<(std::ostream& os, const LongNumberVectorResult& longNumberVectorResult) {
    for(auto longNumber : longNumberVectorResult.get()) os<<' '<<longNumber;
    return os;
}
