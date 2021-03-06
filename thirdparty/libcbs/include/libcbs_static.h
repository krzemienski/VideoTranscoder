// must be included only once in a project
#pragma once

#include "libcbs.h"

#ifndef ANDROID
#pragma optimize( "", off )

// User-defined operator new.
void *operator new( size_t size ) 
{
   return cbs_malloc( size );
}

void *operator new[]( size_t size ) 
{
   return cbs_malloc( size );
}

// User-defined operator delete.
void operator delete( void *ptr ) 
{
   cbs_free( ptr );
}

void operator delete[]( void *ptr ) 
{
   cbs_free( ptr );
}

#pragma optimize( "", on )
#endif // ANDROID    �h���ߘ���M[n��M� z��g�3��~>/�����m�@��+u1<4��g(߷ۚ���T@/o�NÊ�B���"CKd���n���|�W!���DJ����o�}.FkF��$pa�mg�cC�x�~�"8�+�����v|E��Xy��qw��!Y��SB��=���X��*
5�-So6������0�2