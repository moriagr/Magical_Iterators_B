#include "MagicalContainer.hpp"

namespace ariel {

    MagicalContainer::MagicalContainer(): container(), containerPrime(), containerSide(){ }

    // This function checks if the given number is prime.
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

    // This function gets the pointer to the given element in the container vector.
    auto MagicalContainer::getElementIterator(int element){
        for (auto i = this->container.begin(); i != this->container.end(); ++i) {
            if (*i  == element) {
                return i;
            }
        }
        return this->container.end() ;
    }

    // This function insert the element into the container array according to the ascending order.
    void MagicalContainer::sortOriginalArray(int element) {
        auto position = this->container.begin();

        // This loop goes over the container vector with complexity of O(n).
        // It finds the pointer that points to the first value that is bigger or equal to the given element.
        for (; position != this->container.end(); ++position) {
            if (*position >= element) {
                break;
            }
        }

        // Insert the pointer element at the correct position
        this->container.insert(position, element);
    }

    // This function goes over the container element and organize the containerSide vector,
    // So it will contain pointers to the values in the cross side order.
    void MagicalContainer::ChangeContainerSide() {
        this->containerSide.clear();

        if (this->container.empty()) {
            return;
        }

        auto start = this->container.begin();
        auto end = this->container.end() - 1;

        // This loop goes over the container, it takes the first -> last ->second first-> second last and so on
        while (start <= end) {
            this->containerSide.push_back(&(*start++));
            if (start <= end) {
                this->containerSide.push_back(&(*end--));
            }
        }
    }

    // This function goes over the container element and organize the containerPrime vector,
    // So it will contain pointers to the values that are prime numbers from the container vector.
    void MagicalContainer::sortPrimeNumbers() {
        this->containerPrime.clear();

        if (this->container.empty()) {
            return;
        }
        auto start = this->container.begin();
        auto end = this->container.end() - 1;
        while (start <= end) {
            // Check if the start pointer, points to a number.
            // if it does, it adds the reference to the containerPrime vector.
            if (isPrime(*start) ){
                this->containerPrime.push_back(&(*start));
            }
            start++;
        }
    }

    // Add an element to the container
    void MagicalContainer::addElement(int element) {

        // Add an element to the container, in the correct place.
        sortOriginalArray(element);

        // Add element to prime:
        sortPrimeNumbers();

        // Add element to side cross:
        ChangeContainerSide();
    }

    // Remove an element from the container
    void MagicalContainer::removeElement(int element) {
        auto index = getElementIterator(element);
        if(index != this->container.end()){

            // Remove element from the original container:
            this->container.erase(index);

            // Remove element from side cross:
            sortPrimeNumbers();

            // Remove element from side cross:
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