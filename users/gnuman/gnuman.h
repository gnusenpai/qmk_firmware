#pragma once
#include "quantum.h"
#include "version.h"
#include "wrappers.h"
#include "keys.h"

typedef union {
    uint32_t raw;
    struct {
        unsigned char umode;
    };
} user_config_t;

user_config_t user_config;

enum userspace_layers {
    _PRIMARY = 0,
    _GAME,
    _SECONDARY,
    _EMPTY,
    _GAMEL,
    _LAYER,
    _NAV,
    _NUM,
    _SYM,
    _OPTION,
    _UNICODE
};
