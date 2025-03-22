#ifndef IVIEW_H
#define IVIEW_H


class IView
{
public:
    IView();
    virtual void Display() = 0;
    virtual ~IView() = default;
};

#endif // IVIEW_H
