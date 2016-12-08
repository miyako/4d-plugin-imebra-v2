/*

Imebra 4.0.7.1 changeset 108a911a22e1

Imebra: a C++ Dicom library

Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016
by Paolo Brandoli/Binarno s.p.

All rights reserved.

This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License version 2 as published by
 the Free Software Foundation.

This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

-------------------

If you want to use Imebra commercially then you have to buy the commercial
 license available at http://imebra.com

After you buy the commercial license then you can use Imebra according
 to the terms described in the Imebra Commercial License.
A copy of the Imebra Commercial License is available at http://imebra.com.

Imebra is available at http://imebra.com

The author can be contacted by email at info@binarno.com or by mail at
 the following address:
 Binarno s.p., Paolo Brandoli
 Rakuseva 14
 1000 Ljubljana
 Slovenia



*/

/*! \file streamReader.h
    \brief Declaration of the the class used to read the streams.

*/

#if !defined(imebraStreamReader__INCLUDED_)
#define imebraStreamReader__INCLUDED_

#ifndef SWIG

#include <memory>
#include "definitions.h"

namespace imebra
{
namespace implementation
{
class streamReader;
}

}

#endif


namespace imebra
{

class BaseStreamInput;

class CodecFactory;

///
/// \brief A StreamReader is used to read data from a BaseStreamInput
///        object.
///
/// A StreamReader can be mapped to only a portion of the BaseStreamInput it
/// manages: for instance this is used by the Imebra classes to read Jpeg
/// streams embedded into a DICOM stream.
///
/// \warning  The StreamReader object IS NOT THREAD-SAFE: however, several
///           StreamReader objects from different threads can be connected to
///           the same BaseStreamInput object.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API StreamReader
{
    StreamReader(const StreamReader&) = delete;
    StreamReader& operator=(const StreamReader&) = delete;

#ifndef SWIG
    friend class CodecFactory;
    friend class Tag;

private:
    StreamReader(std::shared_ptr<implementation::streamReader> pReader);
#endif

public:
    /// \brief Constructor.
    ///
    /// \param stream the BaseStreamInput object from which the StreamReader will
    ///               read
    ///
    ///////////////////////////////////////////////////////////////////////////////
    StreamReader(const BaseStreamInput& stream);

    /// \brief Constructor.
    ///
    /// This version of the constructor limits the portion of the stream that
    /// the StreamReader will see.
    ///
    /// \param stream        the BaseStreamInput object from which the StreamReader
    ///                      will read
    /// \param virtualStart  the first visible byte of the managed stream
    /// \param virtualLength the number of visible bytes in the managed stream
    ///
    ///////////////////////////////////////////////////////////////////////////////
    StreamReader(const BaseStreamInput& stream, size_t virtualStart, size_t virtualLength);

    virtual ~StreamReader();

#ifndef SWIG
protected:
    std::shared_ptr<implementation::streamReader> m_pReader;
#endif
};

}

#endif // !defined(imebraStreamReader__INCLUDED_)
