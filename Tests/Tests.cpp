/*
 * Tests.c
 *      Author: Kurossa
 */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <string>
#include "Tests.h"

/* --------------------------------------------------------------------- */
/*                              Vector_test                              */
/* --------------------------------------------------------------------- */

void Vector_test (void)
{
    printf("\n***************************************************\n");
    printf("Start %s \n",__FUNCTION__);
    printf("***************************************************\n");

    std::vector<TestClass>  cp_vect;

    TestClass *item;
    printf("Begin loop\n");
    for (int i = 0; i < 5; ++i)
    {
        item = new TestClass;
        item->in = i;
        item->out = 3*i;
        cp_vect.push_back(*item);
        delete item;
    }
    printf("End loop");

    printf("%d\n",cp_vect.begin()->in);
    std::vector<TestClass>::reverse_iterator it = cp_vect.rbegin();

    for (;it<cp_vect.rend();++it)
    {
        TestClass &item_ref = *it;

        printf("TestClass item_ref.in = %d, item_ref.out = %d\n",item_ref.in, item_ref.out);
        if(item_ref.in == 2)
        {
            printf("item_ref.in == 2 \n");
        }
    }
}

/* --------------------------------------------------------------------- */
/*                             Singleton_test                            */
/* --------------------------------------------------------------------- */
void Singleton_test (void)
{
    printf("\n***************************************************\n");
    printf("Start %s \n",__FUNCTION__);
    printf("***************************************************\n");

    Singleton<TestClass>::Instance()->in = 22;
    Singleton<TestClass>::Instance()->out = 33;
    printf("in = %d, out = %d\n",Singleton<TestClass>::Instance()->in,Singleton<TestClass>::Instance()->out);
    Singleton<TestClass>::Destroy();

    Singleton<TestClass>::Instance();
    printf("in = %d, out = %d\n",Singleton<TestClass>::Instance()->in,Singleton<TestClass>::Instance()->out);
    Singleton<TestClass>::Instance()->in = 11;
    printf("in = %d, out = %d\n",Singleton<TestClass>::Instance()->in,Singleton<TestClass>::Instance()->out);

}

/* --------------------------------------------------------------------- */
/*                            PriorityQueue_test                         */
/* --------------------------------------------------------------------- */
void PriorityQueue_test (void)
{
    printf("\n***************************************************\n");
    printf("Start %s \n",__FUNCTION__);
    printf("***************************************************\n");

    /* Create priority queue */
    BufferQueue<sContext_t> oBufferQueue;

    /* Create two buffers */
    sBuffer_t* buffer = new sBuffer_t();
    sBuffer_t* buffer2 = new sBuffer_t();
    std::string str("New String 1, prio = Medium");
    std::string str2("New String 2, prio = Highest");

    buffer->data = new char [str.length()+1];
    std::strcpy (buffer->data, str.c_str());

    buffer2->data = new char [str2.length()+1];
    std::strcpy (buffer2->data, str2.c_str());

    /* Printf two buffers*/
    cout << "*buffer = " << buffer << ", data = " << buffer->data <<  endl;
    cout << "*buffer2 = " << buffer2 << ", data = " << buffer2->data <<  endl;

    /* Create two new queue elements with set priority and add them to queue */
    sContext_t* context = new sContext_t(buffer, Medium);
    oBufferQueue.enqueue(context);
    sContext_t* context2 = new sContext_t(buffer2, Highest);
    oBufferQueue.enqueue(context2);

    sContext_t *el;
    sBuffer_t* msg;
    int i = 0;

    while (0!=oBufferQueue.getSize())
    {
        /* Dequeue elements in priority order and printf content */
        el = oBufferQueue.dequeue();
        msg = el->getSCpriBufferPtr();
        cout << "*msg"<< i << " = "<<(void *)msg->data << ", msg"<< i <<" = " << msg->data << endl;
        delete el;
        ++i;
    }

    cout << "*msg"<< i << " = "<<(void *)msg->data << ", msg"<< i <<" = " << buffer->data << endl;

}


