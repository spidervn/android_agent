#ifndef FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IDATATYPE_H_
#define FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IDATATYPE_H_

#include <string>
#include "IValueRange.h"

/* Any data type */
class IDataType
{
public:
    virtual ~IDataType() {}
    virtual std::string my_name() = 0;
    virtual IValueRange* value_range() = 0;
};

#endif // !FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IDATATYPE_H_