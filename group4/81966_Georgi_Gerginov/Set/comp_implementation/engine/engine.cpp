#include "engine.h"

Engine::Engine(const unsigned int& serialnum) : m_serialnum{serialnum} {}

const short int Engine::compareTo(Comparable* other) const {
    Engine* pt_to_eng{dynamic_cast<Engine*>(other)};

    if(m_serialnum < pt_to_eng -> m_serialnum) {
        return -1;
    } else if(m_serialnum == pt_to_eng -> m_serialnum) {
        return 0;
    }

    return 1;
}

const unsigned int Engine::get_data() const {
    return m_serialnum;
}