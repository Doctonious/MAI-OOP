#pragma once

struct Counter
{
    int sharedCounter;
    int weakCounter;
};

template<typename T>
class Shared_Ptr
{
public:
    Shared_Ptr():ptr_{nullptr}, counter_{nullptr}{}
    Shared_Ptr(T* nptr):ptr_{nullptr}, counter_{nullptr}{reset(nptr);}
    Shared_Ptr( Shared_Ptr& r):ptr_{nullptr}, counter_{nullptr}{
        reset();
        if(r.get()){
            ptr_ = r.get();
            counter_ = r.count_ref();
            counter_->sharedCounter+= 1;
        }
    }


    ~Shared_Ptr(){
        reset();
    }

    T* get(){return ptr_;}

    void reset(T* nptr){
        if(ptr_){
            if(counter_->sharedCounter == 1){
                delete ptr_;
                counter_->sharedCounter--;
                if(counter_->weakCounter == 0){
                    delete counter_;
                    counter_ = nullptr;
                }
            }else{
                counter_->sharedCounter--;
            }
        }
        if(nptr){
            ptr_ = nptr;
            counter_ = new Counter{1, 0};
        }
    }

    void reset(){reset(nullptr);}


    Shared_Ptr& operator=( Shared_Ptr& r ) 
    {
        reset();
        if(r.get()){
            ptr_ = r.get();
            counter_ = r.count_ref();
            counter_->sharedCounter+= 1;
        }
        return *this;
    }


    Counter count(){return *counter_;}
    Counter* count_ref(){return counter_;}


private:
    T* ptr_;
    Counter* counter_;
};


template <typename T>
Shared_Ptr<T> make_Shared(T* ptr){
    return Shared_Ptr<T>(ptr);
}

