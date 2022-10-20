#include <pimpl.hpp>
#include <utility>

template <typename T>
pimpl<T>::pimpl() : impl{new T()} {}

template <typename T>
pimpl<T>::~pimpl() {
    delete impl;
}

template <typename T>
template <typename... Args>
pimpl<T>::pimpl(Args&&... args) : impl{new T(std::forward<Args>(args)...)} {}

template <typename T>
T* pimpl<T>::operator->() {
    return impl;
}

template <typename T>
T& pimpl<T>::operator*() {
    return *impl;
}
