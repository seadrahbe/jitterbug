#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_sprite_ptr.h>
#include <bn_random.h>
#include <bn_vector.h>
#include <bn_keypad.h>

#include "bn_sprite_items_ant.h"

int main() {
    bn::core::init();

    bn::random rng = bn::random();

    bn::backdrop::set_color(bn::color(31, 0, 31));

    bn::vector<bn::sprite_ptr, 50> bugs = {};

    // bn::sprite_ptr ant = bn::sprite_items::ant.create_sprite();

    while(true) {

        for(bn::sprite_ptr& ant : bugs) {  
            bn::fixed new_x = ant.x() + rng.get_fixed(-1, 1);
            bn::fixed new_y = ant.y() + rng.get_fixed(-1, 1);

            ant.set_x(new_x);
            ant.set_y(new_y);
        }

        if(bn::keypad::a_pressed()) {
            bugs.push_back(bn::sprite_items::ant.create_sprite());
        }

        rng.update();
        bn::core::update();
    }
}