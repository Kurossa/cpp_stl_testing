/*
 * PriorityQueue.h
 *      Author: Kurossa
 */

#ifndef PRIORITYQUEUE_PRIORITYQUEUE_HPP_
#define PRIORITYQUEUE_PRIORITYQUEUE_HPP_

#include <stdio.h>
#include <queue>

using namespace std;

typedef enum
{
    Lowest = 0,
    Low,
    Medium,
    High,
    Highest
} ePriority_t;

/* --------------------------------------------------------------------- */
/*                             sBuffer_t                                 */
/* --------------------------------------------------------------------- */
typedef class sBuffer
{
public:
    sBuffer() : data(NULL) {}
    ~sBuffer() {delete data;}
    char* data;    /* *< message data */

} sBuffer_t;

/* --------------------------------------------------------------------- */
/*                             sBuffer_t                                 */
/* --------------------------------------------------------------------- */

typedef class sContext
{
public:
    sContext()
        : m_buffer(NULL)
        , m_priority(Lowest) { }

    sContext(sBuffer_t* o_sBbuffer, ePriority_t priority)
        : m_buffer(o_sBbuffer)
        , m_priority(priority) { }

    ~sContext()
    {
        delete m_buffer;
    }

    sBuffer_t* getSCpriBufferPtr() const
    {
        return m_buffer;
    }

    int getPriority() const
    {
        return m_priority;
    }

private:
    sContext(const sContext&);
    sContext & operator=(const sContext&);

    sBuffer_t* m_buffer;
    ePriority_t   m_priority;
}sContext_t;


/* --------------------------------------------------------------------- */
/*                             PRIORITY QUEUE                            */
/* --------------------------------------------------------------------- */
template <typename T>
struct ComparePriorityQueue
{
    bool operator()(T const* p1, T const* p2)
    {
        return p1->getPriority() < p2->getPriority();
    }
};

template <class T>
class BufferQueue
{
public:
    BufferQueue() {}
    virtual ~BufferQueue() {}

    void enqueue(T* buffer) {m_storedContextPrioQueue.push(buffer);}
    T* dequeue()
    {
        T* retContext = m_storedContextPrioQueue.top();
        m_storedContextPrioQueue.pop();
        return retContext;
    }
    int getSize() {return m_storedContextPrioQueue.size();}
private:

    BufferQueue(const BufferQueue& src);
    const BufferQueue& operator=(const BufferQueue& src);

    typedef std::priority_queue <T,
                                 std::vector<T*>,
                                 ComparePriorityQueue<T> > StoredContextPrioQueue_t;
    StoredContextPrioQueue_t     m_storedContextPrioQueue;
};



#endif /* PRIORITYQUEUE_PRIORITYQUEUE_HPP_ */
