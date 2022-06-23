//
// Created by elmar on 21/03/2022.
//

#ifndef CPPASSIGNMENT4_READER_H
#define CPPASSIGNMENT4_READER_H

#include "../Message.h"
#include <fstream>

class Reader {
private:

    std::ifstream inputStream;

public:

    Reader(const string &fileName);

    bool hasNext();

    Message next();

private:
    static DeviceType parseDeviceType(const string &deviceTypeStr);
};


#endif //CPPASSIGNMENT4_READER_H
