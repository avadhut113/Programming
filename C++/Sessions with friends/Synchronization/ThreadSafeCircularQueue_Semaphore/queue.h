#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstdio>
#include <semaphore>

/** A thread-safe queue which supports one read-thread and one write-thread
	manipulating the queue concurrently. In other words, the thread-safe queue can
	be used in the consumer-producer problem with one consumer and one producer. **/
template<typename T>
class Queue {
	const size_t size;
	T* const arr;
	int start = 0, end = 0;
	Semaphore write, read;
	std::recursive_mutex writemtx, readmtx; //Recursive mutex to prevent a thread to block self
public:

	/** Default constructor **/
	explicit Queue(const size_t size = 1) : size(size), arr(new T[size]), write(size), read(0) { }

	/** Copy constructor. Does not copy ownership or state of mutices from q, so
		the copy-constructed Queue should be regarded as a completely new queue
		initialized with elements from queue q
		NOTE: The copy constructor have NOT been tested so it may or may not introduce deadlocks if used **/
	explicit Queue(const Queue& q) : size(q.size), arr(new T[size]), start(q.start), end(q.end), write(q.write), read(q.read) {
		//Before copying from q, make sure this owns critical write section of q
		std::lock_guard<std::recursive_mutex> lg(q.writemtx);
		std::memcpy(arr, q.arr, size * sizeof(T));
	}
	virtual ~Queue() {
		delete[] arr;
	}

	/** Adds an element to the queue. If queue is full,
		block the calling thread until queue is not full
		and then add the object, unblocking the calling thread.
		If more than one thread calls add or offer concurrently, behaviour is undefined. **/
	void add(const T& obj) {
		std::lock_guard<std::recursive_mutex> lg(writemtx);
		write.acquire();
		arr[end++] = obj;
		end %= size;
		read.release();
	}

	/** Add an element to the queue if the queue is not full, otherwise
		do not add obj to the queue. The calling thread is never blocked.
		If succesfully added, returns true, otherwise returns false.
		If more than on thread calls add or offer concurrently, behaviour is undefined **/
	bool offer(const T& obj) {
		std::lock_guard<std::recursive_mutex> lg(writemtx);
		if (!full()) {
			add(obj);
			return true;
		}
		return false;
	}

	/** Read first element in queue. If there is no first element
		in the queue, blocks the calling thread until there is an
		element in the queue which is then returned **/
	const T& front() {
		std::lock_guard<std::recursive_mutex> lg(readmtx);
		read.acquire();
		read.release();
		return arr[start % size];
	}

	/** Pops an element from the queue. If there is no element
		to pop, block until there is an element to pop and then pop it,
		unblocking calling thread.
		If more than one thread calls pop concurrently, behaviour is undefined **/
	void pop() {
		std::lock_guard<std::recursive_mutex> lg(readmtx);
		read.acquire();
		start++;
		start %= size;
		write.release();
	}

	/** Copies first element in queue and erases it from queue.
		If there is no element to copy, block until there is an
		element to copy and then copy it, unblocking calling thread.
		So take() is an atomic front() and pop() operation **/
	T take() {
		std::lock_guard<std::recursive_mutex> lg(readmtx);
		read.acquire();
		T retval = arr[start++];
		start %= size;
		write.release();
		return retval;
	}

	/** Check if queue is empty or not **/
	bool empty() const { return !read.available(); }

	/** Check if queue is full or not **/
	bool full() const { return !write.available(); }
};

#endif //QUEUE_HPP