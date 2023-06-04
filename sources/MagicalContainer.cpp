
#include "MagicalContainer.hpp"
#include <algorithm>

namespace ariel {

    MagicalContainer::MagicalContainer(): container(), containerAscending(), containerPrime(), containerSide(){ }

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
            cout<<(**i)  <<":"<< element<<endl;
            if (**i  == element) {
                return i;
            }
        }
        return endIterator; // Return end iterator if element is not found
    }

    // Helper function to insert an element's pointer at the correct position in containerAscending
    void MagicalContainer::insertElementPointerAscending(int* element) {
        // Find the correct insertion position in containerAscending
//        if(this->containerAscending.begin() == this->containerAscending.end() || this->containerAscending.size()==0){
            this->containerAscending.push_back(element);
            return;
//        }
//        auto position = containerAscending.begin();
//        for (; position != containerAscending.end(); ++position) {
//            if (**position >= *element) {
//                break;
//            }
//        }
//
//        // Insert the pointer element at the correct position
//        containerAscending.insert(position, element);
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


    // Add an element to the container
    void MagicalContainer::addElement(int element) {
        if(container.empty()){
            this->containerAscending.clear();
        }
        this->container.push_back(element);

        // Check if element is prime:
        if(isPrime(this->container.back())){
            this->containerPrime.push_back(&this->container.back());
        }

        // Add element to ascending:
       // Add the pointer to the element to the containerAscending vector
        auto position = std::lower_bound(containerAscending.begin(), containerAscending.end(), &container.back(),
                                         [](const int* a, const int* b) {
                                             return *a < *b;
                                         });
        containerAscending.insert(position, &container.back());

        // Add element to side cross:
        ChangeContainerSide();
    }

    // Remove an element from the container
    void MagicalContainer::removeElement(int element) {
        auto index = getElementIterator(element);
        if(index != this->container.end()){
            auto it = getElementPointerIterator(element, this->containerAscending);

//            auto it = std::find(this->containerAscending.begin(), this->containerAscending.end(), element);
            if (it != this->containerAscending.end()) {
                this->containerAscending.erase(it);
            }

            // Check if element is prime:
            if(isPrime(element)){
                auto it = getElementPointerIterator(element, this->containerPrime);
//                auto it = std::find(this->containerPrime.begin(), this->containerPrime.end(), &element);
                if (it != this->containerPrime.end()) {
                    this->containerPrime.erase(it);
                }
            }

            // Remove element to ascending:
            this->container.erase(index);

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
} // ariel