//
// Created by moria on 5/29/23.
//

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <vector>
using namespace std;

namespace ariel {

    class MagicalContainer {
    private:
        std::vector<int> container;
//        std::vector<int*> containerAscending;
        std::vector<int*> containerPrime;
        std::vector<int*> containerSide;

    public:

        MagicalContainer();
        auto getElementIterator(int element);

        void sortOriginalArray(int element);

        void sortPrimeNumbers();

        void ChangeContainerSide();

        void addElement(int element);

        void removeElement(int element);

        int size() const;

        static bool isPrime(int number);

        class AscendingIterator {
        private:
            const MagicalContainer &container;
            int currentIndex;
        public:

            // Default constructor
            AscendingIterator() = delete;
            AscendingIterator(const MagicalContainer &cont, int index = 0);

            // Copy constructor
            AscendingIterator(const AscendingIterator& other);

            // Move constructor
            AscendingIterator(AscendingIterator &&other) noexcept;

            // Destructor
            ~AscendingIterator() = default;

            // Assignment operator
            AscendingIterator &operator=(const AscendingIterator &other);

            // Move assignment operator
            AscendingIterator &operator=(AscendingIterator &&other) noexcept;

            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            int operator*() const;

            AscendingIterator &operator++();

            AscendingIterator begin() const;

            AscendingIterator end() const;
        };

        class SideCrossIterator {
        private:
            const MagicalContainer &container;
            int currentIndex;
        public:

            // Default constructor
            SideCrossIterator() = delete;
            SideCrossIterator(const MagicalContainer &cont, int index = 0);

            // Copy constructor
            SideCrossIterator(const SideCrossIterator& other);

            // Move constructor
            SideCrossIterator(SideCrossIterator &&other) noexcept;

            // Destructor
            ~SideCrossIterator() = default;

            // Assignment operator
            SideCrossIterator &operator=(const SideCrossIterator &other);

            // Move assignment operator
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;

            bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            int operator*() const;

            SideCrossIterator &operator++();

            SideCrossIterator begin() const;

            SideCrossIterator end() const;
        };

        class PrimeIterator {
        private:
            const MagicalContainer &container;
            int currentIndex;
        public:

            // Default constructor
            PrimeIterator() = delete;
            PrimeIterator(const MagicalContainer &cont, int index = 0);

            // Copy constructor
            PrimeIterator(const PrimeIterator& other);

            // Move constructor
            PrimeIterator(PrimeIterator &&other) noexcept;

            // Destructor
            ~PrimeIterator() = default;

            // Assignment operator
            PrimeIterator &operator=(const PrimeIterator &other);

            // Move assignment operator
            PrimeIterator &operator=(PrimeIterator &&other) noexcept;

            bool operator==(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            int operator*() const;

            PrimeIterator &operator++();

            PrimeIterator begin() const;

            PrimeIterator end() const;
        };

    };

} // ariel

