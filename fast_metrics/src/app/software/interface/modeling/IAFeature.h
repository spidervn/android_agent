#ifndef FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IAFEATURE_H_
#define FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IAFEATURE_H_

#include <vector>
#include <string>
#include "IDataType.h"

class IAFeature
{
public:
    virtual ~IAFeature() {}
    virtual std::string my_name() = 0;

    virtual int instantiate(const char* name, 
                            IDataType* input,       // Input type for Feature
                            IDataType* out_put     // Output type of this feature
                ) = 0;
};

#endif // !FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IAFEATURE_H_