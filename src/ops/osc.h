#pragma once

#include "target.h"

#include <lo/lo.h>
#include <lo/lo_cpp.h>

inline bool broadcast_OSC(const Target& _target, const std::string& _folder, float _value) {
    lo_message m = lo_message_new();
    lo_message_add_float(m, _value);

    lo_address t = lo_address_new(_target.address.c_str(), _target.port.c_str());

    lo_send_message(t, std::string(_target.folder + _folder).c_str(), m);
    lo_address_free(t);
    lo_message_free(m);

    return true;
}

inline bool broadcast_OSC(const Target& _target, const std::string& _folder, const std::string& _value) {
    lo_message m = lo_message_new();
    lo_message_add_string(m, _value.c_str());

    lo_address t = lo_address_new(_target.address.c_str(), _target.port.c_str());

    lo_send_message(t, std::string(_target.folder + _folder).c_str(), m);
    lo_address_free(t);
    lo_message_free(m);

    return true;
}