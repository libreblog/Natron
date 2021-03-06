#ifndef SBK_APPWRAPPER_H
#define SBK_APPWRAPPER_H

#include <shiboken.h>

#include <PyAppInstance.h>

NATRON_NAMESPACE_ENTER NATRON_PYTHON_NAMESPACE_ENTER
class AppWrapper : public App
{
public:
    inline void renderInternal_protected(bool forceBlocking, Effect * writeNode, int firstFrame, int lastFrame, int frameStep) { App::renderInternal(forceBlocking, writeNode, firstFrame, lastFrame, frameStep); }
    inline void renderInternal_protected(bool forceBlocking, const std::list<Effect * > & effects, const std::list<int > & firstFrames, const std::list<int > & lastFrames, const std::list<int > & frameSteps) { App::renderInternal(forceBlocking, effects, firstFrames, lastFrames, frameSteps); }
    virtual ~AppWrapper();
    static void pysideInitQtMetaTypes();
};
NATRON_PYTHON_NAMESPACE_EXIT NATRON_NAMESPACE_EXIT

#endif // SBK_APPWRAPPER_H

