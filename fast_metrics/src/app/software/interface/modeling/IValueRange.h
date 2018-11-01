#ifndef FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IVALUERANGE_H_
#define FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IVALUERANGE_H_

#include <string>

/* A value range of datatype */
class IValueRange
{
public:
    virtual ~IValueRange() {}
    virtual std::string my_name() = 0;
};

#endif // !FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IVALUERANGE_H_