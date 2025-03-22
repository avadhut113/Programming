#pragma once
#include <mutex>
#include <thread>
#include <atomic>
#include <thread>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// <MayersSingleton>

class MayersSingleton
{
public:
	static MayersSingleton& getInstance() {
		static MayersSingleton instance;
		return instance;
	}

private:
	MayersSingleton() = default;
	MayersSingleton(const MayersSingleton&) = delete;
	MayersSingleton& operator=(const MayersSingleton&) = delete;
};

/// </MayersSingleton>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// <simpleSingleton>

class simpleSingleton
{
public:
	static simpleSingleton* getInstance() {
		if(!m_instance)
			m_instance = new simpleSingleton();

		return m_instance;
	}

	~simpleSingleton() {
		delete m_instance;
		m_instance = nullptr;
	}
private:
	simpleSingleton() = default;
	simpleSingleton(const simpleSingleton&) = delete;
	simpleSingleton& operator=(const simpleSingleton&) = delete;

	static simpleSingleton* m_instance;
};

simpleSingleton* simpleSingleton::m_instance = nullptr;

/// </simpleSingleton>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// <ThreadSafesimpleSingleton>

class ThreadSafesimpleSingleton
{
public:
	static ThreadSafesimpleSingleton* getInstance() {

		if (!m_instance) {			// prevent each time locking 
			std::lock_guard<std::mutex> lg(mu);
			if (!m_instance) {		// double nullcheck problem
				m_instance = new ThreadSafesimpleSingleton();
			}
		}	
		return m_instance;
	}

	~ThreadSafesimpleSingleton() {
		delete m_instance;
		m_instance = nullptr;
	}
private:
	ThreadSafesimpleSingleton() = default;
	ThreadSafesimpleSingleton(const ThreadSafesimpleSingleton&) = delete;
	ThreadSafesimpleSingleton& operator=(const ThreadSafesimpleSingleton&) = delete;

	static std::mutex mu;
	static ThreadSafesimpleSingleton* m_instance;
};

ThreadSafesimpleSingleton* ThreadSafesimpleSingleton::m_instance = nullptr;

/// </ThreadSafesimpleSingleton>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// <callOnceSingleton>

class callOnceSingleton
{
public:
	~callOnceSingleton() {
		delete m_instance;
		m_instance = nullptr;
	}

	static callOnceSingleton* getInstance() {
		std::call_once(flag, &callOnceSingleton::CreateInstance);
		return m_instance;
	}
	
private :
	callOnceSingleton() = default;
	callOnceSingleton(const callOnceSingleton&) = delete;
	callOnceSingleton& operator=(const callOnceSingleton&) = delete;

	static void CreateInstance() {
		m_instance = new callOnceSingleton;
	}

	static callOnceSingleton* m_instance;
	static std::once_flag flag;
};

callOnceSingleton* callOnceSingleton::m_instance;
std::once_flag callOnceSingleton::flag;

/// </callOnceSingleton>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//################################################################ Atomic ################################################################
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// <SeqConsistentSingleton>

class SeqConsistentSingleton
{
public:
	~SeqConsistentSingleton() {
		delete m_instance;
		m_instance = nullptr;
	}

	static SeqConsistentSingleton* getInstance() {
		SeqConsistentSingleton* instance = m_instance.load();
		if (!instance) {
			std::lock_guard<std::mutex> lg(mu);
			instance = m_instance.load();
			if (!instance) {
				instance = new SeqConsistentSingleton;
				m_instance.store(instance);
			}
		}
	}

private:
	SeqConsistentSingleton() = default;
	SeqConsistentSingleton(const SeqConsistentSingleton&) = delete;
	SeqConsistentSingleton& operator=(const SeqConsistentSingleton&) = delete;

	static std::atomic<SeqConsistentSingleton*> m_instance;
	static std::mutex mu;
};

std::atomic<SeqConsistentSingleton*> SeqConsistentSingleton::m_instance = nullptr;
std::mutex SeqConsistentSingleton::mu;

/// </SeqConsistentSingleton>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// <AcqReleaseConsistentSingleton>

class AcqReleaseConsistentSingleton
{
public:
	~AcqReleaseConsistentSingleton() {
		delete m_instance;
		m_instance = nullptr;
	}

	static AcqReleaseConsistentSingleton* getInstance() {
		AcqReleaseConsistentSingleton* instance = m_instance.load(std::memory_order_acquire);
		if (!instance) {
			std::lock_guard<std::mutex> lg(mu);
			instance = m_instance.load(std::memory_order_relaxed);
			if (!instance) {
				instance = new AcqReleaseConsistentSingleton;
				m_instance.store(instance,std::memory_order_release);
			}
		}
	}

private:
	AcqReleaseConsistentSingleton() = default;
	AcqReleaseConsistentSingleton(const AcqReleaseConsistentSingleton&) = delete;
	AcqReleaseConsistentSingleton& operator=(const AcqReleaseConsistentSingleton&) = delete;

	static std::atomic<AcqReleaseConsistentSingleton*> m_instance;
	static std::mutex mu;
};

std::atomic<AcqReleaseConsistentSingleton*> AcqReleaseConsistentSingleton::m_instance = nullptr;
std::mutex AcqReleaseConsistentSingleton::mu;

/// </AcqReleaseConsistentSingleton>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






