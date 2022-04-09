#ifndef __UTILS_H_B6938B89_E0D0_4D84_9A50_0415D061589E__
#define __UTILS_H_B6938B89_E0D0_4D84_9A50_0415D061589E__
namespace math
{
    template<typename vector_t>
    vector_t normalized(const vector_t& v) {
       return vector_t(v).normalize();
    }

    template<typename matrix_t>
    matrix_t transposed(const matrix_t& m)
    {
        return matrix_t(m).transpose();
    }

    template<typename matrix_t>
    matrix_t inverted(const matrix_t& m)
    {
        return matrix_t(m).invert();
    }

#define det2x2(_00, _01, _10, _11)\
(((_00)*(_11))\
-((_10)*(_01)))

#define det3x3(_00, _01, _02, _10, _11, _12, _20, _21, _22)\
(((_00)*(_11)*(_22))\
+((_10)*(_21)*(_02))\
+((_20)*(_01)*(_12))\
-((_20)*(_11)*(_02))\
-((_21)*(_12)*(_00))\
-((_22)*(_10)*(_01)))

#define det4x4(_00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33)\
(-((_00)*(_11)*(_22)*(_33))\
+((_10)*(_21)*(_32)*(_03))\
-((_20)*(_31)*(_02)*(_13))\
+((_30)*(_01)*(_12)*(_23))\
-((_30)*(_21)*(_12)*(_03))\
+((_31)*(_22)*(_13)*(_00))\
-((_32)*(_23)*(_10)*(_01))\
+((_33)*(_20)*(_11)*(_02)))


}

#endif // __UTILS_H_B6938B89_E0D0_4D84_9A50_0415D061589E__
