#ifndef FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_ISOFTWARE_H_
#define FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_ISOFTWARE_H_

#include <vector>
#include "IAFeature.h"

/* Abstraction of A software */
class ISoftware
{
public:
    virtual ~ISoftware() {}   
    virtual int my_features(std::vector<IAFeature*>& v) = 0;
};

#endif // !FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_ISOFTWARE_H_