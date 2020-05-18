#include "gnuman.h"

void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.umode = 0;
    eeconfig_update_user(user_config.raw);
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}
