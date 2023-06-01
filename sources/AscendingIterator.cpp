
#include "MagicalContainer.hpp"

namespace ariel {

    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &cont, int index  ) : container(
            cont), currentIndex(index) {}

    // Copy constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator &other) : container(other.container),
                                                                                 currentIndex(
                                                                                         other.currentIndex) {}

    // Move constructor
    MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &&other) noexcept : container(other.container), currentIndex(other.currentIndex) {
    }

    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator(){

    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other){
        return *this;
    }

    // Move assignment operator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept {
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const{
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const{
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const{
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const{
        return false;
    }

    int MagicalContainer::AscendingIterator::operator*() const{
        return 0;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++(){
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const{
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const{
        return *this;
    }
} // ariel