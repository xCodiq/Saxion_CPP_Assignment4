//
// Created by elmar on 21/03/2022.
//

#include <sstream>
#include "Message.h"
#include "timestamp/Timestamp.h"

Message::Message(const long targetId, const DeviceType &deviceType, const string &text) :
        messageId(Message::generateMessageId()),
        targetId(targetId),
        timestamp(Timestamp::now()),
        deviceType(deviceType),
        text(text.length() > Message::MSG_LENGTH ? text.substr(0, Message::MSG_LENGTH) : text) {
}

string getDeviceTypeName(DeviceType deviceType) {
    switch (deviceType) {
        default:
        case UNDEFINED:
            return "UNKNOWN";
        case TEMPERATURE_SENSOR:
            return "Temperature Sensor";
        case PRESSURE_SENSOR:
            return "Pressure Sensor";
        case HUMIDITY_SENSOR:
            return "Humidity Sensor";
        case HEATER:
            return "Heater";
        case AIR_PURIFIER:
            return "Air Purifier";
        case DEV_LAST:
            return "Dev Last";
    }
}

long Message::generateMessageId() {
    static long generatedId = 0x0000;
    return ++generatedId;
}

void Message::send() const {
    if (this->isValid()) {
        cout << this->toString() << endl;
    }
}

void Message::updateText(const string &newText) {
    this->text = newText;
}

bool Message::isValid() const {
    return this->deviceType != DeviceType::UNDEFINED && !this->text.empty();
}

string Message::toString() const {
    // Create a new string stream
    std::ostringstream stringStream{};

    // Populate the string stream with the message members
    stringStream << "(" << this->timestamp << ") "
                 << "[M#" << this->messageId << ", "
                 << "T#" << this->targetId << "]["
                 << getDeviceTypeName(this->deviceType) << "]: "
                 << "\"" << this->text << "\"";

    // Convert the string stream to a string
    return stringStream.str();
}

long Message::getMessageId() const {
    return this->messageId;
}

long Message::getTargetId() const {
    return this->targetId;
}

long long Message::getTimestamp() const {
    return this->timestamp;
}


