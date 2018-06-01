#include <iostream>
#include <pthread.h>

namespace gof {
namespace creational {

class Mutex {
public:
    Mutex(){ pthread_mutex_init(&mMutex, NULL); }
    Mutex(int dummy){ pthread_mutex_init(&mMutex, NULL); }
    ~Mutex(){ pthread_mutex_destroy(&mMutex); }
    Mutex(const Mutex&) = delete;
    Mutex&      operator = (const Mutex&) = delete;

    int lock(){ return -pthread_mutex_lock(&mMutex); }
    void unlock(){ pthread_mutex_unlock(&mMutex); }

    // Manages the mutex automatically. It'll be locked when Autolock is
    // constructed and released when Autolock goes out of scope.
    class Autolock {
    public:
        explicit Autolock(Mutex& mutex) : mLock(mutex)  { mLock.lock(); }
        ~Autolock() { mLock.unlock(); }
    private:
        Mutex& mLock;
    };

private:
    pthread_mutex_t mMutex;
};

template <typename T>
class Singleton {
public:
    static T& Instance() {
        Mutex::Autolock _l(_lock);
        if(nullptr == _instance) {
            _instance = new T();
        }

        return *_instance;           
    }
    virtual ~Singleton(){}
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
private:
    static T* _instance;
    static Mutex _lock; 
};


class Test: public Singleton<Test> {
public:
    void dis() {std::cout << "hi" << std::endl;}    
};

}
}

template<>  gof::creational::Mutex  gof::creational::Singleton< gof::creational::Test>::_lock(1);
template<>  gof::creational::Test*  gof::creational::Singleton< gof::creational::Test>::_instance(nullptr);
template class  gof::creational::Singleton< gof::creational::Test>;
//template<typename T> Mutex gof::creational::Singleton<T>::_lock;
//template<typename T> T* gof::creational::Singleton<T>::_instance(nullptr);

int main()
{
    gof::creational::Test::Instance().dis();    
    return 0;    
}








