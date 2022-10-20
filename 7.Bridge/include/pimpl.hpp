#pragma once
template <typename T>
class pimpl {
   private:
    T* impl;

   public:
    pimpl();
    template <typename... Args>
    pimpl(Args&&... args);
    ~pimpl();
    T* operator->();
    T& operator*();
};