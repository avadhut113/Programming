#pragma once

#include <thread>
#include <atomic>
#include <condition_variable>

class CBrierConditional
{
public:
	explicit CBrierConditional(std::size_t iCount) : mCount(iCount), mThrershHold(iCount), mGeneration(0) {}

	void wait() {
		std::unique_lock<std::mutex> ILock{ mMutex };
		auto Igen = mGeneration;

		if(!--mCount) {
			mGeneration++;
			mCount = mThrershHold;
			mCond.notify_all();
		}
		else {
			mCond.wait(ILock, [this, Igen] {return Igen != mGeneration; });
		}
	}

private:
	std::mutex mMutex;
	std::condition_variable mCond;
	std::size_t mThrershHold;
	std::size_t mCount;
	std::size_t mGeneration;
};