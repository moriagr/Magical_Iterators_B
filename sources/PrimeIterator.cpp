
#include "MagicalContainer.hpp"

namespace ariel {

    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &cont, int index  ) : container(
            cont), currentIndex(index) {
//        for (auto it = begin(); it != end(); ++it) {
//            std::cout << *it << ' ';  // 2 3 17
//        }
    }

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
        if (this != &other && (typeid(&other) == typeid(this)) ) {
//            container = other.container;
            currentIndex = other.currentIndex;
        }
        else{
            throw std::runtime_error("iterators are pointing at different containers");
        }
        return *this;
    }

    // Move assignment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept {
        if (this != &other && (typeid(&other) == typeid(this)) ) {
//            container = other.container;
            currentIndex = other.currentIndex;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const{
        return currentIndex == other.currentIndex;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const{
        return currentIndex != other.currentIndex;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const{
        return currentIndex > other.currentIndex;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const{
        return currentIndex < other.currentIndex;
    }

    int MagicalContainer::PrimeIterator::operator*() const{
//        cout <<"size:   "<<container.containerPrime.size() <<endl;
//
//        cout << static_cast<std::vector<int>::size_type>(currentIndex)<<"       :      "<<(*container.containerPrime[static_cast<std::vector<int>::size_type>(currentIndex)]) << endl;
//        cout << 1<<"       :      "<<(*container.containerPrime[static_cast<std::vector<int>::size_type>(1)]) << endl;
        return (*container.containerPrime[static_cast<std::vector<int>::size_type>(currentIndex)]);
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++(){
        if(this->begin() != this->end()){
            ++currentIndex;
            return *this;
        }
        throw std::runtime_error("Iterator Increment Beyond End");
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const{
        return PrimeIterator(container, 0);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const{
//        cout <<"size:   "<<container.containerPrime.size() <<endl;
        return PrimeIterator(container, container.containerPrime.size());
    }
} // ariel