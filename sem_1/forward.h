#pragma once
#include <iostream>
#include <memory>
template<class T>
class ForwardList
{
private:
    struct Node {
        T _data;
        std::unique_ptr<Node> _next;
        Node(const T& data) : _data(data), _next(nullptr) {}
    };
    std::unique_ptr<Node> head;
public:
    ForwardList() : head(nullptr) {}
    void pushFront(const T& value);
    void popFront();
    bool empty();
    const T& front() const;
};