
#include "MagicalContainer.hpp"

namespace ariel {

    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &cont, int index  ) : container(
            cont), currentIndex(index) {}

    // Copy constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator &other) : container(other.container),
                                                                                                               currentIndex(
                                                                                                                       other.currentIndex) {}

    // Move constructor
    MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &&other) noexcept : container(other.container), currentIndex(other.currentIndex) {
    }

    // Destructor
    MagicalContainer::PrimeIterator::~PrimeIterator(){

    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other){
        return *this;
    }

    // Move assignment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept {
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const{
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const{
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const{
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const{
        return false;
    }

    int MagicalContainer::PrimeIterator::operator*() const{
        return 0;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++(){
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const{
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const{
        return *this;
    }
} // ariel