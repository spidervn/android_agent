#ifndef FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IANYDATATYPE_H_
#define FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IANYDATATYPE_H_

#include <string>
#include "IAnyValueRange.h"

/* Any data type */
class IAnyDataType
{
public:
    virtual ~IAnyDataType() {}
    virtual std::string my_name() = 0;
    virtual IAnyValueRange* value_range() = 0;
};

typedef IAnyDataType* PIAnyDataType;

#endif // !FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IANYDATATYPE_H_