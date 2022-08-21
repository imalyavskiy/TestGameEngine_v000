#ifndef __LEARNING_PAWN_HPP__
#define __LEARNING_PAWN_HPP__
namespace Learning
{
  class Pawn : public Base::Pawn
  {
  public:
    Pawn(const std::string& name);

    void MoveForward(float value) override;

    void MoveUp(float value) override;

    void MoveRight(float value) override;

    void Update(float dt) override;

  protected:
    float forwardDelta = 0.f;
    float rightDelta = 0.f;
    float upDelta = 0.f;
  };
}
#endif // __LEARNING_PAWN_HPP__