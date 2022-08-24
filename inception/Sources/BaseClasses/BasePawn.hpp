#ifndef __BASE_PAWN_HPP__
#define __BASE_PAWN_HPP__
namespace Base
{
  class Pawn : public SceneObject
  {
  public:
		/**
		 * @todo describe this
		 */
		using sptr = std::shared_ptr<Pawn>;

		/**
		 * @todo describe this
		 */
		explicit Pawn(const std::string name);

		/*
		 * @param value changes in [-1, 1] range. 1 - forward, -1 - backwards
		 */
		virtual void MoveForward(float value);

		/*
		 * @param value changes in [-1, 1] range. 1 - right, -1 - left
		 */
		virtual void MoveRight(float value);

		/*
		 * @param value changes in [-1, 1] range. 1 - up, -1 - down
		 */
		virtual void MoveUp(float value);

		/*
		 * @param value changes in [-1, 1] range. 1 - right, -1 - left
		 */
		virtual void Yaw(float value);

		/*
		 * @param value changes in [-1, 1] range. 1 - up, -1 - down
		 */
		virtual void Pitch(float value);

		/*
		 * @param value changes in [-1, 1] range. 1 - right, -1 - left
		 */
		virtual void Roll(float value);

	};
}
#endif //__BASE_PAWN_HPP__