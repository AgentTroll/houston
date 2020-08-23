#include "body_model.h"

void houston::body_model::update_motion(double time_step) {
    x += vx * time_step;
    y += vy * time_step;
    z += vz * time_step;
}

double houston::body_model::get_x() const {
    return x;
}

double houston::body_model::get_y() const {
    return y;
}

double houston::body_model::get_z() const {
    return z;
}

double houston::body_model::get_vx() const {
    return vx;
}

double houston::body_model::get_vy() const {
    return vy;
}

double houston::body_model::get_vz() const {
    return vz;
}

void houston::body_model::set_velocity(double in_vx, double in_vy, double in_vz) {
    vx = in_vx;
    vy = in_vy;
    vz = in_vz;
}
