#ifndef DATA_READER_BUFFER_H
#define DATA_READER_BUFFER_H

#include <stdint.h>

class DataReaderBuffer
{
public:
    DataReaderBuffer();
    
    // Resets the buffer to its initial state, and updates the SyncId.
    virtual void clear();

    // The SyncId is required to prevent buffer filling with out of date data.
    uint8_t getSyncId() const;

    // FIFO eviction of item from the buffer to make space for another item.
    virtual void evictItem() = 0;

    // Returns true if a response item (a data chunk) has been received from the server.
    bool itemAvailable() const;

    // Call this method if the response from the server ends unexpectedly.
    void cancel();

    // Returns true if the response from the server ended unexpectedly.
    bool cancelled () const;
    
    // Call this method when all items for a response have been received from the server.
    void setComplete();

    // Returns true if there are no more items to receive from the server.
    bool completed() const;

    // Adds item (FIFO) to the buffer (if space is available).
    // Item is parsed into an instance where necessary.
    virtual void addItem (const char *value) = 0;

protected:

    void setAvailable(bool val);
    
private:

    bool _cancelled;
    bool _available;
    bool _completed;
    uint8_t _syncId;
};

#endif
