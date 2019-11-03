#pragma once

#include "interactable.hpp"

class Door: public Interactable
{
    static Texture s_door_texture;

    public:
        // Creates all the associated render resources and default transform
        bool init(int id);

        // set the destination to go to after using door
        void set_destination(std::string dest);

        std::string get_destination();

        Hitbox get_hitbox() const;

        std::string perform_action();

		void lock();

    private:
        bool m_locked;
};
