/*******************************************************************************
 * Copyright (c) 2014, Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @header      CFPP-Boolean.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFBooleanRef wrapper
 */

#ifndef CFPP_BOOLEAN_H
#define CFPP_BOOLEAN_H

#include <CF++/CFPP-PropertyListType.h>

namespace CF
{
    class Boolean: public PropertyListType< Boolean >
    {
        public:
            
            Boolean( const Boolean & value );
            Boolean( CFTypeRef cfObject );
            Boolean( CFBooleanRef cfObject );
            Boolean( CFTypeRef cfObject, bool defaultValueIfNULL );
            Boolean( CFBooleanRef cfObject, bool defaultValueIfNULL );
            Boolean( bool value = false );
            
            #ifdef CFPP_HAS_CPP11
            Boolean( Boolean && value );
            #endif
            
            virtual ~Boolean( void );
            
            Boolean & operator = ( Boolean value );
            Boolean & operator = ( CFTypeRef value );
            Boolean & operator = ( CFBooleanRef value );
            Boolean & operator = ( bool value );
            
            bool operator == ( const Boolean & value ) const;
            bool operator == ( bool value ) const;
            bool operator == ( CFTypeRef value ) const;
            bool operator == ( CFBooleanRef value ) const;
            
            bool operator != ( const Boolean & value ) const;
            bool operator != ( bool value ) const;
            bool operator != ( CFTypeRef value ) const;
            bool operator != ( CFBooleanRef value ) const;
            
            operator bool () const;
            
            virtual CFTypeID  GetTypeID( void ) const;
            virtual CFTypeRef GetCFObject( void ) const;
            
            bool GetValue( void ) const;
            void SetValue( bool value );
            
            friend void swap( Boolean & v1, Boolean & v2 );
            
        private:
            
            CFBooleanRef _cfObject;
    };
}

#endif /* CFPP_BOOLEAN_H */
