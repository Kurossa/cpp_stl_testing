/*
 * Singleton.h
 *      Author: Kurossa
 */

#ifndef SINGLETON_SINGLETON_HPP_
#define SINGLETON_SINGLETON_HPP_

#include <stdio.h>

class TestClass
{
public:
    TestClass()
    {
        printf("TestClass constructor\n");
        in = 0;
        out = 0;
    }
    ~TestClass()
    {
        printf("TestClass destructor\n");
    }

    int in;
    int out;
private:
};


template <class T>
class Singleton
{
public:
    static T* Instance()
    {
        if(NULL == m_pInstance)
        {
            m_pInstance = new T;
        }
        return m_pInstance;
    }
    static void Destroy()
    {
        if(NULL != m_pInstance)
        {
            delete m_pInstance;
            m_pInstance = NULL;
        }
    }
protected:
    Singleton();
    ~Singleton();
private:
    Singleton(Singleton const&);
    Singleton& operator=(Singleton const&);

    static T* m_pInstance;
};

template <class T> T* Singleton<T>::m_pInstance = NULL;

#endif /* SINGLETON_SINGLETON_HPP_ */
