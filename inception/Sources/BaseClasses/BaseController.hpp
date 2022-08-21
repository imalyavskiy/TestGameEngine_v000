#ifndef __BASE_CONTROLLER_HPP__
#define __BASE_CONTROLLER_HPP__
namespace Base
{
  class Controller : public Object
  {
  public:
    using sptr = std::shared_ptr<Controller>;

    /**
     *
     */
    Controller(const Base::Settings& settings, const std::string& name);

    /**
     *
     */
    virtual void SetPawn(Base::Pawn::sptr pawn);

    /*
     * @param key Certain key ID.
     * @param state True is key is pressed, false if released.
     */
    virtual bool OnKey(GLUT::KEY key, bool state) = 0;

    /*
     * @brief sends states to the subordinate pawn
     */
    virtual void Update(float dt) = 0;

  protected:
    /**
     *
     */
    Base::Pawn::sptr controlledPawn_;

    /**
     *
     */
    Settings settings_;
  };
}
#endif // __BASE_CONTROLLER_HPP__