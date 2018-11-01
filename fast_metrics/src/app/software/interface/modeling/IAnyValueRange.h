#ifndef FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IANYVALUERANGE_H_
#define FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IANYVALUERANGE_H_

#include <string>

/* A value range of datatype */
class IAnyValueRange
{
public:
    virtual ~IAnyValueRange() {}
    virtual std::string my_name() = 0;
};

typedef IAnyValueRange* PIAnyValueRange;

#endif // !FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IANYVALUERANGE_H_