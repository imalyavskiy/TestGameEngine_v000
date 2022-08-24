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

    void Yaw(float value) override;

    void Pitch(float value) override;

    void Roll(float value) override;

    void Draw(const Math3D::Matrix4f& matViewProjection) override;

  protected:
    float forwardDelta_ = 0.f;
    float rightDelta_ = 0.f;
    float upDelta_ = 0.f;

    float yawDelta_ = 0.f;
    float pitchDelta_ = 0.f;
    float rollDelta_ = 0.f;
  };
}
#endif // __LEARNING_PAWN_HPP__