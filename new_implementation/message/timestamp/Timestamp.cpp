//
// Created by elmar on 21/03/2022.
//

#include "Timestamp.h"
#include <ctime>

long long Timestamp::now() {
    time_t ts = time(nullptr);
    return (long long) ts;
}
