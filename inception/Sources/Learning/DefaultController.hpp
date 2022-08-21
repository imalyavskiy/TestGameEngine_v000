#ifndef __LEARNING_DEFAULT_CONTROLLER_HPP__
#define __LEARNING_DEFAULT_CONTROLLER_HPP__
namespace Learning
{
  struct Button
  {
    Button(GLUT::KEY id) : id(id) {}
    GLUT::KEY id;
    bool   pressed = false;
  };

  struct PawnAction
  {
    virtual  void Update() = 0;

    std::shared_ptr<Base::Pawn> pawn;
  };

  class AxisAction : public PawnAction
  {
  public:
    AxisAction(std::shared_ptr<Button> more, std::shared_ptr<Button> less, std::function<void(float)> cb)
      : cb_(cb)
      , more_(more)
      , less_(less)
    {
    }

  protected:
    void Apply(float value) const
    {
      cb_(value);
    }

    void Update() final override
    {
      assert(more_ && less_);
      if ((!more_->pressed && less_->pressed) || (more_->pressed && !less_->pressed))
        Apply(more_->pressed ? most : least);
      else
        Apply(neutral);
    }

    std::shared_ptr<Button> more_;
    std::shared_ptr<Button> less_;

    std::function<void(float)> cb_;

    float most = 1.0f;
    float neutral = 0.0f;
    float least = -1.f;
  };

  struct EventAction : PawnAction
  {
    std::shared_ptr<Button> button;
  };

  class DefaultController : public Base::Controller
  {
  public:
    using sptr = std::shared_ptr<DefaultController>;

    /**
    *
    */
    DefaultController(const Base::Settings& settings, const std::string& name = "DefaultController");

    /*
     * @param key Certain key ID.
     * @param state True is key is pressed, false if released.
     */
    bool OnKey(GLUT::KEY key, bool state) override;

    /*
     * @brief sends states to the subordinate pawn
     */
    void Update(float dt) override;

  protected:
    std::map<GLUT::KEY, std::shared_ptr<Button>> registeredKeys_;
    std::list<std::shared_ptr<PawnAction>> actionList_;
  };
}
#endif // __LEARNING_DEFAULT_CONTROLLER_HPP__