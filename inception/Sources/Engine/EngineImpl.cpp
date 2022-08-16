#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include <BaseClasses/Interfaces.hpp>
#include <BaseClasses/BaseClasses.hpp>
#include "Engine.hpp"
#include "RenderFacility.hpp"
#include "EngineImpl.hpp"
namespace Engine
{
    Impl::Impl(Base::Settings settings)
        : settings_(settings)
    {

    }

    void Impl::KeyboardFunc(unsigned char ch, int x, int y)
    {
        throw std::logic_error("not implemented");
    }

    void Impl::SpecialFunc(int, int, int)
    {
        throw std::logic_error("not implemented");
    }

    void Impl::ReshapeFunc(int, int)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::VisibilityFunc(int)
    {
        throw std::logic_error("not implemented");
    }

    constexpr int oneThirtieth = 1000 / 30; // of a second in milliseconds
    std::chrono::steady_clock::time_point prev = std::chrono::steady_clock::now() - std::chrono::milliseconds(oneThirtieth);
    void Impl::RenderProc()
    {
        const auto now = std::chrono::steady_clock::now();
        const auto dtMS = std::chrono::duration_cast<std::chrono::milliseconds>(now - prev);
        prev = now;

        // @todo implement 2 pass physics calculations
        scene_->Update(dtMS.count() / 1000.f);

        renderFacility_->Draw(scene_->GetObjectTree());
    }

    void  Impl::MouseFunc(int, int, int, int)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::MotionFunc(int, int) {
        throw std::logic_error("not implemented");
    }

    void  Impl::PassiveMotionFunc(int, int)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::EntryFunc(int _0)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::KeyboardUpFunc(unsigned char, int, int)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::SpecialUpFunc(int, int, int)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::JoystickFunc(unsigned int, int, int, int)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::MenuStateFunc(int)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::MenuStatusFunc(int, int, int)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::OverlayDisplayFunc()
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::WindowStatusFunc(int status)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::SpaceballMotionFunc(int, int, int)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::SpaceballRotateFunc(int, int, int)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::SpaceballButtonFunc(int, int)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::ButtonBoxFunc(int, int)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::DialsFunc(int, int)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::TabletMotionFunc(int, int)
    {
        throw std::logic_error("not implemented");
    }

    void  Impl::TabletButtonFunc(int, int, int, int)
    {
        throw std::logic_error("not implemented");
    }

    void Impl::SetScene(Base::Scene::sptr scene)
    {
        scene_ = scene;
    }

    void Impl::SetRenderer(Base::RenderFacility::sptr renderer)
    {
        renderFacility_ = renderer;
    }
}
