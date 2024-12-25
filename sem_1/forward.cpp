#include "forward.h"

void ForwardList<T>::pushFront(const T& value)
{
    auto newNode = std::make_unique<Node>(value);
    newNode -> _next = std::move(head);
    head = std::move(newNode);
}
bool ForwardList<T>::empty() const
{
    return head == nullptr;
}
void ForwardList<T>::popFront()
{
    if (head != nullptr)
    {
        head = std::move(head -> _next);
    }
}
const T& ForwardList<T>::front() const
{
    if (head != nullptr)
    {
        return head -> _data;
    }
}
