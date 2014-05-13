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
 
/* $Id$ */

/*!
 * @file        main.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ test executable
 */

#include <CF++.h>

extern const char * externalKey;
extern const char * externalByteBuffer;
extern size_t       externalByteBufferLength;
extern const char * externalURL;

const char * externalKey                = "key-2";
const char * externalByteBuffer         = NULL;
size_t       externalByteBufferLength   = 0;
const char * externalURL                = "http://www.example.org/";

int main( void )
{
    std::cout << "********** CF::Boolean **********" << std::endl;
    std::cout << std::endl;
    
    {
        CF::Boolean boolean;
        
        boolean = true;
        
        std::cout << boolean << std::endl;
        
        boolean = false;
        
        std::cout << boolean << std::endl;
        
        if( boolean == true )
        {
            std::cout << "CF::Boolean is true" << std::endl;
        }
        else
        {
            std::cout << "CF::Boolean is not true" << std::endl;
        }
    }
    
    std::cout << std::endl;
    std::cout << "********** CF::String **********" << std::endl;
    std::cout << std::endl;
    
    {
        CF::String string;
        
        string = "hello, world";
        
        std::cout << string << std::endl;
        
        string = "hello, universe";
        
        std::cout << string << std::endl;
        
        if( string == "hello, world" )
        {
            std::cout << "CF::String is \"hello, world\"" << std::endl;
        }
        else
        {
            std::cout << "CF::String is not \"hello, world\"" << std::endl;
        }
        
        string += "!!!";
        
        std::cout << string << std::endl;
        std::cout << "Second character is: '" << string[  1 ] << "'" << std::endl;
        std::cout << "Last character is:   '" << string[ -1 ] << "'" << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "********** CF::Number **********" << std::endl;
    std::cout << std::endl;
    
    {
        CF::Number number;
        
        number = 42;
        
        std::cout << number << std::endl;
        
        number += 2;
        
        std::cout << number << std::endl;
        
        number /= 2;
        
        std::cout << number << std::endl;
        
        if( number == 22 )
        {
            std::cout << "CF::Number is 22" << std::endl;
        }
        else
        {
            std::cout << "CF::Number is not 22" << std::endl;
        }
        
        if( number > 42 )
        {
            std::cout << "CF::Number greater than 42" << std::endl;
        }
        else
        {
            std::cout << "CF::Number is lesser than 42" << std::endl;
        }
        
        number++;
        
        number += 2;
        
        std::cout << number      << std::endl;
        std::cout << number + 10 << std::endl;
        std::cout << number      << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "********** CF::Date **********" << std::endl;
    std::cout << std::endl;
    
    {
        CF::Date date1;
        CF::Date date2;
        
        date1 = date2;
        
        std::cout << date1 << std::endl;
        std::cout << date2 << std::endl;
        
        if( date1 == date2 )
        {
            std::cout << "CF::Date are equal" << std::endl;
        }
        else
        {
            std::cout << "CF::Date are not equal" << std::endl;
        }
        
        sleep( 1 );
        
        date2 = CF::Date::currentDate();
        
        std::cout << date2 << std::endl;
        
        date1 += date2;
        
        std::cout << date1 << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "********** CF::Array **********" << std::endl;
    std::cout << std::endl;
    
    {
        CF::Array  array1;
        CF::Array  array2;
        
        std::cout << array1 << std::endl;
        
        array1 << "hello, world"
               << 42;
        
        std::cout << array1 << std::endl;
        
        array2  = array1;
        array1 += array2;
        array1 << array2;
        
        std::cout << array1 << std::endl;
        
        std::cout << "CF::Array[ 0 ] is:" << std::endl;
        CFShow( array1[ 0 ] );
        
        std::cout << "CF::Array[ 1 ] is:" << std::endl;
        CFShow( array1[ 1 ] );
        
        std::cout << "CF::Array[ 10 ] is:" << std::endl;
        CFShow( array1[ 10 ] );
    }
    
    std::cout << std::endl;
    std::cout << "********** CF::Dictionary **********" << std::endl;
    std::cout << std::endl;
    
    {
        CF::Dictionary dictionary;
        
        std::cout << dictionary << std::endl;
        
        dictionary << CF::Pair( "hello, world", 42 );
        
        std::cout << dictionary << std::endl;
        
        dictionary << CF::Pair( "string", "hello, world" )
                   << CF::Pair( "number", 42 );
        
        CFShow( dictionary );
        
        std::cout << "CF::Dictionary[ 'hello, world' ] is:" << std::endl;
        CFShow( dictionary[ "hello, world" ] );
        
        std::cout << "CF::Dictionary[ 'number' ] is:" << std::endl;
        CFShow( dictionary[ "number" ] );
        
        std::cout << "CF::Dictionary[ 'xxx' ] is:" << std::endl;
        CFShow( dictionary[ "xxx" ] );
    }
    
    std::cout << std::endl;
    std::cout << "********** CF::URL **********" << std::endl;
    std::cout << std::endl;
    
    {
        CF::URL url;
        
        url = std::string( "http://www.xs-labs.com/en/projects/index.php" );
        
        std::cout << url                                                     << std::endl;
        std::cout << "Scheme:         " << url[ CF::URL::PartScheme ]        << std::endl;
        std::cout << "Hostname:       " << url[ CF::URL::PartHostName ]      << std::endl;
        std::cout << "Path extension: " << url[ CF::URL::PartPathExtension ] << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "********** CF::Data **********" << std::endl;
    std::cout << std::endl;
    
    {
        CF::Data data;
        
        data = std::string( "hello, world" );
        
        std::cout << data                                   << std::endl;
        std::cout << ( std::string )data                    << std::endl;
        std::cout << "First byte is: " << ( char )data[ 0 ] << std::endl;
    }
    
    {
        CF::Error error( "com.xs-labs", 42 );
        
        std::cout << error << std::endl;
    }
    
    {
        CF::UUID uuid;
        
        std::cout << uuid << std::endl;
        std::cout << ( std::string )uuid << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "********** CF::PropertyListType **********" << std::endl;
    std::cout << std::endl;
    
    {
        CF::Dictionary dict;
        
        dict << CF::Pair( "foo", "hello, world" )
             << CF::Pair( "bar", "hello, universe" )
             << CF::Pair( "foobar", CF::Number( 42 ) );
        
        dict.ToPropertyList( "CF++.plist", CF::PropertyListFormatBinary );
        
        std::cout << CF::Dictionary::FromPropertyList( "/Users/macmade/Desktop/Manifest.plist" ) << std::endl;
    }
    
    return EXIT_SUCCESS;
}
