#include <iostream>
#include "message/Message.h"
#include "message/broker/Broker.h"
#include "message/reader/Reader.h"

int main() {
//    Message message0{123, DeviceType::AIR_PURIFIER, "SET ON"};
//    Message message1{234, DeviceType::TEMPERATURE_SENSOR, "SET ON"};
//    Message message2{123, DeviceType::AIR_PURIFIER, "SET OFF"};
//    Message message3{123, DeviceType::AIR_PURIFIER, "SET ON"};
//    Message message4{234, DeviceType::TEMPERATURE_SENSOR, "MEASURE"};
//    Message message5{123, DeviceType::AIR_PURIFIER, "SET MODE PURIFY"};
//    Message message6{321, DeviceType::HEATER, "SET ON"};

    Reader reader{"messages.in"};
    Broker broker{};

    while (reader.hasNext()) {
        broker.pushMessage(reader.next());
    }

    cout << "Total messages: " << broker.count() << endl;

    broker.popMessage(324).send();

    cout << "Total messages: " << broker.count() << endl;


    return 0;
}
