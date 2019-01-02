#ifndef VIGRA_ARGB_HXX
#define VIGRA_ARGB_HXX

#include <cmath>    
#include <cstdlib>  
#include "config.hxx"
#include "numerictraits.hxx"
#include "accessor.hxx"
#include "tinyvector.hxx"
#include "static_assert.hxx"

namespace vigra {
#ifndef DOXYGEN

template <uint8_t A, uint8_t R, uint8_t G, uint8_t B>
struct BDA_color
: staticAssert::AssertBool<(A < 4 && R < 4 && G < 4 && B < 4 &&
                           ((1 << A)+ (1 << R) + (1 << G) + (1 << B) == 15))>
{};
#endif 

template <class VALUETYPE,uint8_t ALPHA_IDX = 0,uint8_t RED_IDX = 1, uint8_t GREEN_IDX = 2, uint8_t BLUE_IDX = 3> //template for 4 components
class BDAColor: public TinyVector<VALUETYPE, 4>//vector type STL
{
public: 
    typedef TinyVector<VALUETYPE, 4> Base;
    typedef typename Base::value_type value_type;
	BDAColor(): Base( 0,0,0,0 ){}; //constructor 1
 	 BDAColor(value_type a, value_type r, value_type g,value_type b): Base(a, r, g, b) //constructor for argb
	{
	     VIGRA_STATIC_ASSERT((BDA_color<ALPHA_IDX,RED_IDX, GREEN_IDX, BLUE_IDX>));
	}
	BDAColor(value_type r, value_type g,value_type b): Base(0, r, g, b) //constructor for rgb
	{
	     VIGRA_STATIC_ASSERT((BDA_color<ALPHA_IDX,RED_IDX, GREEN_IDX, BLUE_IDX>));
	}
	   enum {  //enum for index
      IDX0 = (ALPHA_IDX == 0) ? 0 : (RED_IDX == 0) ? 1 : (GREEN_IDX==0) ? 2 : 3,
      IDX1 = (ALPHA_IDX == 0) ? 0 : (RED_IDX == 0) ? 1 : (GREEN_IDX==0) ? 2 : 3,
      IDX2 = (ALPHA_IDX == 0) ? 0 : (RED_IDX == 0) ? 1 : (GREEN_IDX==0) ? 2 : 3,
      IDX3 = (ALPHA_IDX == 0) ? 0 : (RED_IDX == 0) ? 1 : (GREEN_IDX==0) ? 2 : 3
    
    }; //color index positions
     enum
    {
      AlphaIdx= ALPHA_IDX,
      RedIdx = RED_IDX,
      GreenIdx = GREEN_IDX,
      BlueIdx = BLUE_IDX
    };
   
	BDAColor operator[](int n )   //without reference
	{
	
		return (*this)[n]; 
	}

	const BDAColor& operator[]( int n ) const  //with reference
	{
		
		return (*this)[n];
	}

	


};
}
#endif // VIGRA_ARGB_HXX

