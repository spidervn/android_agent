#ifndef FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_ISOFTWARE_H_
#define FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_ISOFTWARE_H_

#include <vector>
#include "IAnyFeature.h"

/* Abstraction of A software */
class ISoftware
{
public:
    virtual ~ISoftware() {}   
    virtual int my_features(std::vector<IAnyFeature*>& v) = 0;
};

typedef ISoftware* PISoftware;

#endif // !FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_ISOFTWARE_H_