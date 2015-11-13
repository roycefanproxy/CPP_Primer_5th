#ifndef _16_28_H_
#define _16_28_H_
#include <iostream>

// generic default deleter
template <typename T>
class __DefaultDeleter
{
public:
	void operator()(T* p) { delete p; }
};

// self implementation of std::shared_ptr
template <typename T>
class S_ptr
{
	// private classes definition
private:
	class Aux
	{
		template<typename> friend class S_ptr;
	public:
		// constructor & destructor
		Aux() : ref_count_(1) {}

		virtual ~Aux() {}

		// member method
		virtual void incre() { ++ref_count_; }
		virtual void decre() = 0;
		virtual void destroy() = 0;

	protected:
		unsigned int ref_count_;
	};

	template <typename T2, typename Deleter>
	class AuxCounter : public Aux
	{
		using Aux::ref_count_;
	public:
		// constructor & destructor
		AuxCounter(T2* p, Deleter d) : ptr_(p), deleter_(d) {}

		~AuxCounter() { decre(); }

		// member method
		void decre() override { if(--ref_count_ == 0) destroy(); }
		void destroy() override { deleter_(ptr_); }

		//public member
		T2* ptr_;
	private:
		Deleter deleter_;
	};
	// private class defination end
	
public:
	// constructor & destructor
	S_ptr(T* p) : ptr_(new T(*p))
	{
		counter_ = new AuxCounter<T, __DefaultDeleter<T>>(ptr_, __DefaultDeleter<T>());
		delete p;
		p = nullptr;
	}
	template <typename T2, typename D> S_ptr(T2* p, D&& deleter) : ptr_(new T(*p))
	{
		counter_ = new AuxCounter<T, D>(new T(*p), deleter);
		delete p;
		p = nullptr;
	}
	S_ptr(const S_ptr<T>& rhs) : ptr_(rhs.ptr_), counter_(rhs.counter_) { counter_->incre(); }
	
	~S_ptr() { counter_->decre(); }

	// assignment
	S_ptr& operator=(const S_ptr<T>& rhs)
	{
		auto temp = rhs.counter_;
		temp->incre();
		counter_->decre();
		counter_ = temp;
		ptr_ = rhs.ptr_;
		return *this;
	}

	// operation
	const T& operator*() const { return *ptr_; }
	T& operator*() { return *ptr_; }

	const T* operator->() const { return ptr_; }
	T* operator->() { return ptr_; }

	unsigned int GetRefCount() const { return counter_->ref_count_; }


	// private data member
	T* ptr_;
	Aux *counter_;
};

// self implementation of std::unique_ptr
template <typename T, typename Deleter = __DefaultDeleter<T>>
class U_ptr
{
public:
	// constructor & destructor
	U_ptr(T* p = nullptr) : ptr_(p) {}
	U_ptr(T* p, const Deleter& d) : ptr_(p), deleter_(d) {}
	U_ptr(U_ptr<T>&& rhs) : ptr_(rhs.ptr_), deleter_(std::move(rhs.deleter_)) { rhs.ptr_ = nullptr; }
	
	~U_ptr() { reset(); }

	// assignment operator
	U_ptr& operator=(U_ptr&& rhs)
	{
		reset(rhs.release());
		deleter_ = std::move(rhs.deleter_);
		return *this;
	}
	template <typename T2, typename D2>
	U_ptr& operator=(U_ptr<T2, D2>&& rhs)
	{
		reset(rhs.release());
		deleter_ = std::move(rhs.deleter_);
		return *this;
	}

	// operation
	T* release()
	{
		T *ret_ptr = ptr_;
		ptr_ = nullptr;
		return ret_ptr;
	}
	T* get() const { return const_cast<T*>(ptr_); }
	void reset(T* n_ptr = nullptr)
	{
		if(ptr_ != n_ptr)
		{
			deleter_(ptr_);
			ptr_ = n_ptr;
		}
	}

private:
	// private data member
	T* ptr_;
	Deleter deleter_;
};

#endif // 16_28_H_
