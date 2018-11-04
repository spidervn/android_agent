#ifndef FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IWHATEVERITIS_H_
#define FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IWHATEVERITIS_H_

#include <string>
/* 
 *  An abstraction object, which stands for Whatever object?
 *  Everything we know about it is the name.
 */
class IWhateverItIs
{
public:
    virtual ~IWhateverItIs() {}
    virtual std::string my_name() = 0;
};

typedef IWhateverItIs* PIWhateverItIs;
#endif // !FASTMETRICS_APP_SOFTWARE_INTERFACE_MODELING_IWHATEVERITIS_H_