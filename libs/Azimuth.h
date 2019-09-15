#ifndef AZIMUTH_H
#define	AZIMUTH_H


#include <cstdint>


class Azimuth
{
    friend bool operator <= (const Azimuth& left, const Azimuth& right) noexcept;
    friend bool operator < (const Azimuth& left, const Azimuth& right) noexcept;
    friend Azimuth operator + (const Azimuth& left, const Azimuth& right) noexcept;
    friend Azimuth operator - (const Azimuth& left, const Azimuth& right) noexcept;
    
public:
    static void setAzimuthCodeLSB(double lsb) noexcept;
    
    static Azimuth fromDegrees(double degrees) noexcept;
    static Azimuth fromRadians(double radians, double lsb = m_lsb) noexcept;
    static Azimuth fromAzimuthCode(uint32_t code) noexcept;
    
    Azimuth() = default;
    explicit Azimuth(uint32_t azimuthCode) noexcept;
    
    double toDegrees() const noexcept;
    double toRadians() const noexcept;
    uint32_t toAzimuthCode() const noexcept;
    
    bool inRange(const Azimuth& left, const Azimuth& rigth) const noexcept;
    
    Azimuth& operator += (const Azimuth& other) noexcept;
    Azimuth& operator -= (const Azimuth& other) noexcept;
private:
    static double m_lsb;
    
    uint32_t azimuth = 0;
};

bool operator <= (const Azimuth& left, const Azimuth& right) noexcept;
bool operator < (const Azimuth& left, const Azimuth& right) noexcept;
Azimuth operator + (const Azimuth& right, const Azimuth& left) noexcept;
Azimuth operator - (const Azimuth& right, const Azimuth& left) noexcept;


/**
 * @brief Пользовательский литерал. Преобразует число из градусов в радианы
 * @param value - значение в градусах
 * @return значение в радианах
 */
long double operator"" _deg(long double value) noexcept;



#endif	/* AZIMUTH_H */

