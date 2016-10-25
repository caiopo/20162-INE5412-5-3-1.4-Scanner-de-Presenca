#include "basics.h"

class DistanceMatrix {
private:

    size_t _height, _width;
    Distance* data;
    Distance max_error;
    bool comparison;

    bool lt_error(Distance d1, Distance d2) {
        auto max = d1 > d2 ? d1 : d2;
        auto min = d1 < d2 ? d1 : d2;

        return (max - min) > max_error;
    }

public:
    DistanceMatrix(size_t height, size_t width, Distance _max_error):
        _height{height}, _width{width},
        data{new Distance[_height * _width]},
        max_error{_max_error},
        comparison{false}
    {}

    Distance get(size_t i, size_t j) {
        return data[i * _width + j];
    }

    Distance* put(size_t i, size_t j, Distance dist) {
        auto index = i * _width + j;

        Distance* before = (comparison && lt_error(data[index], dist)) ?
            &data[index] : nullptr;

        data[index] = dist;

        return before;
    }

    void enable_comparison() {
        comparison = true;
    }

    void disable_comparison() {
        comparison = false;
    }

    size_t height() {
        return _height;
    }

    size_t width() {
        return _width;
    }

    void print() {
        for (size_t i = 0; i < width(); ++i) {
            for (size_t j = 0; j < height(); ++j) {

                cout << get(i, j) << ' ';

            }
            cout << '\n';
        }
    }
};
