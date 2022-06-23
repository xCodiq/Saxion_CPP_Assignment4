//
// Created by elmar on 21/03/2022.
//

#ifndef CPPASSIGNMENT4_BROKER_H
#define CPPASSIGNMENT4_BROKER_H

#include <vector>
#include "../Message.h"

class Broker {
private:

    std::vector<Message> messages;

public:

    void pushMessage(const Message &message);

    void pushMessage(long targetId, const DeviceType &deviceType, const string &text);

    Message popMessage(long targetId);

    Message peekMessage(long targetId);

    void print() const;

    void print(long targetId) const;

    [[nodiscard]] int count() const;

    [[nodiscard]] int count(long targetId) const;

    [[nodiscard]] int printMessages(long targetId) const;
};


#endif //CPPASSIGNMENT4_BROKER_H
