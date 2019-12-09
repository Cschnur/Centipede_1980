#include "MovementCollection.h"
#include "OffsetArray.h"

const OffsetArray MovementCollection::OffsetsStraightRight = OffsetArray(1, 0, 0.0f, 2);
const OffsetArray MovementCollection::OffsetsTurnUpEndRight = OffsetArray(0, -1, 11.25f, 0);
const OffsetArray MovementCollection::OffsetsTurnDownEndRight = OffsetArray(0, 1, -11.25f, 0);
const OffsetArray MovementCollection::OffsetsStraightLeft = OffsetArray(-1, 0, 0.0f, -1);
const OffsetArray MovementCollection::OffsetsTurnUpEndLeft = OffsetArray(0, -1, -11.25f, 0);
const OffsetArray MovementCollection::OffsetsTurnDownEndLeft = OffsetArray(0, 1, 11.25f, 0);
