#ifndef FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IANYFEATURE_H_
#define FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IANYFEATURE_H_

#include <vector>
#include <string>
#include "IAnyDataType.h"

class IAnyFeature
{
public:
    virtual ~IAnyFeature() {}
    virtual std::string my_name() = 0;

    virtual int instantiate(const char* name, 
                            IDataType* input,       // Input type for Feature
                            IDataType* out_put     // Output type of this feature
                ) = 0;
};

typedef IAnyDataType* PIAnyFeature;

#endif // !FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IANYFEATURE_H_