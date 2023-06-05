
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

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
        if (this != &other && (typeid(&other) == typeid(this)) ) {
            currentIndex = other.currentIndex;
        }

        else{
            throw std::runtime_error("iterators are pointing at different containers");
        }
        return *this;
    }

    // Move assignment operator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept {
        if (this != &other && (typeid(&other) == typeid(this)) ) {
//            container = other.container;
            currentIndex = other.currentIndex;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const{
        return currentIndex == other.currentIndex;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const{
        return currentIndex != other.currentIndex;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const{
        return currentIndex > other.currentIndex;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const{
        return currentIndex < other.currentIndex;
    }

    int MagicalContainer::AscendingIterator::operator*() const{
        return container.container[static_cast<std::vector<int>::size_type>(currentIndex)];
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++(){
        if(this->begin() != this->end()){
            ++currentIndex;
            return *this;
        }
        throw std::runtime_error("Iterator Increment Beyond End");
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const{
        return AscendingIterator(container, 0);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const{
        return AscendingIterator(container, container.container.size());
    }
} // ariel