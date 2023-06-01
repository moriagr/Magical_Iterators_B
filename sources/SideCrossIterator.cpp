
#include "MagicalContainer.hpp"

namespace ariel {

    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &cont, int index  ) : container(
            cont), currentIndex(index) {}

    // Copy constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer::SideCrossIterator &other) : container(other.container),
                                                                                                               currentIndex(
                                                                                                                       other.currentIndex) {}

    // Move constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &&other) noexcept : container(other.container), currentIndex(other.currentIndex) {
    }

    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){

    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other){
        return *this;
    }

    // Move assignment operator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept {
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const{
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const{
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const{
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const{
        return false;
    }

    int MagicalContainer::SideCrossIterator::operator*() const{
        return 0;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++(){
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const{
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
        return *this;
    }
} // ariel