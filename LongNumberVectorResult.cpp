#include "LongNumberVectorResult.h"

std::ostream& operator<<(std::ostream& os, const LongNumberVectorResult& longNumberVectorResult) {
    for(auto longNumber : longNumberVectorResult.get()) os<<' '<<longNumber;
    return os;
}
