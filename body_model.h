#ifndef HOUSTON_BODY_MODEL_H
#define HOUSTON_BODY_MODEL_H

namespace houston {
    /**
     * Models some physical body with a position and
     * velocity vector.
     */
    class body_model {
    private:
        double x{0};
        double y{0};
        double z{0};

        double vx{0};
        double vy{0};
        double vz{0};
    public:
        /**
         * Updates the position based on the current
         * velocity of the model.
         *
         * @param time_step the time over which the
         * constant velocity is applied
         */
        void update_motion(double time_step);

        /**
         * Obtains the current X position of the body.
         *
         * @return the X position
         */
        double get_x() const;

        /**
         * Obtains the current Y position of the body.
         *
         * @return the Y position
         */
        double get_y() const;

        /**
         * Obtains the current Y position of the body.
         *
         * @return the Y position
         */
        double get_z() const;

        /**
         * Obtains the current X velocity of the body.
         *
         * @return the X velocity
         */
        double get_vx() const;

        /**
         * Obtains the current Y velocity of the body.
         *
         * @return the Y velocity
         */
        double get_vy() const;

        /**
         * Obtains the current Z velocity of the body.
         *
         * @return the Z velocity
         */
        double get_vz() const;

        /**
         * Updates the velocity vector of the body to match
         * the given new input components. This performs no
         * updates to the position.
         *
         * @param in_vx the input X velocity
         * @param in_vy the input Y velocity
         * @param in_vz the input Z velocity
         */
        void set_velocity(double in_vx, double in_vy, double in_vz);
    };
}

#endif // HOUSTON_BODY_MODEL_H
