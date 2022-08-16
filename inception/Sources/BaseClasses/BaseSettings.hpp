#ifndef __BASE_SETTINGS_HPP__
#define __BASE_SETTINGS_HPP__
namespace Base
{
  struct Settings
  {
    uint32_t viewportWidth = 1024;
    uint32_t viewportHeight = 768;
    float nearClipPlane = 1.f;
    float farClipPlane = 100.f;

    // @todo add scene name, this also required to create a 'scene factory', this in self turn
    //       requires to to make scenes able to register in compile or load time in the 'scene
    //       factory'. At time of specific scene loading the 'scene factory' object runs a specific
    //       'scene loader' and then releases ready to use scene that passes to the engine object.
  };
}
#endif // __BASE_SETTINGS_HPP__