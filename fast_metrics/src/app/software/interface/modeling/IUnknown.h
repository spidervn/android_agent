#ifndef FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IUNKNOWN_H_
#define FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IUNKNOWN_H_

#include <vector>
#include "IWhateverItIs.h"
/*
 * An abstraction object, which stands for an Uknown object.
 * The object which we do not know anything about it, except it's existence.
 * We only know about is's existence, and it's signal of existence.
 */
class IUnknown
{
public:
    virtual ~IUnknown() {}
    virtual IWhateverItIs* my_signal() = 0;
};

typedef IUnknown* PIUnknown;

#endif // !FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IUNKNOWN_H_