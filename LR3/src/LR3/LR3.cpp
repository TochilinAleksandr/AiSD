// LR3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Heap.h"
#include "Iterator.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
    Heap heap = Heap();
    heap.insert(5);
    heap.insert(15);
    heap.insert(34);
    heap.insert(77);
    heap.insert(100);
    heap.insert(50);
    heap.insert(1);
    heap.insert(75);
    heap.insert(350);
    heap.printHeap();

    std::cout << heap.getHeapString() << std::endl;

    std::cout << std::endl;

    Iterator* dfs_iterator = heap.create_dft_iterator();
    Iterator* bfs_iterator = heap.create_bft_iterator();

    while (dfs_iterator->hasNext()) {
        dfs_iterator->next();
        std::cout << dfs_iterator->getCur() << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    while (bfs_iterator->hasNext()) {
        bfs_iterator->next();
        std::cout << bfs_iterator->getCur() << " ";
    }
    std::cout << std::endl;
    
}
