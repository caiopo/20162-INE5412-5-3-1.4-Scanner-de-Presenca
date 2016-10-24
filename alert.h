#include "basics.h"

class Alert {
public:
    void alert(size_t i, size_t j, Distance before, Distance after);
};

class SerialAlert : public Alert {
public:
    void alert(size_t i, size_t j, Distance before, Distance after) {

    }
};

class RadioAlert : public Alert {
public:
    void alert(size_t i, size_t j, Distance before, Distance after) {

    }
};
