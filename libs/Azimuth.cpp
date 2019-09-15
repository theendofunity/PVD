#include "Azimuth.h"

#include <cmath>


double Azimuth::m_lsb = 1;

void Azimuth::setAzimuthCodeLSB(double lsb) noexcept
{
    m_lsb = lsb;
}

//------------------------------------------------------------------------------

Azimuth Azimuth::fromRadians(double radians, double lsb) noexcept
{
    Azimuth azimuth(0);
    azimuth.azimuth = static_cast<uint32_t>(radians / lsb);
    return azimuth;
}

//------------------------------------------------------------------------------

Azimuth Azimuth::fromDegrees(double degrees) noexcept
{
    Azimuth azimuth(0);
    azimuth.azimuth = static_cast<uint32_t>(degrees * (1 << 16) / 360);
    return azimuth;
}

//------------------------------------------------------------------------------

Azimuth Azimuth::fromAzimuthCode(uint32_t code) noexcept
{
    return Azimuth(code);
}

//------------------------------------------------------------------------------

Azimuth::Azimuth(uint32_t azimuthCode) noexcept
{
    azimuth = azimuthCode;
}

//------------------------------------------------------------------------------

double Azimuth::toRadians() const noexcept
{
    return static_cast<double>(azimuth) * m_lsb;
}

//------------------------------------------------------------------------------

double Azimuth::toDegrees() const noexcept
{
    return static_cast<double>(azimuth) * 360 / (1 << 16);
}

//------------------------------------------------------------------------------

uint32_t Azimuth::toAzimuthCode() const noexcept
{
    return azimuth;
}

//------------------------------------------------------------------------------

bool Azimuth::inRange(const Azimuth& left, const Azimuth& right) const noexcept
{
    uint32_t offset = left.azimuth;
    int rValue = static_cast<int>(right.azimuth - offset);
    if (rValue < 0)
        rValue += (1 << 16);

    int cValue = static_cast<int>(azimuth - offset);
    if (cValue < 0)
        cValue += (1 << 16);
    return (0 <= cValue and cValue <= rValue);
}


Azimuth& Azimuth::operator +=(const Azimuth& other) noexcept
{
    azimuth += other.azimuth;
    if (azimuth >= (1 << 16))
        azimuth -= (1 << 16);
    return *this;
}

Azimuth &Azimuth::operator -=(const Azimuth &other) noexcept
{
    long diff = azimuth - other.azimuth;
    azimuth = static_cast<uint32_t>(std::abs(diff));

    if (azimuth >= (1 << 16))
        azimuth -= (1 << 16);
    return *this;
}

//------------------------------------------------------------------------------

bool operator < (const Azimuth& left, const Azimuth& right) noexcept
{
    return left.azimuth < right.azimuth;
}

//-----------------------------------------------------------------------------

bool operator <= (const Azimuth& left, const Azimuth& right) noexcept
{
    return left.azimuth <= right.azimuth;
}

//-----------------------------------------------------------------------------

Azimuth operator + (const Azimuth& right, const Azimuth& left) noexcept
{
    int value = static_cast<int>(right.azimuth + left.azimuth);
    if (value >= (1 << 16))
        value -= (1 << 16);
    return Azimuth::fromAzimuthCode(static_cast<uint32_t>(value));
}

//------------------------------------------------------------------------------

Azimuth operator -(const Azimuth& right, const Azimuth& left) noexcept
{
    int value = static_cast<int>(right.azimuth - left.azimuth);
    if (value < 0)
        value += (1 << 16);
    return Azimuth::fromAzimuthCode(static_cast<uint32_t>(value));
}


long double operator"" _deg(long double value) noexcept
{
    return value * M_PI / 180;
}
