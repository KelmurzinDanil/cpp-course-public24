#pragma once

#include <iterator>

/**
 * @brief
 * Класс итератора, представлен для возможности использовать в векторе
 * обаладает стандартными операциями с итераторами
 * @tparam T 
 */
template <class T>
class Iterator
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using reference = T&;
    using pointer = T*;
    using iterator = Iterator<T>;

    Iterator(pointer ptr) noexcept
        : ptr_(ptr)
    {}

    reference operator * () const noexcept {
        return *ptr_;
    }

    bool operator == (const Iterator & other) const noexcept {
        return ptr_ == other.ptr_;
    }

    bool operator != (const Iterator & other) const noexcept {
        return ptr_ != other.ptr_;
    }

    bool operator < (const Iterator & other) const noexcept {
        return ptr_ < other.ptr_;
    }

    bool operator > (const Iterator & other) const noexcept {
        return ptr_ > other.ptr_;
    }

    bool operator <= (const iterator & other) const noexcept {
        return ptr_ <= other.ptr_;
    }

    bool operator >= (const Iterator & other) const noexcept {
        return ptr_ >= other.ptr_;
    }

    // Без &: Не изменяет текущий итератор и возвращаем копию
    // C &: Изменяет себя и возвращает себя
    Iterator operator + (int n) const noexcept {
        return Iterator(ptr_ + n); 
    }
 
    Iterator & operator += (int n) noexcept {
        ptr_ += n;
        return *this;
    }

    Iterator operator - (int n) const noexcept {
        return Iterator(ptr_ - n)
    }

    Iterator & operator -= (int n) noexcept {
        ptr_ -= n;
        return *this;
    }

    reference operator [] (int n) const noexcept {
        return ptr_[n];
    }

    // Без &: Изменяем текущий объект и возвращаем копию
    // C &: Изменяет себя и возвращает себя
    Iterator & operator ++ () noexcept {
        ++ptr_;
        return *this;
    }

    Iterator & operator -- () noexcept {
        --ptr_;
        return *this;
    }

    Iterator operator ++ (int) noexcept {
        Iterator tmp = *this;
        --ptr_;
        return tmp;
        
    }

    Iterator operator -- (int) noexcept {
        Iterator tmp = *this;
        ++ptr_;
        return tmp;
    }

    friend Iterator& operator + (int n, const Iterator & it) noexcept {
        return Iterator(it.ptr_ + n);
    }

    friend Iterator& operator - (int n, const Iterator & it) noexcept {
         return Iterator(it.ptr_ - n);
    }

    friend int operator - (const Iterator & lhs, const Iterator & rhs) noexcept {
        return lhs.ptr_ - rhs.ptr_;
    }
private:
    pointer ptr_;
};
