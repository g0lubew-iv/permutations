//
// Created by one_eyed_john on 27/06/23.
//

#ifndef PERMUTATION_PERMUTATIONS_HPP
#define PERMUTATION_PERMUTATIONS_HPP

#include <sstream>
#include <ranges>

template<std::ranges::input_range Container>
// Define permutation for any possible container
class Permutation {
public:
    using Iterator = std::ranges::iterator_t<Container>;
    using Type = Container::value_type;

public:
    Permutation(Iterator start, Iterator fin) : begin(start), end(fin) {
        length = static_cast<std::size_t>(end - begin);
    }

    Permutation(const Permutation &other) = default;

    Permutation(Permutation &&other) noexcept = default;

    Permutation &operator=(const Permutation &other) {
        *this(other);
        return *this;
    }

    Permutation &operator=(Permutation &&other) = delete;

    ~Permutation() = default;

    // NOTE: indexing starts from 1. Maths...
    Type &operator[](const std::size_t &index) {
        if ((index <= 0) || (index > length)) {
            throw std::out_of_range("Going out of range!");
        }

        return *(begin + index - 1);
    }

    // NOTE: indexing starts from 1. Maths...
    const Type &operator[](const std::size_t &index) const {
        if ((index <= 0) || (index > length)) {
            throw std::out_of_range("Going out of range!");
        }

        return *(begin + index - 1);
    }

    // First left permutation, then right one
    friend Permutation operator*(const Permutation &lhs, const Permutation &rhs) {
        // Time:  O(n)
        // Space: O(1)

        if ((lhs.end - lhs.begin) != (rhs.end - rhs.begin)) {
            throw std::logic_error("Permutations must have the same size!");
        }

        Permutation<Container> mul(lhs.begin, lhs.end);

        for (std::size_t i = 1; i <= rhs.length; i++) {
            mul[i] = rhs[*(lhs.begin + i - 1)];
        }

        return mul;
    }

    Permutation Inverse(Iterator store_begin, Iterator store_end) {
        // Time:  O(n)
        // Space: O(n)
        Permutation<Container> inverse_p(begin, end);
        Permutation<Container> store_p(store_begin, store_end);

        for (std::size_t i = 1; i <= length; i++) {
            store_p[inverse_p[i]] = i;
        }

        return store_p;
    }

    inline Iterator GetBegin() { return begin; }

    inline Iterator GetEnd() { return end; }

    void SetBegin(Iterator start) {
        begin = start;
        length = static_cast<std::size_t>(end - begin);
    }

    void SetEnd(Iterator fin) {
        if (fin < begin) {
            throw std::out_of_range("A pointer to end of Container is smaller than a pointer to its begin!");
        }
        end = fin;
        length = static_cast<std::size_t>(end - begin);
    }

    inline std::size_t GetSize() { return length; }

    std::ostream &WriteTo(std::ostream &ostream) {
        std::size_t counter = 0;
        while ((begin + counter) < end) {
            counter++;
            ostream << counter << "\t";
        }

        counter = 0;
        ostream << "\n";
        while ((begin + counter) < end) {
            ostream << *(begin + counter) << "\t";
            counter++;
        }
        ostream << "\n";

        return ostream;
    }

private:
    Iterator begin = nullptr;
    Iterator end = nullptr;
    std::size_t length = 0;
};

template<std::ranges::input_range Container>
std::ostream &operator<<(std::ostream &ostream, Permutation<Container> &permutation) {
    return permutation.WriteTo(ostream);
}

#endif //PERMUTATION_PERMUTATIONS_HPP
