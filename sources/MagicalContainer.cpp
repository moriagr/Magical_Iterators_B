#include "MagicalContainer.hpp"

namespace ariel {

    MagicalContainer::MagicalContainer(): container(), containerPrime(), containerSide(){ }

    bool MagicalContainer::isPrime(int number){
        bool is_prime = true;

        // 0 and 1 are not prime numbers
        if (number == 0 || number == 1) {
            is_prime = false;
        }

        // loop to check if n is prime
        for (int i = 2; i <= number/2; ++i) {
            if (number % i == 0) {
                is_prime = false;
                return is_prime;
            }
        }
        return is_prime;
    }

    auto MagicalContainer::getElementIterator(int element){
        for (auto i = this->container.begin(); i != this->container.end(); ++i) {
            if (*i  == element) {
                return i;
            }
        }
        return this->container.end() ;
    }

    auto MagicalContainer::getElementPointerIterator(int element, std::vector<int*> containerPointer){
        auto endIterator = containerPointer.end();
        for (auto i = containerPointer.begin(); i != endIterator; ++i) {
            if (**i  == element) {
                return i;
            }
        }
        return endIterator; // Return end iterator if element is not found
    }

    // Helper function to insert an element's pointer at the correct position in containerAscending
    void MagicalContainer::sortOriginalArray(int element) {
        auto position = this->container.begin();
        for (; position != this->container.end(); ++position) {
            if (*position >= element) {
                break;
            }
        }

        // Insert the pointer element at the correct position
        this->container.insert(position, element);
    }

    void MagicalContainer::ChangeContainerSide() {
        this->containerSide.clear();

        if (this->container.empty()) {
            return;
        }

        auto start = this->container.begin();
        auto end = this->container.end() - 1;
        while (start <= end) {
            this->containerSide.push_back(&(*start++));
            if (start <= end) {
                this->containerSide.push_back(&(*end--));
            }
        }
    }

    void MagicalContainer::sortPrimeNumbers() {
        this->containerPrime.clear();

        if (this->container.empty()) {
            return;
        }
        auto start = this->container.begin();
        auto end = this->container.end() - 1;
        while (start <= end) {
            if (isPrime(*start) ){
                this->containerPrime.push_back(&(*start));
            }
            start++;
        }
//        auto position = this->container.begin();
//        for (; position != this->container.end(); ++position) {
//            if (isPrime(*position) ){
//                this->containerPrime.push_back(&(*position));
//            }
//        }
    }

    // Add an element to the container
    void MagicalContainer::addElement(int element) {
        sortOriginalArray(element);
        // Check if element is prime:
        if(isPrime(element)) {
            sortPrimeNumbers();
        }
        // Add element to side cross:
        ChangeContainerSide();
    }

    // Remove an element from the container
    void MagicalContainer::removeElement(int element) {
        auto index = getElementIterator(element);
        if(index != this->container.end()){

            // Remove element:
            this->container.erase(index);

            if(isPrime(element)) {
                sortPrimeNumbers();
            }

            // Remove element to side cross:
            ChangeContainerSide();
        }
        else{
            throw std::runtime_error("No element found");
        }
    }

    // Get the size of the container
    int MagicalContainer::size() const {
        return this->container.size();
    }
}