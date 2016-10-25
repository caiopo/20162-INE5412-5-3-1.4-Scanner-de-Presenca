#include "basics.h"
#include <nic.h>

class SerialAlert {
public:
    void alert(size_t i, size_t j, Distance before, Distance after) {
        cout << "Presence detected!" <<
            "\ni: " << i <<
            "\nj: " << j <<
            "\nbefore: " << before <<
            "\nafter: " << after << "\n\n";
    }
};

class RadioAlert {
public:
    void alert(size_t i, size_t j, Distance before, Distance after) {

    }
};
