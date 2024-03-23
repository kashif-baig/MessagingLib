#ifndef DATA_READER_H
#define DATA_READER_H

#include "DataReaderBuffer.h"

class DataReader
{
public:

    // Instance is considered to be connected until either all items
    // have been received and processed, or cancellation has been requested.
    virtual bool connected();

    // Returns true if an item is available.
    bool itemAvailable() const;

    // Move to the next directory item.
    void moveNext();

protected:
    DataReader(DataReaderBuffer *buffer);

    DataReaderBuffer *getBuffer() const;
private:

    DataReaderBuffer *_buffer;

};


#endif
