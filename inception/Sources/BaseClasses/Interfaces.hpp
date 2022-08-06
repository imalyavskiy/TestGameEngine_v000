#ifndef __INTERFACES_H__
#define __INTERFACES_H__

///
struct Updatable
{
	virtual void Update(float dt) = 0;
};

///
struct Drawable
{
	virtual void Draw() = 0;
};

#endif // __INTERFACES_H__
