#include <pch.hpp>
#include <Math3D/Math3d.hpp>
#include <Utilities/Utilities.hpp>
#include "BaseClasses.hpp"
namespace Base
{
  Controller::Controller(const Base::Settings& settings, const std::string& name)
    : Object(name)
    , settings_(settings)
  {
    
  }

  void Controller::SetPawn(Base::Pawn::sptr pawn)
  {
    controlledPawn_ = pawn;
  }
}
