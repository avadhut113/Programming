#include "Pimpl.h"

template<typename T>
CPimpl<T>::CPimpl() : impl{new T{}}
{

}

template<typename T>
template<typename...Args>
CPimpl<T>::CPimpl(Args &&... args) :
	impl{new T{std::forward<Args>(args)...}}
{

}

template<typename T>
CPimpl<T>::~CPimpl()
{

}

template<typename T>
T *CPimpl<T>::operator->()
{
	return impl.get();
}

template<typename T>
T& CPimpl<T>::operator*()
{
	return *impl.get();
}

