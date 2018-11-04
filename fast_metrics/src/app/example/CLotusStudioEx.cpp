#include "CLotusStudioEx.h"
#include "app/software/interface/modeling/ISoftware.h"
#include <vector>

using namespace std;

CLotusStudioEx::CLotusStudioEx()
{
}

CLotusStudioEx::~CLotusStudioEx()
{
}

int CLotusStudioEx::run(int argc, char* argv[])
{
    PISoftware pLotusStudio = NULL;
    vector<PIAnyFeature> v_Features_;

    v_Features_.push_back(NULL);
    v_Features_.push_back(NULL);
    
    return 0;
}