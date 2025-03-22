#pragma once
#include <mutex>
#include <vector>
#include <functional>
namespace Old{class Lock {
public:
	virtual void lock() = 0 ;
	virtual void unlock() = 0 ;
};

class MutexLock : public Lock {
	std::mutex mtx ;
public:
	void lock() {
		mtx.lock() ;
	}
	void unlock() {
		mtx.unlock() ;
	}
};

class NoLock : public Lock{
public:
	void lock() {
	}
	void unlock() {
	}
};

template<typename T>
class Array {
	std::vector<T> m_buffer ;
	std::mutex mtx ;
	Lock *m_pLock{} ;
public:
	Array(Lock *lock):m_pLock{lock} {
		if(m_pLock == nullptr) {
			//m_pLock = new NoLock ;
		}
	}
	void Add(const T &element) {
		m_pLock->lock() ;
		m_buffer.push_back(element) ;
		m_pLock->unlock() ;
	}
	void Remove(int position) {
		m_buffer.erase(m_buffer.begin() + position) ;
	}
	void Modify(int position, const T &new_value) {
		m_buffer[position] = new_value ;
	}
	size_t Size()const {
		return m_buffer.size() ;
	}
	const T & GetAt(int position)const {
		return m_buffer[position] ;
	}
};}


class MutexLock  {
	std::mutex mtx ;
public:
	void lock() {
		mtx.lock() ;
	}
	void unlock() {
		mtx.unlock() ;
	}
};

class NoLock {
public:
	void lock() {
	}
	void unlock() {
	}
};
template<typename T>
using DisplayStrategy = std::function<void (const std::vector<T> &)> ;
template<typename T, typename LockPolicyT = NoLock>
class Array {
	std::vector<T> m_buffer ;
	std::mutex mtx ;
	LockPolicyT m_pLock{} ;
	DisplayStrategy<T> m_Strategy{} ;
public:
	Array(const std::initializer_list<T> & list):m_buffer{list.begin(), list.end()} {
		
	}
	void Add(const T &element) {
		m_pLock.lock() ;
		m_buffer.push_back(element) ;
		m_pLock.unlock() ;
	}
	void Remove(int position) {
		m_buffer.erase(m_buffer.begin() + position) ;
	}
	void Modify(int position, const T &new_value) {
		m_buffer[position] = new_value ;
	}
	size_t Size()const {
		return m_buffer.size() ;
	}
	const T & GetAt(int position)const {
		return m_buffer[position] ;
	}
	void SetStrategy(DisplayStrategy<T> strategy) {
		m_Strategy = strategy ;
	}
	void Display() {
		m_Strategy(m_buffer) ;
	}
};