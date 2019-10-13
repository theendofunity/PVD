#ifndef GUARD_33feb136_faa7_43ef_b0b7_f66dfaa0b571
#define GUARD_33feb136_faa7_43ef_b0b7_f66dfaa0b571


#include <GenericPrototypes/GenericPrototypes.h>



namespace pvd
{


struct CoordinatePoint : public Codogramm
{
    enum { MessageTypeCode = 4 };
    
    CoordinatePoint()
    {
        appendToOrder( { &azimuth } );
        appendToOrder( { &range } );
        appendToOrder( { &bortNumber } );
        appendToOrder( { &height } );
    }
    
    CoordinatePoint(const CoordinatePoint& orig)
        : CoordinatePoint()
    {
        *this = orig;
    }
    
    Field<double> azimuth;
    Field<double> range;
    Field<uint32_t> bortNumber;
    Field<uint32_t> height;
};


} // namespace pvd


#endif // GUARD_33feb136_faa7_43ef_b0b7_f66dfaa0b571
