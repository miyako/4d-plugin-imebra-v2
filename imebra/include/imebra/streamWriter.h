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

/*! \file streamWriter.h
    \brief Declaration of the the class used to write the streams.

*/

#if !defined(imebraStreamWriter__INCLUDED_)
#define imebraStreamWriter__INCLUDED_

#ifndef SWIG

#include <memory>
#include "definitions.h"

namespace imebra
{
namespace implementation
{
class streamWriter;
}
}
#endif

namespace imebra
{

class BaseStreamOutput;

class CodecFactory;

///
/// \brief A StreamWriter is used to write data into a BaseStreamOutput
///        object.
///
/// A StreamWriter can be mapped to only a portion of the BaseStreamOutput it
/// manages.
///
/// \warning: The StreamWriter object IS NOT THREAD-SAFE: however, several
///           StreamWriter objects from different threads can be connected to
///           the same BaseStreamOutput object.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API StreamWriter
{
    StreamWriter(const StreamWriter&) = delete;
    StreamWriter& operator=(const StreamWriter&) = delete;

#ifndef SWIG
    friend class CodecFactory;
    friend class Tag;

private:
    StreamWriter(std::shared_ptr<implementation::streamWriter> pWriter);
#endif

public:
    /// \brief Constructor.
    ///
    /// \param stream the BaseStreamOutput object on which the StreamWriter will
    ///               write
    ///
    ///////////////////////////////////////////////////////////////////////////////
    StreamWriter(const BaseStreamOutput& stream);

    /// \brief Constructor.
    ///
    /// This version of the constructor limits the portion of the stream that
    /// the StreamWriter will be able to use.
    ///
    /// \param stream        the BaseStreamOutput object on which the StreamWriter
    ///                      will write
    /// \param virtualStart  the first visible byte of the managed stream
    /// \param virtualLength the number of visible bytes in the managed stream
    ///
    ///////////////////////////////////////////////////////////////////////////////
    StreamWriter(const BaseStreamOutput& stream, size_t virtualStart, size_t virtualLength);

    virtual ~StreamWriter();

#ifndef SWIG
protected:
    std::shared_ptr<implementation::streamWriter> m_pWriter;
#endif
};

}

#endif // !defined(imebraStreamWriter__INCLUDED_)
