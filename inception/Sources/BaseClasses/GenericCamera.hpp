#ifndef __GENERIC_CAMERA_HPP__
#define __GENERIC_CAMERA_HPP__
namespace Base
{
    namespace Generic
    {
        /**
         * @brief Describes generic camera interface.
         */
        struct Camera
        {
            /**
             * @brief Returns world camera position.
             */
            [[nodiscard]]
            virtual Math3D::Position  Position() const = 0;

            /**
             * @brief Returns worls camera `Up` direction
             */
            [[nodiscard]]
            virtual Math3D::Direction Up() const = 0;

            /**
             * @brief Returns world camers `Look At` direction
             */
            [[nodiscard]]
            virtual Math3D::Direction LookAt() const = 0 ;

            /**
             * @brief Returns world camera `Right` direction
             */
            [[nodiscard]]
            virtual Math3D::Direction Right() const = 0;

            /**
             * @brief Returns camera's `Field Of View` angle in degrees.
             */
            [[nodiscard]]
            virtual float             FoV() const = 0;

            /**
             * @brief ???
             */
            [[nodiscard]]
            virtual bool IsActive() const = 0;

            /**
             * @brief ???
             */
            virtual void SetActive(bool active) = 0;
        };
    }
}
#endif // __GENERIC_CAMERA_HPP__