#ifndef __GENERIC_VIDEO_RENDERER_HPP__
#define __GENERIC_VIDEO_RENDERER_HPP__

namespace Base
{
    namespace Generic
    {
        /**
        * @brief Describes generic video renderer interface
        */
        struct VideoRenderer
        {
            virtual bool AddCamera(Camera& camera) = 0;
            virtual bool RemoveCamera(Camera& camera) = 0;
        };
    }
}
#endif // __GENERIC_VIDEO_RENDERER_HPP__