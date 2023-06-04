
#include "MagicalContainer.hpp"

namespace ariel {

    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &cont, int index  ) : container(
            cont), currentIndex(index) {}

    // Copy constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer::SideCrossIterator &other) : container(other.container),
                                                                                                   currentIndex(
                                                                                                           other.currentIndex) {}

    // Move constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &&other) noexcept : container(other.container), currentIndex(other.currentIndex) {}

    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){

    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other){
        if (this != &other) {
//            container = other.container;
            currentIndex = other.currentIndex;
        }
        return *this;
    }

    // Move assignment operator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept {
        if (this != &other) {
//            container = other.container;
            currentIndex = other.currentIndex;
        }
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const{
        return currentIndex == other.currentIndex;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const{
        return currentIndex != other.currentIndex;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const{
        return currentIndex > other.currentIndex;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const{
        return currentIndex < other.currentIndex;
    }

    int MagicalContainer::SideCrossIterator::operator*() const{
        return *container.containerSide[static_cast<std::vector<int>::size_type>(currentIndex)];
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++(){
        ++currentIndex;
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const{
        return SideCrossIterator(container, 0);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
        return SideCrossIterator(container, container.containerSide.size());
    }
} // ariel