#ifndef FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_ISOFTWARELIFE_H_
#define FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_ISOFTWARELIFE_H_

#include <vector>
#include "IWhateverItIs.h"
#include "IAnyFeature.h"
#include "ISoftware.h"

/* Abstraction of A software */
class ISoftwareLife
{
public:
    virtual ~ISoftwareLife() {}
    virtual int instantiate(PISoftware definition,
                            PIAnyDataType inner_state,
                            PIWhateverItIs runtime_environment
                ) = 0;
};

typedef ISoftwareLife* PISoftwareLife;
#endif // !FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_ISOFTWARELIFE_H_