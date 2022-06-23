//
// Created by elmar on 21/03/2022.
//

#ifndef CPPASSIGNMENT4_MESSAGE_H
#define CPPASSIGNMENT4_MESSAGE_H

#include <iostream>

using std::cout, std::cin, std::endl, std::getline, std::ifstream, std::string;

enum DeviceType {
    UNDEFINED = 0x00,
    TEMPERATURE_SENSOR,
    PRESSURE_SENSOR,
    HUMIDITY_SENSOR,
    HEATER,
    AIR_PURIFIER,
    DEV_LAST
};

class Message {
public:
    static const int MSG_LENGTH = 255;

private:
    long messageId, targetId;
    long long timestamp;
    DeviceType deviceType;

    string text;

public:
    Message() = default;

    Message(long targetId, const DeviceType &deviceType, const string &text);

    static long generateMessageId();

    void send() const;

    void updateText(const string &newText);

    [[nodiscard]] bool isValid() const;

    [[nodiscard]] string toString() const;

    [[nodiscard]] long getMessageId() const;

    [[nodiscard]] long getTargetId() const;

    [[nodiscard]] long long getTimestamp() const;
};


#endif //CPPASSIGNMENT4_MESSAGE_H
