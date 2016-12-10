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

/*! \file codecFactory.h
    \brief Declaration of the class used to retrieve the codec able to
        handle the requested transfer syntax.

*/

#if !defined(imebraCodecFactory__INCLUDED_)
#define imebraCodecFactory__INCLUDED_

#include <string>
#include <limits>
#include "dataSet.h"
#include "streamReader.h"
#include "streamWriter.h"
#include "definitions.h"

namespace imebra
{

///
/// \brief The CodecFactory class can load or save a DataSet or an Image object
///        using one of the codecs supplied by the Imebra library.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API CodecFactory
{
public:
    /// \brief Parses the content of the input stream and returns a DataSet
    ///        representing it.
    /// 
    /// If none of the codecs supplied by Imebra is able to decode the stream's
    /// content then it throws a CodecWrongFormatError exception.
    /// 
    /// \param reader            a StreamReader connected to the input stream
    /// \param maxSizeBufferLoad the maximum size of the tags that are loaded
    ///                          immediately. Tags larger than maxSizeBufferLoad
    ///                          are left on the input stream and loaded only when
    ///                          a ReadingDataHandler or a WritingDataHandler
    ///                          reference them.
    /// \return a DataSet object representing the input stream's content
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static DataSet* load(StreamReader& reader, size_t maxSizeBufferLoad = std::numeric_limits<size_t>::max());

    /// \brief Parses the content of the input file and returns a DataSet
    ///        representing it.
    ///
    /// If none of the codecs supplied by Imebra is able to decode the file's
    /// content then it throws a CodecWrongFormatError exception.
    ///
    /// \param fileName          the Unicode name of the input file to read
    /// \param maxSizeBufferLoad the maximum size of the tags that are loaded
    ///                          immediately. Tags larger than maxSizeBufferLoad
    ///                          are left on the input stream and loaded only when
    ///                          a ReadingDataHandler or a WritingDataHandler
    ///                          reference them.
    /// \return a DataSet object representing the input file's content
    ///
    ///////////////////////////////////////////////////////////////////////////////
#ifndef SWIG // Use Unicode strings only with SWIG
    static DataSet* load(const std::wstring& fileName, size_t maxSizeBufferLoad = std::numeric_limits<size_t>::max());
#endif

    /// \brief Parses the content of the input file and returns a DataSet
    ///        representing it.
    ///
    /// If none of the codecs supplied by Imebra is able to decode the file's
    /// content then it throws a CodecWrongFormatError exception.
    ///
    /// \param fileName          the Utf8 name of the input file to read
    /// \param maxSizeBufferLoad the maximum size of the tags that are loaded
    ///                          immediately. Tags larger than maxSizeBufferLoad
    ///                          are left on the input stream and loaded only when
    ///                          a ReadingDataHandler or a WritingDataHandler
    ///                          reference them.
    /// \return a DataSet object representing the input file's content
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static DataSet* load(const std::string& fileName, size_t maxSizeBufferLoad = std::numeric_limits<size_t>::max());

    static void saveImage(
            StreamWriter& destStream,
            const Image& sourceImage,
            const std::string& transferSyntax,
            imageQuality_t imageQuality_t,
            tagVR_t dataType,
            std::uint32_t allocatedBits,
            bool bSubSampledX,
            bool bSubSampledY,
            bool bInterleaved,
            bool b2Complement);

    /// \brief Saves the content of a DataSet object to an output stream using the
    ///        requested codec.
    ///
    /// \param dataSet           the DataSet object to save
    /// \param writer            a StreamWriter connected to the output stream
    /// \param codecType         the codec to use to save the DataSet
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static void save(const DataSet& dataSet, StreamWriter& writer, codecType_t codecType);

    /// \brief Saves the content of a DataSet object to an output file using the
    ///        requested codec.
    ///
    /// \param dataSet           the DataSet object to save
    /// \param fileName          the Unicode name of the output file to create
    /// \param codecType         the codec to use to save the DataSet
    ///
    ///////////////////////////////////////////////////////////////////////////////
#ifndef SWIG // Use UTF8 strings only with SWIG
    static void save(const DataSet& dataSet, const std::wstring& fileName, codecType_t codecType);
#endif

    /// \brief Saves the content of a DataSet object to an output file using the
    ///        requested codec.
    ///
    /// \param dataSet           the DataSet object to save
    /// \param fileName          the Utf8 name of the output file to create
    /// \param codecType         the codec to use to save the DataSet
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static void save(const DataSet& dataSet, const std::string& fileName, codecType_t codecType);


    /// \brief Set the maximum image's width & height accepted by Imebra.
    ///
    /// By default both the maximum width and height are set to 4096 pixels.
    ///
    /// \param maximumWidth      the maximum image's width accepted by Imebra
    /// \param maximumHeight     the maximum image's height accepted by Imebra
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static void setMaximumImageSize(const std::uint32_t maximumWidth, const std::uint32_t maximumHeight);

};

}
#endif // !defined(imebraCodecFactory__INCLUDED_)
