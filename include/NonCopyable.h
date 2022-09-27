#ifndef __NOCOPTABLE_H__
#define __NOCOPTABLE_H__

//不允许复制或者赋值
class NonCopyable
{
protected:
    NonCopyable()
    {
    }
    ~NonCopyable()
    {
    }

    NonCopyable(const NonCopyable &rhs) = delete;
    NonCopyable &operator=(const NonCopyable &rhs) = delete;
};

#endif
