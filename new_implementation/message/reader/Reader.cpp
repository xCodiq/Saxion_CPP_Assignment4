//
// Created by elmar on 21/03/2022.
//

#include "Reader.h"

Reader::Reader(const string &fileName) : inputStream({fileName}) {
}

bool Reader::hasNext() {
    return !this->inputStream.fail() && !this->inputStream.eof();
}

Message Reader::next() {
    // If there is no next, return an empty Message object
    if (!this->hasNext()) return {};

    string nextLine{};
    std::getline(this->inputStream, nextLine);

    auto targetIdPosition = nextLine.find(' ');
    if (targetIdPosition == string::npos) return {};
    long targetId = std::stol(nextLine.substr(0, targetIdPosition));

    auto deviceTypePosition = nextLine.find(' ', targetIdPosition + 1);
    DeviceType deviceType = Reader::parseDeviceType(nextLine.substr(targetIdPosition + 1, deviceTypePosition - (targetIdPosition + 1)));

    string text = nextLine.substr(deviceTypePosition + 1);

    return {targetId, deviceType, text};
}

DeviceType Reader::parseDeviceType(const string &deviceTypeStr) {
    if (deviceTypeStr == "temperature_sensor") return TEMPERATURE_SENSOR;
    if (deviceTypeStr == "pressure_sensor") return PRESSURE_SENSOR;
    if (deviceTypeStr == "humidity_sensor") return HUMIDITY_SENSOR;
    if (deviceTypeStr == "heater") return HEATER;
    if (deviceTypeStr == "air_purifier") return AIR_PURIFIER;
    if (deviceTypeStr == "dev_last") return DEV_LAST;
    return UNDEFINED;
}
