/*
 * Copyright (C) 2018 Vladimir "allejo" Jimenez
 * All rights reserved.
 */

#include "bzfsAPI.h"
#include "plugin_utils.h"

class DemilitarizedZones : public bz_Plugin
{
    virtual const char* Name();
    virtual void Init(const char* config);
    virtual void Cleanup();
    virtual void Event(bz_EventData* eventData);
};

BZ_PLUGIN(DemilitarizedZones)

const char* DemilitarizedZones::Name()
{
    return "Demilitarized Zones";
}

void DemilitarizedZones::Init(const char* config)
{
    Register(bz_eShotFiredEvent);
}

void DemilitarizedZones::Cleanup()
{
    Flush();
}

void DemilitarizedZones::Event(bz_EventData* eventData)
{
    switch (eventData->eventType)
    {
        case bz_eShotFiredEvent:
        {
            // This event is called each time a shot is fired
            bz_ShotFiredEventData_V1 *data = (bz_ShotFiredEventData_V1*)eventData;

            // Data
            // ----
            // (int)          playerID  - ID of the player that fired the shot
            // (bool)         changed   - Whether or not the shot has been modified. Shot type will not change unless this is set to 1 (true).
            // (float[3])     pos       - Where the shot was fired
            // (bz_ApiString) type      - The shot type. This is the abbreviation, such as "PZ" or "SW"
            // (double)       eventTime - This value is the local server time of the event.
        }
        break;

        default:
            break;
    }
}