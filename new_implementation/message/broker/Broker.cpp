//
// Created by elmar on 21/03/2022.
//

#include "Broker.h"

void Broker::pushMessage(const Message &message) {
    this->messages.push_back(message);
}

void Broker::pushMessage(long targetId, const DeviceType &deviceType, const string &text) {
    this->pushMessage({targetId, deviceType, text});
}

Message Broker::popMessage(long targetId) {
    int index = 0;
    for (Message &message: this->messages) {
        if (message.getTargetId() == targetId) {
            Message messageCopy = message;
            this->messages.erase(this->messages.begin() + index);
            return messageCopy;
        }

        index++;
    }

    // Return an empty Message object
    return {};
}

Message Broker::peekMessage(long targetId) {
    for (const auto &message: this->messages) {
        if (message.getTargetId() == targetId) {
            return message;
        }
    }

    // Return an empty Message object
    return {};
}

void Broker::print() const {
    for (const Message &message: this->messages) message.send();
}

void Broker::print(long targetId) const {
    for (const Message &message: this->messages) {
        if (message.getTargetId() == targetId) {
            message.send();
            return;
        }
    }
}

int Broker::count() const {
    return (int) this->messages.size();
}

int Broker::count(long targetId) const {
    int messageCount = 0;

    for (const auto &message: this->messages) {
        if (message.getTargetId() == targetId) messageCount++;
    }

    return messageCount;
}

int Broker::printMessages(long targetId) const {
    if (targetId == 0) {
        for (const auto &message: this->messages) message.send();
        return (int) this->messages.size();
    }

    int messagesPrinted = 0;
    for (const auto &message: this->messages) {
        if (message.getTargetId() == targetId) {
            message.send();
            messagesPrinted++;
        }
    }

    return messagesPrinted;
}
