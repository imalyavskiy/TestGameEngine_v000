#ifndef __UTILS_H_B6938B89_E0D0_4D84_9A50_0415D061589E__
#define __UTILS_H_B6938B89_E0D0_4D84_9A50_0415D061589E__
namespace math
{
    template<typename vector_t>
    vector_t normalized(const vector_t& v) {
       return vector_t(v).normalize();
    }
}

#endif // __UTILS_H_B6938B89_E0D0_4D84_9A50_0415D061589E__
